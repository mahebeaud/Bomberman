/*
** EPITECH PROJECT, 2022
** Idnie
** File description:
** wall collisoins
*/

#include "Game.hpp"

void Indie::Game::check_collisions_right(Vector2 middle_bomb, Player *myPlayer,
                                         int idx) {
  int h = 0;
  int i = 1;

  for (i = 1; i <= allBombRange.at(idx); i = i + 1) {
    DrawRectangle(middle_bomb.x + h + 20, middle_bomb.y, 80, 50, RED);
    if (CheckCollisionRecs(myPlayer->playerPos,
                           {middle_bomb.x + h + 20, middle_bomb.y, 80, 50})) {
      myPlayer->life = myPlayer->life - 1;
      if (myPlayer->life == 0)
        allSounds.at(Indie::Game::DEAD_SND)->play_sound();
    }
    if (check_all_bombs_collisions(
            {middle_bomb.x + h + 20 + 80, middle_bomb.y + 25}))
      i = allBombRange.at(idx) + 1;
    h = h + 80;
  }
}

void Indie::Game::check_collisions_left(Vector2 middle_bomb, Player *myPlayer,
                                        int idx) {
  int h = 0;
  int i = 1;

  for (i = 1; i <= allBombRange.at(idx); i = i + 1) {
    DrawRectangle(middle_bomb.x - h - 80 + 20, middle_bomb.y, 80, 50, RED);
    if (CheckCollisionRecs(myPlayer->playerPos, {middle_bomb.x - h - 80 + 20,
                                                 middle_bomb.y, 80, 50})) {
      myPlayer->life = myPlayer->life - 1;
      if (myPlayer->life == 0)
        allSounds.at(Indie::Game::DEAD_SND)->play_sound();
    }
    if (check_all_bombs_collisions(
            {middle_bomb.x - h - 80 + 20, middle_bomb.y + 25}))
      i = allBombRange.at(idx) + 1;
    h = h + 80;
  }
}

void Indie::Game::check_collisions_up(Vector2 middle_bomb, Player *myPlayer,
                                      int idx) {
  int h = 0;
  int i = 1;

  for (i = 1; i <= allBombRange.at(idx); i = i + 1) {
    DrawRectangle(middle_bomb.x, middle_bomb.y - h - 80 + 25, 40, 80, RED);
    if (CheckCollisionRecs(
            myPlayer->playerPos,
            {middle_bomb.x, middle_bomb.y - h - 80 + 25, 40, 80})) {
      myPlayer->life = myPlayer->life - 1;
      if (myPlayer->life == 0)
        allSounds.at(Indie::Game::DEAD_SND)->play_sound();
    }
    if (check_all_bombs_collisions(
            {middle_bomb.x + 20, middle_bomb.y - h - 80 + 25}))
      i = allBombRange.at(idx) + 1;
    h = h + 80;
  }
}

void Indie::Game::check_collisions_down(Vector2 middle_bomb, Player *myPlayer,
                                        int idx) {
  int h = 0;
  int i = 1;

  for (i = 1; i <= allBombRange.at(idx); i = i + 1) {
    DrawRectangle(middle_bomb.x, middle_bomb.y + h + 25, 40, 80, RED);
    if (CheckCollisionRecs(myPlayer->playerPos,
                           {middle_bomb.x, middle_bomb.y + h + 25, 40, 80})) {
      myPlayer->life = myPlayer->life - 1;
      if (myPlayer->life == 0)
        allSounds.at(Indie::Game::DEAD_SND)->play_sound();
    }
    if (check_all_bombs_collisions(
            {middle_bomb.x + 20, middle_bomb.y + h + 80 + 25}))
      i = allBombRange.at(idx) + 1;
    h = h + 80;
  }
}

void Indie::Game::check_collisions(Vector2 middle_bomb, Player *myPlayer,
                                   int idx) {
  check_collisions_right(middle_bomb, myPlayer, idx);
  check_collisions_left(middle_bomb, myPlayer, idx);
  check_collisions_up(middle_bomb, myPlayer, idx);
  check_collisions_down(middle_bomb, myPlayer, idx);
}

bool Indie::Game::check_all_bombs_collisions(Vector2 idx) {
  for (int i = 0; i < collisions.size(); i = i + 1) {
    for (int ii = 0; ii < collisions.at(i).size(); ii = ii + 1) {
      if (CheckCollisionPointRec(idx, collisions.at(i).at(ii))) {
        if (myMap.at(i)[ii] == 'o') {
          create_bonus(
              {collisions.at(i).at(ii).x + 20, collisions.at(i).at(ii).y + 20});
          myMap.at(i)[ii] = ' ';
          collisions.at(i).at(ii).x = 0;
          collisions.at(i).at(ii).y = 0;
          collisions.at(i).at(ii).width = 0;
          collisions.at(i).at(ii).height = 0;
        }
        return (true);
      }
    }
  }
  return (false);
}
