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

#include <GL/glew.h>
#include <GL/glut.h>
#include "Shader.h"
#include "szene.h"
#include "player.h"
#include "camera.h"
#include "texture.h"

class Game {
public:
    Game();
    Game(player spieler, szene scene);
    static void render();
    void init();
    void loadObjs();
    static void releaseKey(unsigned char key, int x, int y);
    static void reshape( int w, int h);
    static void keyboard( unsigned char key, int x, int y);
    static void mouse( int x, int y);
    
private:
    static player spieler;
    static szene scene;
};

#endif /* GAME_H */

