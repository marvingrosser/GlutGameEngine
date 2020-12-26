/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   face.h
 * Author: marvin
 *
 * Created on December 24, 2020, 11:31 PM
 */

#ifndef FACE_H
#define FACE_H
#include "vertice.h"
class face {
    
public:
    
    face();
    
    face(vertice x, vertice y, vertice z, vertice normal);
    

    
    vertice getX();
    
    vertice getY();
    
    vertice getZ();
    

    
    vertice getNormal();
    void setNormal(vertice normal);
    void setX(vertice x);
    void setY(vertice y);
    void setZ(vertice z);

    
    void set(vertice x, vertice y, vertice z, vertice normal);
    
    int size();
    
private:
    
    vertice X;
    
    vertice Y;
    
    vertice Z;
    
    vertice normal;
};

#endif /* FACE_H */

