/*
** EPITECH PROJECT, 2022
** inddie
** File description:
** player
*/

#pragma once

#include "Indie.hpp"
#include <iostream>
#include <vector>

namespace Indie {
    class Player {
        public:
            enum movement {
                TOP = 0,
                RIGHT = 1,
                BOT = 2,
                LEFT = 3,
            };
            Player (std::string firstName, Vector2 pos, int id) noexcept;
            Player (Player const &other) noexcept = default;
            Player (Player &&other) noexcept = default;
            Player &operator=(Player const &other) noexcept = default;
            Player &operator=(Player &&other) noexcept = default;
            ~Player() noexcept = default;

            int move_player(std::vector<std::vector<Rectangle>> collisions);
            void draw_player(std::vector<Texture2D> allGameTexture);
            void animate_player(std::vector<Texture2D> allGameTexture);
            bool check_collision(std::vector<std::vector<Rectangle>> collisions);
            int manage_command(void);
            void draw_player_ath(void);
            int control_second_bot(std::vector<std::vector<Rectangle>> collisions);
            int control_first_bot(std::vector<std::vector<Rectangle>> collisions);

            int myId;
            std::string myName;
            Rectangle playerPos;
            int anim;
            int move;
            int life;
            float speed;
            int bombStock;
            int bombPosed;
            int fire;
            int script_bot_1;
            int script_bot_2;
    };
}
