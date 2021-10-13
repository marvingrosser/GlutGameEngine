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

#include "../headers/szene.h"
#include <vector>
#include "../headers/object3d.h"
#include <iostream>
using std::vector;

szene::szene() {
    this->light = * new Light(*new Vector(1.0f, 10.0f, 1.0f), *new Vector(1.0f,1.0f,1.0f));
    
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
    this->light.sendToShader(&this->shader);
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

void szene::addObjFromFile(string name, string textureName){
    
    object3d obj = * new object3d(name,textureName,&this->shader);
    objects.push_back(obj);
}
void szene::initShader(string vsPath, string fsPath){
    this->shader = * new Shader(vsPath, fsPath);
    this->shader.use();
}
Shader * szene::getShader(){
    return &this->shader;
}