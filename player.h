/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   player.h
 * Author: marvin
 *
 * Created on December 28, 2020, 9:59 AM
 */

#ifndef PLAYER_H
#define PLAYER_H
#include "camera.h"
#include "vertice.h"
class player : camera {
public:
    player(int width, int height, double sensitivity);
    player();
    void renderMouseKeyboard();
    static void mouse(int x, int y);
    static void releaseKey(unsigned char key, int x, int y);
    static void keyboard(unsigned char key, int x, int y);
    static void reshape(int w, int h);
    void setPosition(double x, double y, double z);
private:
    double movecount;
    double movefb;
    double moverl;
    double sens;
    int width;
    int height;
    double x_mouse;
    double y_mouse;
    void calculateMousemovement();
    void calculateKeyboardmovement();
};

#endif /* PLAYER_H */

