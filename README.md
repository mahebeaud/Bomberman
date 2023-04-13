
# Indie Studio : YEP - Yearly-End-Project

## **Main goal**

The goal of this project is to create a bomberman-like game with the **[C++]** language.  
In this project, we had to use the raylib graphical library.
The project can either run on Linux or Windows.

## **How to launch?**

### **Compile**

Run this commands on your terminal:
```bash
$ cd build
$ cmake ..
$ make
$ cd ..
```

### **Launch**

Example:
```
$ ./build/bomberman
```

## **How to play?**

This is a bomberman game, you have to be the last one standing in the arena by exploding your ennemies.  
Some walls are breakable and can give you bonuses to improve your competencies.  
Enjoy the game !

### **Commands**

First player keybinds:
```
|Z|     Move up
|Q|     Move left
|S|     Move down
|D|     Move right
|A|     Drop a bomb
```

Second player keybinds:
```
|↑|     Move up
|←|     Move left
|↓|     Move down
|→|     Move right
|Right Shift|   Drop a bomb
```

### **Implementations**
The particularity of our game is that you can implemente your own map and skins.

To implement a new map, in the utils/map folder, you had to add a nem map_x folder (x = number of the current last map).  
Then you need to implemente assets for each part of the map, or the same for some, but you should have at least 3 differents tiles,
like for the ground, unbreakable walls, and breakable walls. The new assets must have the same name as the others assets map.  
Each tiles mush be 80x80 and the preview must be 500x430.

To implement a new skin, that is the same way, you must follow the same way, but in a different folder : utils/Bomberman, but you must have at least 6 animations for each direction of your skins, and you must have the four basics differents directions : up, down, right, left.  
Skins musn't be > to 75x75, and the preview must be near 350x550.


## PDF of the subject

[Subject - Indie Studio](https://intra.epitech.eu/module/2021/B-YEP-400/BDX-4-1/acti-503074/project/file/B-YEP-400_indie.pdf)


## Authors

- Rémi HUGUET
- Tristan BEAU
- Louis LEBLOND
- Louis FOURMANN
- Mahé BEAUD
- Sofiane EL-HOR

## !! Disclaimer !!

#### All Epitech students are prohibited from copying or using any code from this project !
#### Don't forget the -42 ;)