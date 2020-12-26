/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   face.cpp
 * Author: marvin
 * 
 * Created on December 24, 2020, 11:31 PM
 */
#include "face.h"

#include "vertice.h"
#include <cstdlib>
#include <stdlib.h>

using namespace std;

face::face() {
    this->set(*new vertice(),*new vertice(),*new vertice(),*new vertice() );
};

face::face(vertice x, vertice y, vertice z, vertice normal){
    this->set(x,y,z,normal);
};





vertice face::getNormal(){
    return this->normal;
};

vertice face::getX(){
    return this->X;
};

vertice face::getY(){
    return this->Y;
};

vertice face::getZ(){
    return this->Z;
};


void face::set(vertice x, vertice y, vertice z, vertice normal){
    this->X = x;
    this->Y = y;
    this->Z = z;

    this->normal = normal;
};

void face::setNormal(vertice normal){
    this->normal = normal;
};

void face::setX(vertice x){
    this->X = x;
};

void face::setY(vertice y){
    this->Y = y;
};
void face::setZ(vertice z){
    this->Z = z;
};
