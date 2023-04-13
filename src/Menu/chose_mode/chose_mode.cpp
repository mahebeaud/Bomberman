/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** chose moe
*/

#include "../Menu.hpp"
#include "raylib.h"

void Indie::Menu::chose_mode(std::vector<Texture2D> allMenuTexture) {
  DrawRectangle(100, 302, 400, 2, WHITE);
  draw_border();
  check_back();
  get_name();
  solo_or_multi();
  chose_first_skin(allMenuTexture);
}
