/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** setting
*/

#include "../Menu.hpp"
#include "raylib.h"

void Indie::Menu::settings(void) {
  DrawRectangle(700, 202, 490, 2, WHITE);
  DrawRectangle(700, 502, 490, 2, WHITE);
  DrawRectangle(700, 802, 490, 2, WHITE);
  draw_border();
  check_back();
  check_window_size();
  check_sound();
}
