/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Step
*/

#include "../Menu.hpp"
#include "raylib.h"

void Indie::Menu::check_play(void) {
  if (CheckCollisionPointRec(GetMousePosition(), {850, 470, 160, 50})) {
    if (IsMouseButtonPressed(0))
      underStep = Indie::Menu::CHOSE_MODE;
    DrawText("PLAY", 850, 470, 60, VIOLET);
  } else {
    DrawText("PLAY", 850, 470, 60, WHITE);
  }
}

void Indie::Menu::check_settings(void) {
  if (CheckCollisionPointRec(GetMousePosition(), {770, 600, 320, 50})) {
    if (IsMouseButtonPressed(0))
      underStep = Indie::Menu::SETTINGS;
    DrawText("SETTINGS", 770, 600, 60, VIOLET);
  } else {
    DrawText("SETTINGS", 770, 600, 60, WHITE);
  }
}
