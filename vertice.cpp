/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vetice.cpp
 * Author: marvin
 * 
 * Created on December 26, 2020, 11:24 PM
 */
#include <math.h>
#include <cstdlib>
#include <stdlib.h>
#include <iostream>

#include "vertice.h"

using namespace std;


    vertice::vertice(){
        this->x = 0.0;
        this->y = 0.0;
        this->z = 0.0;
    };
    vertice::vertice(double x, double y, double z){
        this->x = x;
        this->y = y;
        this->z = z;
    };
    vertice::vertice(double vec[3]){
        this->x = vec[0];
        this->y = vec[1];
        this->z = vec[2];
    };
    double vertice::getX(){
        return this->x;
    };
    double vertice::getY(){
        return this->y;
    };
    double vertice::getZ(){
        return this->z;
    };
    void vertice::set(double x, double y, double z){
        this->x = x;
        this->y = y;
        this->z = z;
    };
    double vertice::distance(vertice* vec){
        vertice sub = *this - *vec;
        return this->length(&sub);
    };
    vertice vertice::operator+(const vertice vec) const {
        return *new vertice(this->x + vec.x, this->y + vec.y, this->z + vec.z);
    };
    vertice vertice::operator-(const vertice vec) const {
        return *new vertice(this->x - vec.x, this->y - vec.y, this->z - vec.z);
    };
    vertice vertice::operator*(const double factor) const {
        return *new vertice(this->x * factor, this->y * factor, this->z * factor);
    };
    vertice vertice::operator/(const double divisor){
        return *new vertice(this->x / divisor, this->y / divisor, this->z / divisor);
    };
    
    double vertice::length(){
        return this->length(this);
    };
    
    void vertice::normalize(){
        this->x = x/ length();
        this->y = y/ length();
        this->z = z/ length();
    };
    
    vertice vertice::normalizedGet(){
        return  *this;
    };
    
    
    double vertice::length(vertice* vec){
        return sqrt( pow(vec->x,2) + pow(vec->y,2) + pow(vec->z,2));
    };




