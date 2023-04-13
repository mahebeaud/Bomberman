/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** chose map
*/

#include "../Menu.hpp"
#include "raylib.h"

void Indie::Menu::chose_map(std::vector<Texture2D> allMenuTexture) {
  draw_border();
  check_back();
  show_map(allMenuTexture);
  change_map();
  get_second_name();
  chose_second_skin(allMenuTexture);
}
