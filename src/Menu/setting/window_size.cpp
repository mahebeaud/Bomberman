/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Windo sinze
*/

#include "../Menu.hpp"
#include "raylib.h"

void Indie::Menu::draw_arrow(void) {
  DrawRectangle(500, 352, 50, 50, VIOLET);
  if (CheckCollisionPointRec(GetMousePosition(), {500, 352, 50, 50}))
    DrawText("<", 514, 352, 60, WHITE);
  else
    DrawText("<", 514, 352, 60, BLACK);
  DrawRectangle(1340, 352, 50, 50, VIOLET);
  if (CheckCollisionPointRec(GetMousePosition(), {1340, 352, 50, 50}))
    DrawText(">", 1354, 352, 60, WHITE);
  else
    DrawText(">", 1354, 352, 60, BLACK);
}

void Indie::Menu::fenetre(void) {
  DrawText("FENETRE", 800, 350, 60, WHITE);
  if ((CheckCollisionPointRec(GetMousePosition(), {1340, 352, 50, 50}) &&
       IsMouseButtonPressed(0)) ||
      (CheckCollisionPointRec(GetMousePosition(), {500, 352, 50, 50})) &&
          IsMouseButtonPressed(0)) {
    windowSize = Indie::Menu::FULL_SCREEN;
    ToggleFullscreen();
  }
}

void Indie::Menu::full_screen(void) {
  DrawText("FULL SCREEN", 740, 350, 60, WHITE);
  if ((CheckCollisionPointRec(GetMousePosition(), {1340, 352, 50, 50}) &&
       IsMouseButtonPressed(0)) ||
      (CheckCollisionPointRec(GetMousePosition(), {500, 352, 50, 50})) &&
          IsMouseButtonPressed(0)) {
    windowSize = Indie::Menu::FENETRE;
    SetWindowSize(1900, 1000);
    ToggleFullscreen();
  }
}

void Indie::Menu::check_window_size(void) {
  draw_arrow();
  if (windowSize == Indie::Menu::FENETRE) {
    fenetre();
  } else if (windowSize == Indie::Menu::FULL_SCREEN) {
    full_screen();
  }
}
