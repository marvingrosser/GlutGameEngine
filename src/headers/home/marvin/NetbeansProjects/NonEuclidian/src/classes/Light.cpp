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
    shader->setVector("light.diffuse", color);
    shader->setVector("light.ambient", color);
    shader->setVector("light.specular", color);
    shader->setVector("light.position", position);
    shader->setConstant("light.c", 1.0f);
    shader->setConstant("light.l", 0.09f);
    shader->setConstant("light.q", 0.032f);
}
Light::Light(Vector position, Vector color) {
    this->position = position;
    this->color = color;
}

Light::Light() {
    this->color = * new Vector(1.0f,1.0f,1.0f);
    this->position = * new Vector(0.0f,0.0f,0.0f);
}

