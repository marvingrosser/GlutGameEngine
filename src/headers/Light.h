/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Light.h
 * Author: marvin
 *
 * Created on October 12, 2021, 10:49 AM
 */

#ifndef LIGHT_H
#define LIGHT_H
#include "Vector.h"
#include "Shader.h"
class Light {
public:
    Light(Vector position, Vector color);
    Light();
    void sendToShader(Shader * shader);
private:
    Vector position;
    Vector color;
};

#endif /* LIGHT_H */

