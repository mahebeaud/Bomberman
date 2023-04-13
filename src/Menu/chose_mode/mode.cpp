/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** mode
*/

#include "../Menu.hpp"
#include "raylib.h"

void Indie::Menu::solo_or_multi(void) {
  DrawText("Chose your mode :", 50, 380, 50, WHITE);
  if (CheckCollisionPointRec(GetMousePosition(), {50, 480, 265, 45})) {
    DrawText("- NEW GAME", 50, 480, 40, VIOLET);
    if (IsMouseButtonPressed(0) && username.length() >= 3)
      underStep = Indie::Menu::CHOSE_MAP;
  } else {
    DrawText("- NEW GAME", 50, 480, 40, WHITE);
  }
  if (CheckCollisionPointRec(GetMousePosition(), {50, 580, 280, 45})) {
    DrawText("- LOAD GAME", 50, 580, 40, VIOLET);
    if (IsMouseButtonPressed(0))
      underStep = Indie::Menu::LOAD_GAME;
  } else {
    DrawText("- LOAD GAME", 50, 580, 40, WHITE);
  }
}
