/*
** EPITECH PROJECT, 2022
** Inie
** File description:
** getanme
*/

#include "../Menu.hpp"
#include "GameEngine.hpp"
#include "raylib.h"

void Indie::Menu::get_name(void) {
  std::string name = "First username : ";
  char key = GameEngine::get_key_pressed();

  if (key == 127 && username.length() > 0) {
    std::string tmp = "";
    int len = username.length() - 1;
    for (int i = 0; i < len; i = i + 1)
      tmp.push_back(username.at(i));
    username = tmp;
  }
  if (key != 0 && key != 127 && username.length() <= 10)
    username = username + key;
  if (username.length() < 3)
    DrawText("Enter at least 3 caracters", 50, 680, 30, RED);
  name = name + username;
  DrawText(name.c_str(), 50, 140, 100, WHITE);
}

void Indie::Menu::get_second_name(void) {
  std::string tmp = "Second username : ";
  char key = GameEngine::get_key_pressed();

  if (key == 127 && otherUsername.length() > 0) {
    std::string tmpp = "";
    int len = otherUsername.length() - 1;
    for (int i = 0; i < len; i = i + 1)
      tmpp.push_back(otherUsername.at(i));
    otherUsername = tmpp;
  }
  if (key != 0 && key != 127 && otherUsername.length() <= 10)
    otherUsername = otherUsername + key;
  if (otherUsername.length() < 3)
    DrawText("Enter at least 3 caracters", 1000, 230, 30, RED);
  tmp = tmp + otherUsername;
  DrawText(tmp.c_str(), 1000, 150, 50, WHITE);
}
