/*
** EPITECH PROJECT, 2022
** inie
** File description:
** end
*/

#include "Game.hpp"
#include "Player/Player.hpp"

int Indie::Game::check_who_win(Player *firstPlayer, Player *secondPlayer,
                               Player *firstBot, Player *secondBot) {
  int count = 0;

  if (firstPlayer->life <= 0)
    count = count + 1;
  if (secondPlayer->life <= 0)
    count = count + 1;
  if (firstBot->life <= 0)
    count = count + 1;
  if (secondBot->life <= 0)
    count = count + 1;
  if (count == 4)
    return (9);
  else if (count == 3) {
    if (firstPlayer->life > 0)
      return (5);
    else if (secondPlayer->life > 0)
      return (6);
    else if (firstBot->life > 0)
      return (7);
    else if (secondBot->life > 0)
      return (8);
  }
  return (0);
}

void Indie::Game::draw_final(int count) {
  DrawRectangle(660, 305, 640, 480, BLACK);
  if (count == 9)
    DrawText("DRAW", 870, 335, 75, WHITE);
  else {
    if (count == 5)
      DrawText("Player 1 win", 760, 335, 75, WHITE);
    else if (count == 6)
      DrawText("Player 2 win", 760, 335, 75, WHITE);
    else if (count == 7)
      DrawText("Bot 1 win", 820, 335, 75, WHITE);
    else
      DrawText("Bot 2 win", 820, 335, 75, WHITE);
  }
  if (CheckCollisionPointRec(GetMousePosition(), {900, 600, 150, 50})) {
    DrawText("QUIT", 900, 600, 60, VIOLET);
    if (IsMouseButtonPressed(0))
      gameStatus = Indie::Game::EXIT;
  } else
    DrawText("QUIT", 900, 600, 60, WHITE);
  if (CheckCollisionPointRec(GetMousePosition(), {750, 500, 470, 50})) {
    DrawText("BACK TO MENU", 750, 500, 60, VIOLET);
    if (IsMouseButtonPressed(0)) {
      gameStatus = Indie::Game::MENU;
      EndDrawing();
      BeginDrawing();
      ClearBackground(BLACK);
      DrawText("Back to menu...", 575, 480, 100, WHITE);
      EndDrawing();
    }
  } else
    DrawText("BACK TO MENU", 750, 500, 60, WHITE);
}
