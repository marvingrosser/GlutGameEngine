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

Light::Light(Vector position, Vector color) {
    this->position = position;
    this->color = color;
}

Light::Light(const Light& orig) {
}

Light::~Light() {
}

