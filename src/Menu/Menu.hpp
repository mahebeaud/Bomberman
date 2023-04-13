/*
** EPITECH PROJECT, 2022
** INdie
** File description:
** Menu header
*/

#pragma once

#include "raylib.h"
#include "Indie.hpp"
#include <string>
#include <vector>

namespace Indie {
    class Menu {
        public:
            enum indexTexture {
                BACKGROUND = 0,
                QUIT = 1,
                PREVIEW_ONE = 2,
                PREVIEW_TWO = 3,
                PREVIEW_THREE = 4,
                PREVIEW_FOUR = 5,
                RED_PREVIEW = 6,
                YELLOW_PREVIEW = 7,
                BLUE_PREVIEW = 8,
                WHITE_PREVIEW = 9,
            };
            enum allUnderSteps {
                MAIN_MENU = 0,
                CHOSE_MODE = 1,
                SETTINGS = 2,
                CHOSE_MAP = 3,
                SOLO_GAME = 4,
                LOAD_GAME = 5,
                END = 6,
            };
            enum windowSize {
                FENETRE = 0,
                FULL_SCREEN = 1,
            };

            Menu (void) noexcept;
            Menu (Menu &&other) noexcept = default;
            Menu &operator=(Menu const &other) noexcept = default;
            Menu &operator=(Menu &&other) noexcept = default;
            ~Menu() noexcept = default;

            void menu_loop(void);
            void main_menu(void);
            void chose_mode(std::vector<Texture2D> allMenuTexture);
            void get_name(void);
            void solo_or_multi(void);
            void change_map(void);
            void show_map(std::vector<Texture2D> allMenuTexture);
            void settings(void);
            void check_play(void);
            void check_settings(void);
            void draw_border(void);
            void check_back(void);
            void check_quit(std::vector<Texture2D> allMenuTexture);
            void check_window_size(void);
            void draw_arrow(void);
            void fenetre(void);
            void full_screen(void);
            void little(void);
            void check_sound(void);
            void draw_sym(void);
            void edit_sound(void);
            void chose_map(std::vector<Texture2D> allMenuTexture);
            void get_second_name(void);
            void chose_first_skin(std::vector<Texture2D> allMenuTexture);
            void chose_second_skin(std::vector<Texture2D> allMenuTexture);
            void help(void);

            int current_map;
            std::vector<std::string> myMap;
            std::string username;
            std::string otherUsername;
            int firstSkin;
            int secondSkin;
            int underStep;
            int windowSize;
            float volume;

        std::vector<const char *> allMenuPath;
    };
}
