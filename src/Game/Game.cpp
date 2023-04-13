/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Gmae
*/

#include "Game.hpp"
#include "Indie.hpp"
#include "Player/Player.hpp"
#include "raylib.h"
#include <string>
#include <vector>

Indie::Game::Game(std::string path, float volume, int windowSize,
                  std::string usrn, std::string oUsrn, int firstSkinIndex,
                  int secondSkinIndex) noexcept {
  firstName = usrn;
  secondName = oUsrn;
  windowS = windowSize;
  myVolume = volume;
  gameStatus = Indie::Game::GAME;
  myPath = path;
  load_all_assets(firstSkinIndex, secondSkinIndex);
  float x = 380;
  float y = 25;
  for (int i = 0; i < myMap.size(); i = i + 1) {
    std::vector<Rectangle> tmp;
    x = 380;
    for (int ii = 0; ii < myMap.at(i).length(); ii = ii + 1) {
      if (myMap.at(i)[ii] == ' ')
        tmp.push_back({0, 0, 0, 0});
      else
        tmp.push_back({x, y, 80, 80});
      x = x + 80;
    }
    collisions.push_back(tmp);
    y = y + 80;
  }
  tmpTime = 0;
  lostTime = 0;
}

void Indie::Game::load_game(int statement) {
  allPlayers.push_back(new Indie::Player(firstName, {475, 85}, 1));
  allPlayers.push_back(new Indie::Player(secondName, {1437, 85}, 2));
  allPlayers.push_back(new Indie::Player("Bot 1", {465, 910}, 3));
  allPlayers.push_back(new Indie::Player("Bot 2", {1427, 910}, 4));
  BeginDrawing();
  ClearBackground(BLACK);
  DrawText("Game is loading...", 575, 480, 100, WHITE);
  EndDrawing();
  allSounds.push_back(new GameEngine::MakeSound("utils/song/bombSound.ogg"));
  allSounds.push_back(new GameEngine::MakeSound("utils/song/bonusSound.ogg"));
  allSounds.push_back(new GameEngine::MakeSound("utils/song/deathSound.ogg"));
  allSounds.push_back(
      new GameEngine::MakeSound("utils/song/depopWallSound.ogg"));
  allSounds.push_back(new GameEngine::MakeSound("utils/song/game_sound.ogg"));
  for (int i = 0; i < allSounds.size(); i = i + 1)
    allSounds.at(i)->setSound(myVolume);
  HideCursor();
  startTime = GetTime();
  allSounds.at(Indie::Game::GAME_SND)->play_sound();
  if (statement == Indie::LOADER) {
    load_saves();
    ShowCursor();
  }
}

void Indie::Game::game_loop(int statement) {
  load_game(statement);
  std::vector<Texture2D> allGameTexture;
  for (int i = 0; i < allGamePath.size(); i = i + 1) {
    allGameTexture.push_back(LoadTexture(allGamePath.at(i).c_str()));
  }
  while (gameStatus != Indie::Game::EXIT && gameStatus != Indie::Game::MENU) {
    BeginDrawing();
    ClearBackground(BLANK);
    if (gameStatus == Indie::Game::GAME) {
      draw_map(allGameTexture);
      for (int i = 0; i < 4; i = i + 1) {
        if (i == 0 || i == 1) {
          allPlayers.at(i)->move_player(collisions);
          allPlayers.at(i)->draw_player(allGameTexture);
          if (allPlayers.at(i)->manage_command() == 1 &&
              &allPlayers.at(i)->life > 0)
            create_bombs(allPlayers.at(i));
        } else if (i == 2) {
          if (allPlayers.at(i)->control_first_bot(collisions) == 1)
            create_bombs(allPlayers.at(i));
          allPlayers.at(i)->draw_player(allGameTexture);
        } else {
          if (allPlayers.at(i)->control_second_bot(collisions) == 1)
            create_bombs(allPlayers.at(i));
          allPlayers.at(i)->draw_player(allGameTexture);
        }
        manage_bombs(allGameTexture, allPlayers.at(i));
        manage_bonus(allGameTexture, allPlayers.at(i));
        end_map(allPlayers.at(i));
      }
      draw_time();
      check_pause();
      if (check_who_win(allPlayers.at(0), allPlayers.at(1), allPlayers.at(2),
                        allPlayers.at(3)) > 0) {
        gameStatus = Indie::Game::OVER;
        ShowCursor();
      }
    } else if (gameStatus == Indie::Game::PAUSE ||
               gameStatus == Indie::Game::SETTING) {
      draw_map(allGameTexture);
      for (int i = 0; i < 4; i = i + 1)
        allPlayers.at(i)->draw_player(allGameTexture);
      draw_bombs(allGameTexture);
      for (int i = 0; i < allBonus.size(); i = i + 1)
        draw_bonus(allGameTexture, i);
      manage_pause();
      check_play();
    } else if (gameStatus == Indie::Game::OVER) {
      draw_map(allGameTexture);
      for (int i = 0; i < 4; i = i + 1)
        allPlayers.at(i)->draw_player(allGameTexture);
      draw_bombs(allGameTexture);
      for (int i = 0; i < allBonus.size(); i = i + 1)
        draw_bonus(allGameTexture, i);
      draw_final(check_who_win(allPlayers.at(0), allPlayers.at(1),
                               allPlayers.at(2), allPlayers.at(3)));
    }
    EndDrawing();
    if (WindowShouldClose())
      gameStatus = Indie::Game::EXIT;
  }
  for (int i = 0; i < allGameTexture.size(); i = i + 1)
    UnloadTexture(allGameTexture.at(i));
  for (int i = 0; i < allSounds.size(); i = i + 1)
    UnloadSound(allSounds.at(i)->snd);
  for (int i = 0; i < allPlayers.size(); i = i + 1)
    delete allPlayers.at(i);
}
