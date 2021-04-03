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
    static void render();
    void init();
    void loadObjs();
    static void releaseKey(unsigned char, int, int);
    static void reshape( int, int);
    static void keyboard( unsigned char, int, int);
    static void mouse( int, int);
    
private:
    static player spieler;
    static szene scene;
};

#endif /* GAME_H */

