/*
** EPITECH PROJECT, 2022
** indie
** File description:
** ge char
*/

#include "GameEngine.hpp"

char GameEngine::get_key_pressed(void) {
  int key = GetCharPressed();

  if ((key > 47 && key < 58) || (key > 64 && key < 91) || key == 95 ||
      (key > 96 && key < 123))
    return (char(key));
  else if (GetKeyPressed() == 259) {
    return (127);
  }
  return (0);
}
