/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** sound
*/

#include "../Menu.hpp"
#include "raylib.h"

void Indie::Menu::draw_sym(void) {
  DrawRectangle(500, 602, 50, 50, VIOLET);
  DrawRectangle(1340, 602, 50, 50, VIOLET);
  if (CheckCollisionPointRec(GetMousePosition(), {500, 602, 50, 50}))
    DrawText("-", 512, 602, 60, WHITE);
  else
    DrawText("-", 512, 602, 60, BLACK);
  if (CheckCollisionPointRec(GetMousePosition(), {1340, 602, 50, 50}))
    DrawText("+", 1351, 602, 60, WHITE);
  else
    DrawText("+", 1351, 602, 60, BLACK);
}

void Indie::Menu::edit_sound(void) {
  if (CheckCollisionPointRec(GetMousePosition(), {500, 602, 50, 50}) &&
      IsMouseButtonPressed(0) && volume > 0)
    volume = volume - 1;
  if (CheckCollisionPointRec(GetMousePosition(), {1340, 602, 50, 50}) &&
      IsMouseButtonPressed(0) && volume <= 9)
    volume = volume + 1;
}

void Indie::Menu::check_sound(void) {
  std::string theSound = "Sound : ";

  draw_sym();
  edit_sound();
  if (volume == 10) {
    theSound = theSound + "100%";
  } else {
    char tmp = volume + '0';
    theSound = theSound + tmp + '0' + '%';
  }
  DrawText(theSound.c_str(), 770, 600, 60, WHITE);
}
