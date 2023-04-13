/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** time
*/

#include "Game.hpp"

void Indie::Game::draw_time(void) {
  int tmp = 120 - (GetTime() - startTime) + lostTime;
  std::string gruid = "";

  DrawRectangle(10, 450, 360, 100, BLACK);
  if (tmp <= 0)
    DrawText("DEATH TIME", 40, 480, 45, RED);
  else if (tmp == 120) {
    DrawText("02:00", 120, 470, 60, WHITE);
  } else if (tmp < 120 && tmp >= 60) {
    gruid = "01:";
    if (tmp < 70)
      gruid = gruid + "0";
    gruid = gruid + std::to_string(tmp - 60);
    DrawText(gruid.c_str(), 120, 470, 60, WHITE);
  } else {
    gruid = "00:";
    if (tmp < 10)
      gruid = gruid + "0";
    gruid = gruid + std::to_string(tmp);
    DrawText(gruid.c_str(), 120, 470, 60, WHITE);
  }
}

void Indie::Game::spawn_end(void) {
  int tmp = 120 - (GetTime() - startTime) + lostTime;
  int once = 0;

  if (tmp <= 40 && tmp >= 39 && once == 0) {
    allSounds.at(Indie::Game::WALL_SND)->play_sound();
    myMap.at(0) = "|||||||||||||||";
    myMap.at(1) = "|||||||||||||||";
    myMap.at(myMap.size() - 2) = "|||||||||||||||";
    myMap.at(myMap.size() - 1) = "|||||||||||||||";
    once = 1;
  }
  once = 0;
  if (tmp <= 30 && tmp >= 29 && once == 0) {
    allSounds.at(Indie::Game::WALL_SND)->play_sound();
    for (int i = 0; i < myMap.size(); i = i + 1) {
      myMap.at(i)[0] = '|';
      myMap.at(i)[1] = '|';
      myMap.at(i)[myMap.at(0).length() - 2] = '|';
      myMap.at(i)[myMap.at(0).length() - 1] = '|';
    }
    once = 1;
  }
  once = 0;
  if (tmp <= 20 && tmp >= 19) {
    allSounds.at(Indie::Game::WALL_SND)->play_sound();
    myMap.at(2) = "|||||||||||||||";
    myMap.at(myMap.size() - 3) = "|||||||||||||||";
    for (int i = 0; i < myMap.size(); i = i + 1) {
      myMap.at(i)[2] = '|';
      myMap.at(i)[myMap.at(0).length() - 3] = '|';
    }
    once = 1;
  }
  once = 0;
  if (tmp <= 10 && tmp >= 9) {
    allSounds.at(Indie::Game::WALL_SND)->play_sound();
    for (int i = 0; i < myMap.size(); i = i + 1) {
      myMap.at(i)[3] = '|';
      myMap.at(i)[myMap.at(0).length() - 4] = '|';
    }
    once = 1;
  }
  once = 0;
  if (tmp <= 1 && tmp >= 0) {
    allSounds.at(Indie::Game::WALL_SND)->play_sound();
    myMap.at(3) = "|||||||||||||||";
    myMap.at(4) = "|||||||||||||||";
    myMap.at(myMap.size() - 4) = "|||||||||||||||";
    myMap.at(myMap.size() - 5) = "|||||||||||||||";
    once = 1;
  }
}

void Indie::Game::end_map(Player *myPlayer) {
  spawn_end();
  for (int i = 0; i < collisions.size(); i = i + 1) {
    for (int ii = 0; ii < collisions.at(i).size(); ii = ii + 1) {
      if (CheckCollisionRecs(myPlayer->playerPos, collisions.at(i).at(ii))) {
        allSounds.at(Indie::Game::DEAD_SND)->play_sound();
        myPlayer->life = 0;
      }
    }
  }
}
