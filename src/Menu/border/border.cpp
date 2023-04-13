/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** Border
*/

#include "Menu.hpp"

void Indie::Menu::draw_border(void) {
  DrawRectangle(0, 0, 2100, 50, VIOLET);
  if (windowSize == Indie::Menu::FENETRE)
    DrawRectangle(0, 970, 2100, 50, VIOLET);
  else
    DrawRectangle(0, GetMonitorHeight(GetCurrentMonitor()) - 50, 2100, 50,
                  VIOLET);
}

void Indie::Menu::check_back(void) {
  if (windowSize == Indie::Menu::FENETRE) {
    DrawText("<---", 35, 974, 40, BLACK);
    if (CheckCollisionPointRec(GetMousePosition(), {35, 974, 75, 16})) {
      if (IsMouseButtonPressed(0)) {
        if (underStep == Indie::Menu::CHOSE_MODE ||
            underStep == Indie::Menu::SETTINGS)
          underStep = Indie::Menu::MAIN_MENU;
        if (underStep == Indie::Menu::CHOSE_MAP)
          underStep = Indie::Menu::CHOSE_MODE;
      }
    }
  } else {
    DrawText("<---", 35, 1034, 40, BLACK);
    if (CheckCollisionPointRec(GetMousePosition(), {35, 1034, 75, 45})) {
      if (IsMouseButtonPressed(0)) {
        if (underStep == Indie::Menu::CHOSE_MODE ||
            underStep == Indie::Menu::SETTINGS)
          underStep = Indie::Menu::MAIN_MENU;
        if (underStep == Indie::Menu::CHOSE_MAP)
          underStep = Indie::Menu::CHOSE_MODE;
      }
    }
  }
}

void Indie::Menu::check_quit(std::vector<Texture2D> allMenuTexture) {
  if (windowSize == Indie::Menu::FENETRE) {
    DrawTexture(allMenuTexture.at(Indie::Menu::QUIT), 1855, 975, WHITE);
    if (CheckCollisionPointRec(GetMousePosition(), {1850, 975, 145, 24})) {
      if (IsMouseButtonPressed(0))
        underStep = Indie::Menu::END;
    }
  } else {
    DrawTexture(allMenuTexture.at(Indie::Menu::QUIT), 1855, 1032, WHITE);
    if (CheckCollisionPointRec(GetMousePosition(), {1850, 1032, 145, 47})) {
      if (IsMouseButtonPressed(0))
        underStep = Indie::Menu::END;
    }
  }
}
