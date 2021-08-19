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
#include "../headers/Face.h"

#include "../headers/Vector.h"
#include <cstdlib>
#include <stdlib.h>
#include <GL/glut.h>
#include <iostream>
using namespace std;


Face::Face(){}
Face::Face(Vector * x, Vector * y, Vector * z, Vector normal){
    this->set(x,y,z,normal);
    
};


void Face::init(){
    return;
    //glGenBuffers(1, &VBO);
    //glBindBuffer(GL_ARRAY_BUFFER,VBO);
    //glBufferData(GL_ARRAY_BUFFER,sizeof(),,GL_STATIC_DRAW);
}


Vector * Face::getNormal(){
    return & this->normal;
};

Vector * Face::getX(){
    return this->X;
};

Vector * Face::getY(){
    return this->Y;
};

Vector * Face::getZ(){
    return this->Z;
};


void Face::set(Vector * x, Vector * y, Vector * z, Vector normal){
    this->X = x;
    this->Y = y;
    this->Z = z;
    this->normal = normal;
};

void Face::setNormal(Vector normal){
    this->normal = normal;
};

void Face::setX(Vector * x){
    this->X = x;
};

void Face::setY(Vector * y){
    this->Y = y;
};
void Face::setZ(Vector * z){
    this->Z = z;
};

double Face::area(){
    Vector xy = *this->X | *this->Y;
    
    Vector xz = *this->X | *this->Y;
    
    return this->calculateTriangleArea(xy,xz);
};

void Face::render() {
    /*glBegin(GL_TRIANGLES);
        glNormal3f(this->normal.getX(),
                   this->normal.getY(), 
                   this->normal.getZ()); //Normal und die 3 punkte laden
 
        //std::cout << (* this->X).to_string() << std::endl;
        this->setRenderTextureCoordinates(this->X_texturecoord);
        glVertex3f((* this->X).getX(), (* this->X).getY(), (* this->X).getZ());
        this->setRenderTextureCoordinates(this->Y_texturecoord);
        glVertex3f((*this->Y).getX(), (*this->Y).getY(), (*this->Y).getZ());
        this->setRenderTextureCoordinates(this->Z_texturecoord);
        glVertex3f((*this->Z).getX(), (*this->Z).getY(), (*this->Z).getZ());
        const GLfloat mat[] = {1, 1, 1, 1} ;
        glMaterialfv( GL_FRONT,GL_DIFFUSE,mat); //material bestimmen
    glEnd();*/
    
    
};

void Face::setRenderTextureCoordinates(std::vector<double>* coord){
    
    if(coord && coord){
        glTexCoord2f(coord->at(0), coord->at(1));
    }
    
};
double Face::calculateTriangleArea(Vector ab, Vector ac){
    return ab.crossProduct(ac).length() * 0.5;
};

string Face::to_string(){
    return "Face:\n \t X: \t" + (*this->X).to_string() 
            + "\n\t Y: \t" + (*this->Y).to_string() 
            + "\n\t Z: \t" + (*this->Z).to_string() 
            + "\n\t Normal:" + ( this->normal).to_string();
};

void Face::setTextureCoord_X(std::vector<double>& X_texturecoord){
    this->X_texturecoord = &X_texturecoord;
};

void Face::setTextureCoord_Y(std::vector<double>& Y_texturecoord){
    this->Y_texturecoord = &Y_texturecoord;
};

void Face::setTextureCoord_Z(std::vector<double>& Z_texturecoord){
    this->Z_texturecoord = &Z_texturecoord;
};

std::vector<double>* Face::getTextureCoord_X(){
    return this->X_texturecoord;
};

std::vector<double>* Face::getTextureCoord_Y(){
    return this->Y_texturecoord;
};

std::vector<double>* Face::getTextureCoord_Z(){
    return this->Z_texturecoord;
};