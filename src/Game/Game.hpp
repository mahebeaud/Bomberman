/*
** EPITECH PROJECT, 2022
** INdie
** File description:
** Menu header
*/

#pragma once

#include "raylib.h"
#include "Indie.hpp"
#include "Player/Player.hpp"
#include "GameEngine.hpp"
#include <string>
#include <vector>
#include <array>

namespace Indie {
    class Game {
        public:
            enum windowSize {
                FENETRE = 0,
                FULL_SCREEN = 1,
            };
            enum gameAssets {
                //amp object
                LEFT_CORNER = 0,
                UP_WALL = 1,
                RIGHT_CORNER = 2,
                BRAKE_WALL = 3,
                WALL = 4,
                DOWN_WALL = 5,
                LEFT_WALL = 6,
                RIGHT_WALL = 7,
                GROUND = 8,
                BACKGROUND = 9,
                //utils
                BOMB = 11,
                //skin
                DOWN_PG = 10,
                TOMBSTONE = 17,
                //bonus
                FIRE = 12,
                NEWBOMB = 13,
                SPEED = 14,
                DEATH = 15,
                HEALTH = 16,
                //movement idx
                CREEP_BACK_0 = 18,
                CREEP_BACK_1 = 19,
                CREEP_BACK_2 = 20,
                CREEP_BACK_3 = 21,
                CREEP_BACK_4 = 22,
                CREEP_BACK_5 = 23,
                CREEP_FRONT_0 = 24,
                CREEP_FRONT_1 =	25,
                CREEP_FRONT_2 =	26,
                CREEP_FRONT_3 =	27,
                CREEP_FRONT_4 =	28,
                CREEP_FRONT_5 =	29,
                CREEP_RIGHT_0 = 30,
                CREEP_RIGHT_1 =	31,
                CREEP_RIGHT_2 =	32,
                CREEP_RIGHT_3 =	33,
                CREEP_RIGHT_4 =	34,
                CREEP_RIGHT_5 =	35,
                CREEP_LEFT_0 = 36,
                CREEP_LEFT_1 = 37,
                CREEP_LEFT_2 = 38,
                CREEP_LEFT_3 = 39,
                CREEP_LEFT_4 = 40,
                CREEP_LEFT_5 = 41,
                
            };
            enum bonus {
                FIRE_BONUS = 0,
                NEWBOMB_BONUS = 1,
                SPEED_BONUS = 2,
                DEATH_BONUS = 3,
                HEALTH_BONUS = 4,
            };
            enum gameSteps {
                GAME = 0,
                PAUSE = 1,
                SETTING = 2,
                EXIT = 3,
                MENU = 4,
                OVER = 5,
            };
            enum soundIdx {
                BOMB_SND = 0,
                BONUS_SND = 1,
                DEAD_SND = 2,
                WALL_SND = 3,
                GAME_SND = 4,
            };
            Game (std::string path, float volume, int windowSize, std::string usrn, std::string oUsrn, int firstSkinIndex, int secondSkinIndex) noexcept;
            Game (Game &&other) noexcept = default;
            Game &operator=(Game const &other) noexcept = default;
            Game &operator=(Game &&other) noexcept = default;
            ~Game() noexcept = default;

            void load_all_assets(int firstSkinIndex, int secondSkinIndex);
            void load_game(int statement);
            void game_loop(int statement);
            void draw_map(std::vector<Texture2D> allGameTexture);
            void create_bombs(Player *myPlayer);
            void draw_bombs(std::vector<Texture2D> allGameTexture);
            void manage_bombs(std::vector<Texture2D> allGameTexture, Player *myPlayer);
            void draw_bonus(std::vector<Texture2D> allGameTexture, int i);
            void check_collisions(Vector2 middle_bomb, Player *myPlayer, int i);
            void check_collisions_right(Vector2 middle_bomb, Player *myPlayer, int idx);
            void check_collisions_left(Vector2 middle_bomb, Player *myPlayer, int idx);
            void check_collisions_up(Vector2 middle_bomb, Player *myPlayer, int idx);
            void check_collisions_down(Vector2 middle_bomb, Player *myPlayer, int idx);
            bool check_all_bombs_collisions(Vector2 idx);
            void create_bonus(Vector2 bombPos);
            void manage_bonus(std::vector<Texture2D> allGameTexture, Player *myPlayer);
            void check_bonus_disapear(int i);
            void draw_time(void);
            void end_map(Player *myPlayer);
            void spawn_end(void);
            void check_pause(void);
            void check_play(void);
            void manage_pause(void);
            void resume_pause(void);
            void settings_pause(void);
            void save_pause(void);
            void save_all(void);
            void load_pause(void);
            void load_saves(void);
            void menu_pause(void);
            void quit_pause(void);
            void time_pause(void);
            void fix_pause(void);
            void fix_sound(void);
            void fix_window(void);
            int check_who_win(Player *firstPlayer, Player *secondPlayer, Player *firstBot, Player *secondBot);
            void draw_final(int count);

            int windowS;
            float myVolume;
            int gameStatus;
            int startTime;
            int tmpTime;
            int lostTime;
            int pauseTime;
            std::string firstName;
            std::string secondName;
            std::vector<std::string> myMap;
            std::string myPath;
            std::vector<std::string> allGamePath;
            std::vector<std::vector<Rectangle>> collisions;
            std::vector<int> allBombPlayer;
            std::vector<Vector2> allBombPos;
            std::vector<int> allBombTime;
            std::vector<int> allBombRange;
            std::vector<int> allBombPause;
            std::vector<int> allBombCount;
            std::vector<std::array<int, 5>> allBonus;
            std::vector<GameEngine::MakeSound *> allSounds;
            std::vector<Indie::Player *> allPlayers;
    };
}
