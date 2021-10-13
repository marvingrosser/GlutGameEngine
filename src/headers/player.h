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
#include "Vector.h"
#include <math.h>
#include <GL/glut.h>
#include "Shader.h"
#include<iostream>
class player{
public:
    void render(Shader * shader);
    player(int width, int height, double sensitivity, double walk_sens) ;
    player();
    void renderMouseKeyboard();
    void mouse(int x, int y);
    void releaseKey(unsigned char key, int x, int y);
    void keyboard(unsigned char key, int x, int y);
    void reshape(int w, int h);
    void setPosition(float x, float y, float z);
private:
    int width;
    int height;
    camera cam;
    double movecount;
    double movefb;
    double moverl;
    double sens;
    double walk_sens;
    double x_mouse;
    double y_mouse;
    /**
     * 
     * Calculates the Movement the mouse does to the cam 
     * @param direction
     * @param CNORM
     */
    void calculateCamMovement(Vector * direction, Vector * CNORM);
    /**
     * Calculates the movement via the Keyboardkeys
     * @param direction
     */
    void calculateKeyboardmovement(Vector * direction);
};

#endif /* PLAYER_H */

