/*
** EPITECH PROJECT, 2022
** indie
** File description:
** gamengine
*/

#include "MakeSound/MakeSound.hpp"
#include <string>

namespace GameEngine {
    char get_key_pressed(void);
    void init_window(int x, int y, std::string windowName);
    void close_window(void);
    void set_max_fps(int max);
    void init_audio(void);
    void close_audio(void);
    bool check_window_close(void);
}
