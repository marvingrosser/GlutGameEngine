/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   object3d.h
 * Author: marvin
 *
 * Created on December 24, 2020, 11:29 PM
 */
#include "face.h"
#include <vector>
#include <string>
#include <fstream>
#include <GL/glut.h>
using namespace std;
using std::endl;
using std::string;
using std::vector;
#ifndef OBJECT3D_H
#define OBJECT3D_H
class object3d {
public:
    object3d();
    
    object3d(vector<face> faces);
    object3d(string name);
    
    void addFace(face newface);
    void playerInTriangle(vertice edges[3], vertice playerPosition);
    void readObj(string name);
    void render(vertice playerPosition);
    double getPlayerHeight();
    object3d getFaces();
    
private:
    vector<face> faces;
    double playerHeight;
    
};

#endif /* OBJECT3D_H */

