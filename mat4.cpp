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

#include "mat4.h"

mat4::mat4() {
    this->mat[0]=0.0;
};

mat4::mat4(double startmat[16]) {
    for (int i = 0; i < 16; i++){
        this->mat[i] = startmat[i];
    }
};

double * mat4::get(){
    return this->mat;
};

void mat4::set(double newmat[16]){
    for (int i = 0; i < 16; i++){
        this->mat[i] = newmat[i];
    }

};  

