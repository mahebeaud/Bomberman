/*
** EPITECH PROJECT, 2022
** Idnie
** File description:
** wall collisoins
*/

#include "Game.hpp"

void Indie::Game::check_collisions(Vector2 middle_bomb) {
  int h = 80;
  while (int i = 0;
         !check_all_bombs_collisions({middle_bomb.x + h, middle_bomb.y}) &&
         i <= allBombRange.at(i);
         i = i + 1) {
    h = h + 80;
    DrawRectangle();
  }

  if (!check_all_bombs_collisions({middle_bomb.x + 80, middle_bomb.y}))
    check_all_bombs_collisions({middle_bomb.x + 160, middle_bomb.y});
  if (!check_all_bombs_collisions({middle_bomb.x - 80, middle_bomb.y}))
    check_all_bombs_collisions({middle_bomb.x - 160, middle_bomb.y});
  if (!check_all_bombs_collisions({middle_bomb.x, middle_bomb.y + 80}))
    check_all_bombs_collisions({middle_bomb.x, middle_bomb.y + 160});
  if (!check_all_bombs_collisions({middle_bomb.x, middle_bomb.y - 80}))
    check_all_bombs_collisions({middle_bomb.x, middle_bomb.y - 160});
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
