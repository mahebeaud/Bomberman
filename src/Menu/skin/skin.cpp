/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** skin
*/

#include "../Menu.hpp"

void Indie::Menu::chose_first_skin(std::vector<Texture2D> allMenuTexture) {
  DrawTexture(allMenuTexture.at(6 + firstSkin), 1100, 300, WHITE);

  DrawRectangle(990, 525, 50, 50, VIOLET);
  if (CheckCollisionPointRec(GetMousePosition(), {990, 525, 50, 50})) {
    DrawText("<", 1000, 517, 70, WHITE);
    if (IsMouseButtonPressed(0) && firstSkin != Indie::RED_COLOR)
      firstSkin = firstSkin - 1;
  } else {
    DrawText("<", 1000, 517, 70, BLACK);
  }

  DrawRectangle(1510, 525, 50, 50, VIOLET);
  if (CheckCollisionPointRec(GetMousePosition(), {1510, 525, 50, 50})) {
    DrawText(">", 1525, 517, 70, WHITE);
    if (IsMouseButtonPressed(0) && firstSkin != Indie::WHITE_COLOR)
      firstSkin = firstSkin + 1;
  } else {
    DrawText(">", 1525, 517, 70, BLACK);
  }
  DrawRectangle(1205, 850, 150, 50, VIOLET);
  if (firstSkin == 0)
    DrawText("SKIN", 1225, 858, 40, RED);
  else if (firstSkin == 1)
    DrawText("SKIN", 1225, 858, 40, YELLOW);
  else if (firstSkin == 2)
    DrawText("SKIN", 1225, 858, 40, BLUE);
  else if (firstSkin == 3)
    DrawText("SKIN", 1225, 858, 40, WHITE);
}

void Indie::Menu::chose_second_skin(std::vector<Texture2D> allMenuTexture) {
  DrawTexture(allMenuTexture.at(6 + secondSkin), 1100, 300, WHITE);

  DrawRectangle(990, 525, 50, 50, VIOLET);
  if (CheckCollisionPointRec(GetMousePosition(), {990, 525, 50, 50})) {
    DrawText("<", 1000, 517, 70, WHITE);
    if (IsMouseButtonPressed(0) && secondSkin != Indie::RED_COLOR)
      secondSkin = secondSkin - 1;
  } else {
    DrawText("<", 1000, 517, 70, BLACK);
  }

  DrawRectangle(1510, 525, 50, 50, VIOLET);
  if (CheckCollisionPointRec(GetMousePosition(), {1510, 525, 50, 50})) {
    DrawText(">", 1525, 517, 70, WHITE);
    if (IsMouseButtonPressed(0) && secondSkin != Indie::WHITE_COLOR)
      secondSkin = secondSkin + 1;
  } else {
    DrawText(">", 1525, 517, 70, BLACK);
  }
  DrawRectangle(1205, 850, 150, 50, VIOLET);
  if (secondSkin == 0)
    DrawText("SKIN", 1225, 858, 40, RED);
  else if (secondSkin == 1)
    DrawText("SKIN", 1225, 858, 40, YELLOW);
  else if (secondSkin == 2)
    DrawText("SKIN", 1225, 858, 40, BLUE);
  else if (secondSkin == 3)
    DrawText("SKIN", 1225, 858, 40, WHITE);
}
