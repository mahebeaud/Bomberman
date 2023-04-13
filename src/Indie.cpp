/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Start Indie
*/

#include "Indie.hpp"
#include "../../include/Macro.hpp"
#include "Game/Game.hpp"
#include "GameEngine.hpp"
#include "Menu/Menu.hpp"
#include "raylib.h"
#include <iostream>

void deleteAll(Indie::Game myGame) {
  for (int i = 0; i < myGame.allSounds.size(); i = i + 1)
    delete (myGame.allSounds.at(i));
}

void unloadAll(void) {
  GameEngine::close_audio();
  GameEngine::close_window();
}

void loadAll(void) {
  GameEngine::init_window(1920, 1080, "Bomberman");
  GameEngine::init_audio();
  GameEngine::set_max_fps(60);
  BeginDrawing();
  ClearBackground(BLANK);
  DrawText("Game is loading...", 575, 480, 100, WHITE);
  EndDrawing();
}

int start_indie(void) {
  Indie::Menu myMenu = Indie::Menu();
  int step = Indie::MENU;
  loadAll();
  while (!GameEngine::check_window_close() && step != Indie::EXIT) {
    if (step == Indie::MENU) {
      myMenu.menu_loop();
      if (myMenu.underStep == Indie::Menu::END)
        step = Indie::EXIT;
      if (myMenu.underStep == Indie::Menu::SOLO_GAME)
        step = Indie::SOLO;
      if (myMenu.underStep == Indie::Menu::LOAD_GAME)
        step = Indie::LOADER;
    }
    if (step == Indie::SOLO || step == Indie::LOADER) {
      std::string path = "utils/map/map_";
      char tmp = myMenu.current_map + '0';
      path = path + tmp + '/';
      Indie::Game myGame = Indie::Game(path, myMenu.volume, myMenu.windowSize,
                                       myMenu.username, myMenu.otherUsername,
                                       myMenu.firstSkin, myMenu.secondSkin);
      myGame.game_loop(step);
      if (myGame.gameStatus == Indie::Game::EXIT) {
        deleteAll(std::move(myGame));
        step = Indie::EXIT;
      } else if (myGame.gameStatus == Indie::Game::MENU) {
        step = Indie::MENU;
        myMenu.underStep = Indie::Menu::MAIN_MENU;
      }
    }
  }
  unloadAll();
  return (EXIT_OK);
}
