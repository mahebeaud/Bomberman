/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** map
*/

#include "Game.hpp"

void Indie::Game::draw_map(std::vector<Texture2D> allGameTexture) {
  float x = 380;
  float y = 25;

  DrawTexture(allGameTexture.at(Indie::Game::BACKGROUND), 0, 0, WHITE);
  for (int i = 0; i < myMap.size(); i = i + 1) {
    x = 380;
    for (int ii = 0; ii < myMap.at(i).length(); ii = ii + 1) {
      std::string current_path = myPath;
      if (myMap.at(i)[ii] == 'a')
        DrawTexture(allGameTexture.at(Indie::Game::LEFT_CORNER), x, y, WHITE);
      else if (myMap.at(i)[ii] == 'h')
        DrawTexture(allGameTexture.at(Indie::Game::UP_WALL), x, y, WHITE);
      else if (myMap.at(i)[ii] == 'e')
        DrawTexture(allGameTexture.at(Indie::Game::RIGHT_CORNER), x, y, WHITE);
      else if (myMap.at(i)[ii] == 'o')
        DrawTexture(allGameTexture.at(Indie::Game::BRAKE_WALL), x, y, WHITE);
      else if (myMap.at(i)[ii] == '|') {
        if (collisions.at(i).at(ii).x == 0) {
          collisions.at(i).at(ii).x = x;
          collisions.at(i).at(ii).y = y;
          collisions.at(i).at(ii).width = 80;
          collisions.at(i).at(ii).height = 80;
        }
        DrawTexture(allGameTexture.at(Indie::Game::WALL), x, y, WHITE);
      } else if (myMap.at(i)[ii] == 'b')
        DrawTexture(allGameTexture.at(Indie::Game::DOWN_WALL), x, y, WHITE);
      else if (myMap.at(i)[ii] == '#')
        DrawTexture(allGameTexture.at(Indie::Game::LEFT_WALL), x, y, WHITE);
      else if (myMap.at(i)[ii] == 'X')
        DrawTexture(allGameTexture.at(Indie::Game::RIGHT_WALL), x, y, WHITE);
      else
        DrawTexture(allGameTexture.at(Indie::Game::GROUND), x, y, WHITE);
      x = x + 80;
    }
    y = y + 80;
  }
}
