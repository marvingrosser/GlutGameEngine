/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vector.cpp
 * Author: marvin
 * 
 * Created on December 22, 2020, 9:12 PM
 */
#include <math.h>
#include <cstdlib>
#include <stdlib.h>
#include <iostream>

#include "vector.h"

using namespace std;


    vector::vector(){
        this->x = 0.0;
        this->y = 0.0;
        this->z = 0.0;
    };
    vector::vector(double x, double y, double z){
        this->x = x;
        this->y = y;
        this->z = z;
    };
    vector::vector(double vec[3]){
        this->x = vec[0];
        this->y = vec[1];
        this->z = vec[2];
    };
    double vector::getX(){
        return this->x;
    };
    double vector::getY(){
        return this->y;
    };
    double vector::getZ(){
        return this->z;
    };
    void vector::set(double x, double y, double z){
        this->x = x;
        this->y = y;
        this->z = z;
    };
    double vector::distance(vector* vec){
        vector sub = *this - *vec;
        return this->length(&sub);
    };
    vector vector::operator+(const vector vec) const {
        return *new vector(this->x + vec.x, this->y + vec.y, this->z + vec.z);
    };
    vector vector::operator-(const vector vec) const {
        return *new vector(this->x - vec.x, this->y - vec.y, this->z - vec.z);
    };
    vector vector::operator*(const double factor) const {
        return *new vector(this->x * factor, this->y * factor, this->z * factor);
    };
    vector vector::operator/(const double divisor){
        return *new vector(this->x / divisor, this->y / divisor, this->z / divisor);
    };
    
    double vector::length(){
        return this->length(this);
    };
    
    void vector::normalize(){
        this->x = x/ length();
        this->y = y/ length();
        this->z = z/ length();
    };
    
    vector vector::normalizedGet(){
        return  *this;
    };
    
    
    double vector::length(vector* vec){
        return sqrt( pow(vec->x,2) + pow(vec->y,2) + pow(vec->z,2));
    };

