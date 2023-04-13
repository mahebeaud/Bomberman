/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** map
*/

#include "../Menu.hpp"
#include "raylib.h"

void Indie::Menu::change_map(void) {
  DrawRectangle(190, 525, 50, 50, VIOLET);
  DrawRectangle(840, 525, 50, 50, VIOLET);
  if (CheckCollisionPointRec(GetMousePosition(), {190, 525, 50, 50})) {
    DrawText("<", 200, 517, 70, WHITE);
    if (IsMouseButtonPressed(0) && current_map != 1)
      current_map = current_map - 1;
  } else {
    DrawText("<", 200, 517, 70, BLACK);
  }
  if (CheckCollisionPointRec(GetMousePosition(), {840, 525, 50, 50})) {
    DrawText(">", 855, 517, 70, WHITE);
    if (IsMouseButtonPressed(0) && current_map < 4)
      current_map = current_map + 1;
  } else {
    DrawText(">", 855, 517, 70, BLACK);
  }
}

void Indie::Menu::show_map(std::vector<Texture2D> allMenuTexture) {
  DrawText("Chose your map", 340, 150, 50, WHITE);
  if (current_map == 1)
    DrawTexture(allMenuTexture.at(Indie::Menu::PREVIEW_ONE), 290, 300, WHITE);
  else if (current_map == 2)
    DrawTexture(allMenuTexture.at(Indie::Menu::PREVIEW_TWO), 290, 300, WHITE);
  else if (current_map == 3)
    DrawTexture(allMenuTexture.at(Indie::Menu::PREVIEW_THREE), 290, 300, WHITE);
  else
    DrawTexture(allMenuTexture.at(Indie::Menu::PREVIEW_FOUR), 290, 300, WHITE);
  std::string tmp = "Map ";
  tmp = tmp + std::to_string(current_map);
  DrawText(tmp.c_str(), 360, 850, 50, WHITE);
  DrawRectangle(580, 850, 150, 50, VIOLET);
  if (CheckCollisionPointRec(GetMousePosition(), {580, 850, 150, 50})) {
    DrawText("PLAY", 600, 858, 40, WHITE);
    if (IsMouseButtonPressed(0) && otherUsername.length() >= 3)
      underStep = Indie::Menu::SOLO_GAME;
  } else {
    DrawText("PLAY", 600, 858, 40, BLACK);
  }
}
