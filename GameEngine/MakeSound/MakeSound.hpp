/*
** EPITECH PROJECT, 2022
** Indie
** File description:
** soun
*/

#pragma once

#include "raylib.h"
#include <vector>

namespace GameEngine {
    class MakeSound {
    public:
        MakeSound (const char *path) noexcept;
        MakeSound (MakeSound const &other) noexcept = default;
        MakeSound (MakeSound &&other) noexcept = default;
        MakeSound &operator=(MakeSound const &other) noexcept = default;
        MakeSound &operator=(MakeSound &&other) noexcept = default;
        ~MakeSound() noexcept = default;

        void play_sound(void);
        void setSound(float volume);
        void unloadSound(void);
        Sound snd;
    };
}
