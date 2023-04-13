/*
** EPITECH PROJECT, 2022
** indie
** File description:
** player
*/

#include "Player.hpp"
#include "Game.hpp"

Indie::Player::Player(std::string firstName, Vector2 pos, int id) noexcept {
  anim = 0;
  script_bot_1 = 0;
  script_bot_2 = 0;
  myId = id;
  myName = firstName;
  playerPos.x = pos.x;
  playerPos.y = pos.y;
  if (myId == 1 || myId == 2)
    playerPos.y = playerPos.y + 28;
  playerPos.width = 50;
  playerPos.height = 73;
  if (myId == 3 || myId == 4) {
    playerPos.width = 65;
    playerPos.height = 65;
  }
  life = 1;
  speed = 2;
  bombStock = 1;
  bombPosed = 0;
  fire = 1;
  move = Indie::Player::BOT;
  if (id == 4)
    move = Indie::Player::TOP;
  else if (id == 3)
    move = Indie::Player::RIGHT;
}

int Indie::Player::move_player(std::vector<std::vector<Rectangle>> collisions) {
  Vector2 lastPos = {playerPos.x, playerPos.y};

  if (life <= 0)
    return (0);
  if (myId == 1) {
    if (IsKeyDown(87)) {
      playerPos.y = playerPos.y - speed;
      move = Indie::Player::TOP;
    } else if (IsKeyDown(68)) {
      playerPos.x = playerPos.x + speed;
      move = Indie::Player::RIGHT;
    } else if (IsKeyDown(83)) {
      playerPos.y = playerPos.y + speed;
      move = Indie::Player::BOT;
    } else if (IsKeyDown(65)) {
      playerPos.x = playerPos.x - speed;
      move = Indie::Player::LEFT;
    }
  } else if (myId == 2) {
    if (IsKeyDown(265)) {
      playerPos.y = playerPos.y - speed;
      move = Indie::Player::TOP;
    } else if (IsKeyDown(262)) {
      playerPos.x = playerPos.x + speed;
      move = Indie::Player::RIGHT;
    } else if (IsKeyDown(264)) {
      playerPos.y = playerPos.y + speed;
      move = Indie::Player::BOT;
    } else if (IsKeyDown(263)) {
      playerPos.x = playerPos.x - speed;
      move = Indie::Player::LEFT;
    }
  }
  if (!check_collision(collisions)) {
    playerPos.x = lastPos.x;
    playerPos.y = lastPos.y;
  }
  if (playerPos.x != lastPos.x || playerPos.y != lastPos.y) {
    anim = anim + 1;
    if (anim > 5)
      anim = 0;
  }
  return (0);
}

void Indie::Player::draw_player_ath() {
  std::string tmp = "";
  int x = 0;
  int y = 0;

  if (myId == 2) {
    x = 1580;
    DrawRectangle(10 + x, 10 + y, 320, 400, BLACK);
  } else if (myId == 1) {
    DrawRectangle(10 + x, 10 + y, 360, 400, BLACK);
  } else if (myId == 3) {
    y = 580;
    DrawRectangle(10 + x, 10 + y, 360, 400, BLACK);
  } else if (myId == 4) {
    y = 580;
    x = 1580;
    DrawRectangle(10 + x, 10 + y, 320, 400, BLACK);
  }
  DrawText(myName.c_str(), 20 + x, 15 + y, 30, WHITE);
  if (life <= 0)
    tmp = "LIFE : 0";
  else
    tmp = "LIFE : " + std::to_string(life);
  DrawText(tmp.c_str(), 20 + x, 55 + y, 30, YELLOW);
  tmp = "BOMB : " + std::to_string(bombStock);
  DrawText(tmp.c_str(), 20 + x, 95 + y, 30, LIME);
  tmp = "SPEED : " + std::to_string(speed);
  DrawText(tmp.c_str(), 20 + x, 135 + y, 30, BLUE);
  tmp = "FIRE : " + std::to_string(fire);
  DrawText(tmp.c_str(), 20 + x, 175 + y, 30, RED);
}

void Indie::Player::animate_player(std::vector<Texture2D> allGameTexture) {
  int idx = 0;

  if (move == Indie::Player::BOT)
    idx = 6;
  else if (move == Indie::Player::RIGHT)
    idx = 12;
  else if (move == Indie::Player::LEFT)
    idx = 18;
  idx = idx + anim;
  if (myId == 1)
    idx = idx + 24;
  else if (myId == 2)
    idx = idx + 48;
  if (myId == 1 || myId == 2)
    DrawTexture(allGameTexture.at(Indie::Game::CREEP_BACK_0 + idx), playerPos.x,
                playerPos.y - 28, WHITE);
  else
    DrawTexture(allGameTexture.at(Indie::Game::CREEP_BACK_0 + idx), playerPos.x,
                playerPos.y, WHITE);
}

void Indie::Player::draw_player(std::vector<Texture2D> allGameTexture) {
  if (life <= 0) {
    DrawTexture(allGameTexture.at(Indie::Game::TOMBSTONE), playerPos.x + 10,
                playerPos.y + 5, WHITE);
  } else {
    animate_player(allGameTexture);
  }
  draw_player_ath();
}

bool Indie::Player::check_collision(
    std::vector<std::vector<Rectangle>> collisions) {
  for (int i = 0; i < collisions.size(); i = i + 1) {
    for (int ii = 0; ii < collisions.at(i).size(); ii = ii + 1) {
      if (CheckCollisionRecs(playerPos, collisions.at(i).at(ii)))
        return (false);
    }
  }
  return (true);
}

int Indie::Player::manage_command(void) {
  if (life <= 0)
    return (0);
  if (myId == 1) {
    if (IsKeyPressed(81) && bombPosed < bombStock) {
      bombPosed = bombPosed + 1;
      return (1);
    }
  } else {
    if (IsKeyPressed(344) && bombPosed < bombStock) {
      bombPosed = bombPosed + 1;
      return (1);
    }
  }
  return (0);
}
