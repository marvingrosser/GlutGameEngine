/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mat4.cpp
 * Author: marvin
 * 
 * Created on December 23, 2020, 2:27 PM
 */

#include "../headers/mat4.h"

mat4::mat4() {
    this->mat = glm::mat4(1.0f);
};

GLfloat * mat4::getPtr(){
    return &this->mat[0][0];
};
void mat4::rotate(glm::vec3 axis, float angle){
    this->mat = glm::rotate(this->mat, glm::radians(angle), axis);
};
void mat4::rotate(Vector axis, float angle){
    glm::vec3 newaxis = glm::vec3(axis.getX(), axis.getY(), axis.getZ());
    this->rotate(newaxis,angle);
};

void mat4::scale(glm::vec3 scale){
    this->mat = glm::scale(this->mat,scale);
};

void mat4::scale(Vector scale){
    glm::vec3 newscale = glm::vec3(scale.getX(), scale.getY(), scale.getZ());
    this->scale(newscale);
};



void mat4::translate(Vector v){
    glm::vec3 vec = glm::vec3(v.getX(), v.getY(), v.getZ());
    this->translate(vec);
};
void mat4::translate(glm::vec3 v){
    this->mat = glm::translate(this->mat,v);
};
mat4::mat4(double mat[16]) {
    this->mat = {mat[1],mat[2],mat[3],mat[4],
                mat[5],mat[6],mat[7],mat[8],
                mat[9],mat[10],mat[11],mat[12],
                mat[13],mat[14],mat[15],mat[16]};
                
};
glm::mat4 mat4::get(){
    return mat;
};
float * mat4::getdouble(){
    return  new float[16]{mat[1][1],mat[1][2],mat[1][3],mat[1][4],
                mat[2][1],mat[2][2],mat[2][3],mat[2][4],
                mat[3][1],mat[3][2],mat[3][3],mat[3][4],
                mat[4][1],mat[4][2],mat[4][3],mat[4][4]};
};

void mat4::set(double newmat[16]){
    for (int i = 0; i < 16; i++){
        mat[i/4 + 1][i % 4 + 1] = newmat[i];
    }
  

};  
void mat4::set(glm::mat4 newmat){
    mat = newmat;
};

mat4::mat4(glm::mat4 startmat){
    mat = startmat;
}