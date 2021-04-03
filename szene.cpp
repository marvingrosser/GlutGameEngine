/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   szene.cpp
 * Author: marvin
 * 
 * Created on December 27, 2020, 11:24 PM
 */

#include "szene.h"
#include <vector>
#include "object3d.h"
#include <iostream>
using std::vector;

szene::szene() {
    return;
};

szene::szene(object3d obj){
    this->objects.push_back(obj);
};

szene::szene(vector<object3d> objs){
    this->objects = objs;
};

object3d szene::getObjectByID(int id){
    return this->objects.at(id);
};

vector<object3d> szene::getObjects(){
    return this->objects;
};

void szene::render(){
    for(auto object : this->objects){
        
        object.render();
    }
}
void szene::setPlayer(player spieler){
    this->spieler = spieler;
}
player szene::getPlayer(){
    return spieler;
}

void szene::addObjFromFile(string name){
    object3d obj = * new object3d(name);
    objects.push_back(obj);
}