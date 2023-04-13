/*
** EPITECH PROJECT, 2022
** indie
** File description:
** window
*/

#include "GameEngine.hpp"

void GameEngine::init_window(int x, int y, std::string windowName) {
  InitWindow(x, y, windowName.c_str());
}

void GameEngine::close_window(void) { CloseWindow(); }

void GameEngine::set_max_fps(int max) { SetTargetFPS(max); }
