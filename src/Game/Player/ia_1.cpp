/*
** EPITECH PROJECT, 2022
** indie
** File description:
** ia
*/

#include "Game.hpp"
#include "Player.hpp"

int Indie::Player::control_first_bot(
    std::vector<std::vector<Rectangle>> collisions) {
  Vector2 lastPos = {playerPos.x, playerPos.y};

  if (life <= 0)
    return (0);
  if (script_bot_1 == 0) {
    if (move == Indie::Player::RIGHT)
      playerPos.x = playerPos.x + speed;
    else if (move == Indie::Player::LEFT)
      playerPos.x = playerPos.x - speed;
    else if (move == Indie::Player::TOP)
      playerPos.y = playerPos.y - speed;
    if (!check_collision(collisions)) {
      playerPos.x = lastPos.x;
      playerPos.y = lastPos.y;
      if (move == Indie::Player::RIGHT) {
        move = Indie::Player::LEFT;
        if (myId == 3 && bombPosed < bombStock) {
          bombPosed = bombPosed + 1;
          return (1);
        }
      } else if (move == Indie::Player::LEFT)
        move = Indie::Player::TOP;
      else if (move == Indie::Player::TOP)
        move = Indie::Player::BOT;
    }
  } else if (script_bot_1 == 1) {
    if (move == Indie::Player::RIGHT)
      playerPos.x = playerPos.x + speed;
    else if (move == Indie::Player::LEFT)
      playerPos.x = playerPos.x - speed;
    else if (move == Indie::Player::TOP)
      playerPos.y = playerPos.y - speed;
    else if (move == Indie::Player::BOT)
      playerPos.y = playerPos.y + speed;
    if (!check_collision(collisions)) {
      playerPos.x = lastPos.x;
      playerPos.y = lastPos.y;
      if (move == Indie::Player::RIGHT) {
        move = Indie::Player::LEFT;
        if (myId == 3 && bombPosed < bombStock) {
          bombPosed = bombPosed + 1;
          return (1);
        }
      } else if (move == Indie::Player::TOP)
        move = Indie::Player::BOT;
      else if (move == Indie::Player::BOT)
        move = Indie::Player::RIGHT;
    }
  } else if (script_bot_1 == 2) {
    if (move == Indie::Player::RIGHT)
      playerPos.x = playerPos.x + speed;
    else if (move == Indie::Player::LEFT)
      playerPos.x = playerPos.x - speed;
    else if (move == Indie::Player::TOP)
      playerPos.y = playerPos.y - speed;
    else if (move == Indie::Player::BOT)
      playerPos.y = playerPos.y + speed;
    if (!check_collision(collisions)) {
      playerPos.x = lastPos.x;
      playerPos.y = lastPos.y;
      move = Indie::Player::RIGHT;
    }
    if (playerPos.x > 790 && playerPos.x < 800 && playerPos.y == 920) {
      move = Indie::Player::LEFT;
      if (myId == 3 && bombPosed < bombStock) {
        bombPosed = bombPosed + 1;
        return (1);
      }
    }
  } else if (script_bot_1 == 3) {
    if (bombPosed == 0 && move != Indie::Player::TOP)
      move = Indie::Player::RIGHT;
    if (move == Indie::Player::RIGHT)
      playerPos.x = playerPos.x + speed;
    else if (move == Indie::Player::LEFT)
      playerPos.x = playerPos.x - speed;
    else if (move == Indie::Player::TOP)
      playerPos.y = playerPos.y - speed;
    else if (move == Indie::Player::BOT)
      playerPos.y = playerPos.y + speed;
    if (playerPos.x > 781 && playerPos.x < 801 && playerPos.y == 920 &&
        move == Indie::Player::RIGHT && bombPosed == 0)
      move = Indie::Player::TOP;
    if (!check_collision(collisions)) {
      playerPos.x = lastPos.x;
      playerPos.y = lastPos.y;
      if (move == Indie::Player::TOP) {
        move = Indie::Player::BOT;
        if (myId == 3 && bombPosed < bombStock) {
          bombPosed = bombPosed + 1;
          return (1);
        }
      } else if (move == Indie::Player::BOT)
        move = Indie::Player::RIGHT;
    }
  } else if (script_bot_1 == 4) {
    if (bombPosed == 0 && move != Indie::Player::TOP && playerPos.y == 920)
      move = Indie::Player::LEFT;
    if (move == Indie::Player::RIGHT)
      playerPos.x = playerPos.x + speed;
    else if (move == Indie::Player::LEFT)
      playerPos.x = playerPos.x - speed;
    else if (move == Indie::Player::TOP)
      playerPos.y = playerPos.y - speed;
    else if (move == Indie::Player::BOT)
      playerPos.y = playerPos.y + speed;
    if (playerPos.x > 781 && playerPos.x < 795 && playerPos.y > 910 &&
        playerPos.y < 930 && move == Indie::Player::LEFT && bombPosed == 0)
      move = Indie::Player::TOP;
    if (!check_collision(collisions)) {
      playerPos.x = lastPos.x;
      playerPos.y = lastPos.y;
      if (move == Indie::Player::RIGHT) {
        move = Indie::Player::LEFT;
        if (myId == 3 && bombPosed < bombStock && playerPos.y < 910) {
          bombPosed = bombPosed + 1;
          return (1);
        }
      } else if (move == Indie::Player::TOP)
        move = Indie::Player::RIGHT;
      else if (move == Indie::Player::LEFT)
        move = Indie::Player::TOP;
    }
  } else if (script_bot_1 == 5) {
    if (bombPosed == 0 && move == Indie::Player::LEFT)
      move = Indie::Player::RIGHT;
    if (move == Indie::Player::RIGHT)
      playerPos.x = playerPos.x + speed;
    else if (move == Indie::Player::LEFT)
      playerPos.x = playerPos.x - speed;
    else if (move == Indie::Player::TOP)
      playerPos.y = playerPos.y - speed;
    else if (move == Indie::Player::BOT)
      playerPos.y = playerPos.y + speed;
    if (playerPos.x > 941 && playerPos.x < 965 && playerPos.y < 750 &&
        playerPos.y > 740 && bombPosed == 0)
      move = Indie::Player::TOP;
    if (!check_collision(collisions)) {
      playerPos.x = lastPos.x;
      playerPos.y = lastPos.y;
      if (move == Indie::Player::TOP) {
        move = Indie::Player::BOT;
        if (myId == 3 && bombPosed < bombStock && playerPos.y != 920) {
          bombPosed = bombPosed + 1;
          return (1);
        }
      } else if (move == Indie::Player::BOT)
        move = Indie::Player::LEFT;
    }
  } else if (script_bot_1 == 6) {
    if (move == Indie::Player::RIGHT)
      playerPos.x = playerPos.x + speed;
    else if (move == Indie::Player::LEFT)
      playerPos.x = playerPos.x - speed;
    else if (move == Indie::Player::TOP)
      playerPos.y = playerPos.y - speed;
    else if (move == Indie::Player::BOT)
      playerPos.y = playerPos.y + speed;
    if (playerPos.x > 941 && playerPos.x < 965 && playerPos.y < 760 &&
        playerPos.y > 740 && bombPosed == 0)
      move = Indie::Player::TOP;
    if (playerPos.x > 941 && playerPos.x < 965 && playerPos.y > 585 &&
        playerPos.y < 600 && bombPosed != 0)
      move = Indie::Player::LEFT;
    if (!check_collision(collisions)) {
      playerPos.x = lastPos.x;
      playerPos.y = lastPos.y;
      if (move == Indie::Player::TOP) {
        move = Indie::Player::BOT;
        if (myId == 3 && bombPosed < bombStock && playerPos.y != 920) {
          bombPosed = bombPosed + 1;
          return (1);
        }
      } else if (move == Indie::Player::BOT)
        move = Indie::Player::LEFT;
      else if (move == Indie::Player::RIGHT)
        move = Indie::Player::LEFT;
      else if (move == Indie::Player::LEFT)
        move = Indie::Player::RIGHT;
    }
  } else if (script_bot_1 == 7) {
    if (move == Indie::Player::RIGHT)
      playerPos.x = playerPos.x + speed;
    else if (move == Indie::Player::LEFT)
      playerPos.x = playerPos.x - speed;
    else if (move == Indie::Player::TOP)
      playerPos.y = playerPos.y - speed;
    else if (move == Indie::Player::BOT)
      playerPos.y = playerPos.y + speed;
    if (playerPos.x > 770 && playerPos.x < 790 && playerPos.y > 500 &&
        playerPos.y < 520) {
      if (myId == 3 && bombPosed < bombStock && playerPos.y != 920) {
        bombPosed = bombPosed + 1;
        return (1);
      }
    }
    if (!check_collision(collisions)) {
      playerPos.x = lastPos.x;
      playerPos.y = lastPos.y;
      if (move == Indie::Player::TOP)
        move = Indie::Player::RIGHT;
      else if (move == Indie::Player::RIGHT)
        move = Indie::Player::LEFT;
      else if (move == Indie::Player::LEFT)
        move = Indie::Player::TOP;
    }
  } else if (script_bot_1 >= 8) {
    if (move == Indie::Player::RIGHT)
      playerPos.x = playerPos.x + speed;
    else if (move == Indie::Player::LEFT)
      playerPos.x = playerPos.x - speed;
    else if (move == Indie::Player::TOP)
      playerPos.y = playerPos.y - speed;
    else if (move == Indie::Player::BOT)
      playerPos.y = playerPos.y + speed;
    if (myId == 3 && bombPosed < bombStock && playerPos.y != 920) {
      bombPosed = bombPosed + 1;
      return (1);
    }
    if (!check_collision(collisions)) {
      playerPos.x = lastPos.x;
      playerPos.y = lastPos.y;
      if (move == Indie::Player::TOP)
        move = Indie::Player::RIGHT;
      else if (move == Indie::Player::RIGHT)
        move = Indie::Player::BOT;
      else if (move == Indie::Player::BOT)
        move = Indie::Player::LEFT;
      else if (move == Indie::Player::LEFT)
        move = Indie::Player::TOP;
    }
  }
  if (playerPos.x != lastPos.x || playerPos.y != lastPos.y) {
    anim = anim + 1;
    if (anim > 5)
      anim = 0;
  }
  return (0);
}
