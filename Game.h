/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.h
 * Author: marvin
 *
 * Created on January 1, 2021, 6:55 PM
 */

#ifndef GAME_H
#define GAME_H
#include <GL/glut.h>
#include "szene.h"
#include "player.h"
#include "camera.h"
class Game {
public:
    Game();
    Game(player spieler, szene scene);
    void render();
    void init();
    void loadObjs();
private:
    player spieler;
    szene scene;
};

#endif /* GAME_H */

