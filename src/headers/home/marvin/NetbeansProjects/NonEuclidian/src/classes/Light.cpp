/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Light.cpp
 * Author: marvin
 * 
 * Created on October 12, 2021, 10:49 AM
 */

#include "../headers/Light.h"
void Light::sendToShader(Shader* shader){
    shader->setVector("lightColor", color);
    shader->setVector("lightPos", position);
}
Light::Light(Vector position, Vector color) {
    this->position = position;
    this->color = color;
}

Light::Light() {
    this->color = * new Vector(1.0f,1.0f,1.0f);
    this->position = * new Vector(0.0f,0.0f,0.0f);
}

