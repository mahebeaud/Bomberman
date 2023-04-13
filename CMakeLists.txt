cmake_minimum_required(VERSION 3.17)

project("bomberman" VERSION 1.0 LANGUAGES CXX)

add_executable(bomberman
    src/main.cpp
    src/print_doc.cpp
    src/Indie.cpp
    src/Menu/Menu.cpp
    src/Menu/border/border.cpp
    src/Menu/setting/setting.cpp
    src/Menu/setting/step.cpp
    src/Menu/setting/sound.cpp
    src/Menu/setting/window_size.cpp
    src/Menu/chose_mode/chose_mode.cpp
    src/Menu/username/username.cpp
    src/Menu/chose_mode/mode.cpp
    src/Menu/chose_map/chose_map.cpp
    src/Menu/chose_map/map.cpp
    src/Menu/skin/skin.cpp
    src/Game/Game.cpp
    src/Game/Game_assets_loader.cpp
    src/Game/core/draw_map.cpp
    src/Game/core/bomb_collision.cpp
    src/Game/core/bombs.cpp
    src/Game/core/bonus.cpp
    src/Game/core/death_time.cpp
    src/Game/core/pause.cpp
    src/Game/core/end.cpp
    src/Game/Player/Player.cpp
    src/Game/Player/ia_1.cpp
    src/Game/Player/ia_2.cpp
    GameEngine/MakeSound/MakeSound.cpp
    GameEngine/MakeSound/sound.cpp
    GameEngine/Keyboard/key_pressed.cpp
    GameEngine/Window/window.cpp
    GameEngine/Event/window_closed.cpp
)


target_link_libraries(bomberman
    PRIVATE
    -lraylib
    -lGL
    -lm
    -lpthread
    -ldl
    -lrt
    -lX11
)

target_include_directories(bomberman
    PRIVATE
    include/
    src/
    src/Game/
    src/Menu/
    GameEngine/
    GameEngine/Makesound/
)

if (WIN32)
    COMMAND ("dotnet new sln --name bomberman")
    COMMAND ("dotnet sln \"bomnberman.sln\" add \".\"")
    COMMAND ("msbuild bomberman.sln /p:Configuration=Release")
    COMMAND ("start bomberman/bin/Release/bomberman.exe")
endif ()

if (UNIX AND NOT APPLE)
    set(EXECUTABLE_OUTPUT_PATH$(CMAKE_BINARY_DIR)/../)
    set(CMAKE_CXX_STANDARD 20)
endif ()
