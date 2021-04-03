/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   szene.h
 * Author: marvin
 *
 * Created on December 27, 2020, 11:24 PM
 */

#ifndef SZENE_H
#define SZENE_H
#include <vector>
#include <string>
#include "object3d.h"
#include "player.h"
using std::vector;
using std::string;

class szene {
public:
    szene();
    
    szene(object3d obj);
    
    szene(vector<object3d> objs);
    void render();
    player getPlayer();
    void setPlayer(player spieler);
    object3d getObjectByID(int id);
    
    vector<object3d> getObjects();
    
    void addObjFromFile(string name);
    
private:
    vector<object3d> objects;
    player spieler;
};

#endif /* SZENE_H */

