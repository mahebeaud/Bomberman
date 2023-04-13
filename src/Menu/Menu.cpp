/*
** EPITECH PROJECT, 2022
** INdie
** File description:
** Menu
*/

#include "Menu.hpp"
#include "GameEngine.hpp"
#include "Indie.hpp"
#include "raylib.h"
#include <iostream>

void Indie::Menu::help(void) {
  DrawRectangle(1800, 850, 100, 100, VIOLET);
  if (CheckCollisionPointRec(GetMousePosition(), {1800, 850, 100, 100})) {
    DrawText("?", 1813, 847, 120, WHITE);
    DrawRectangle(1500, 100, 375, 710, VIOLET);
    DrawText("KEYBINDS", 1530, 120, 60, BLACK);
    DrawText("First Player", 1560, 238, 40, BLACK);
    DrawText("Put Bomb : A", 1580, 300, 30, BLACK);
    DrawText("Movements", 1590, 345, 30, BLACK);
    DrawText("Z", 1660, 390, 30, BLACK);
    DrawText("QSD", 1640, 415, 30, BLACK);

    DrawText("Second Player", 1540, 508, 40, BLACK);
    DrawText("Put Bomb : right shift", 1525, 570, 30, BLACK);
    DrawText("Movements", 1590, 615, 30, BLACK);
    DrawText("UP", 1660, 660, 20, BLACK);
    DrawText("LEFT / DOWN / RIGTH", 1555, 687, 20, BLACK);
    DrawText("(ARROW KEYS)", 1600, 714, 20, BLACK);
  } else
    DrawText("?", 1813, 847, 120, BLACK);
}

Indie::Menu::Menu(void) noexcept {
  underStep = Indie::Menu::MAIN_MENU;
  windowSize = Indie::Menu::FENETRE;
  volume = 1;
  username = "";
  otherUsername = "";
  current_map = 1;
  allMenuPath.push_back("utils/assets/background_menu.png");
  allMenuPath.push_back("utils/assets/quit.png");
  allMenuPath.push_back("utils/map/map_1/preview_map.png");
  allMenuPath.push_back("utils/map/map_2/preview_map.png");
  allMenuPath.push_back("utils/map/map_3/preview_map.png");
  allMenuPath.push_back("utils/map/map_4/preview_map.png");
  allMenuPath.push_back("utils/Bomberman/Red_Preview.png");
  allMenuPath.push_back("utils/Bomberman/Yellow_Preview.png");
  allMenuPath.push_back("utils/Bomberman/Blue_Preview.png");
  allMenuPath.push_back("utils/Bomberman/White_Preview.png");
  firstSkin = 0;
  secondSkin = 0;
}

void Indie::Menu::main_menu(void) {
  check_play();
  check_settings();
  DrawText("The Bomberman Game", 380, 280, 100, WHITE);
  DrawText("Wejdene Fan Club <3", 830, 750, 20, WHITE);
  draw_border();
}

void Indie::Menu::menu_loop(void) {
  username = "";
  otherUsername = "";
  std::vector<Texture2D> allMenuTexture;
  for (int i = 0; i < allMenuPath.size(); i = i + 1)
    allMenuTexture.push_back(LoadTexture(allMenuPath.at(i)));

  GameEngine::MakeSound mySound =
      GameEngine::MakeSound("utils/song/back_sound.ogg");
  mySound.play_sound();
  while (underStep != Indie::Menu::END && underStep != Indie::Menu::SOLO_GAME &&
         underStep != Indie::Menu::LOAD_GAME) {
    BeginDrawing();
    ClearBackground(BLANK);
    DrawTexture(allMenuTexture.at(Indie::Menu::BACKGROUND), 0, 0, WHITE);
    if (underStep == Indie::Menu::MAIN_MENU) {
      main_menu();
      help();
    } else if (underStep == Indie::Menu::CHOSE_MODE) {
      chose_mode(allMenuTexture);
    } else if (underStep == Indie::Menu::SETTINGS) {
      settings();
    } else if (underStep == Indie::Menu::CHOSE_MAP) {
      chose_map(allMenuTexture);
    }
    check_quit(allMenuTexture);
    EndDrawing();
    mySound.setSound(volume);
    if (WindowShouldClose())
      underStep = Indie::Menu::END;
  }
  for (int i = 0; i < allMenuTexture.size(); i = i + 1)
    UnloadTexture(allMenuTexture.at(i));
  mySound.unloadSound();
}
