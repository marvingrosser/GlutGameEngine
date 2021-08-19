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

#include "../headers/Vector.h"

#define EPSILON 0.0001
using namespace std;

    
    Vector::Vector(float* vec){
        this->vec = vec;
    }
    Vector::Vector(float& vec){
        this->vec = &vec;
    };
    Vector::Vector(){
        this->vec = new float[3];
        this->vec[0] = 0.0;
        this->vec[1] = 0.0;
        this->vec[2] = 0.0;
    };
    Vector::Vector(float x, float y, float z){
        this->vec = new float[3];
        this->vec[0] = x;
        this->vec[1] = y;
        this->vec[2] = z;
    };
    Vector::Vector(double vec[3]){
        this->vec = new float[3];
        this->vec[0] = vec[0];
        this->vec[1] = vec[1];
        this->vec[2] = vec[2];
    };
    double Vector::getX(){
        return this->vec[0];
    };
    double Vector::getY(){
        return this->vec[1];
    };
    double Vector::getZ(){
        return this->vec[2];
    };
    void Vector::set(float x, float y, float z){
        this->vec[0] = x;
        this->vec[1] = y;
        this->vec[2] = z;
    };
    double Vector::distance(Vector* vec){
        Vector sub = *this - *vec;
        return this->length(&sub);
    };
    
    Vector Vector::operator +(const Vector vec) const {
        return *new Vector(this->vec[0] + vec.vec[0], this->vec[1] + vec.vec[1], this->vec[2] + vec.vec[2]);
    };
    Vector Vector::operator -(const Vector vec) const {
        return *new Vector(this->vec[0] - vec.vec[0], this->vec[1] - vec.vec[1], this->vec[2] - vec.vec[2]);
    };
    
    Vector Vector::operator *(const Vector vec) const{
        return *new Vector(this->vec[0] * vec.vec[0], this->vec[1] * vec.vec[1], this->vec[2] * vec.vec[2]);
    };
    
    Vector Vector::operator *(const double factor) const {
        return *new Vector(this->vec[0] * factor, this->vec[1] * factor, this->vec[2] * factor);
    };
    Vector Vector::operator /(const double divisor){
        return *new Vector(this->vec[0] / divisor, this->vec[1] / divisor, this->vec[2] / divisor);
    };
    
    Vector Vector::operator +(const double addend) const{
        return *new Vector(this->vec[0] + addend, this->vec[1] + addend, this->vec[2] + addend);
    };
    
    Vector Vector::operator -(const double substractor) const{
        return *new Vector(this->vec[0] - substractor, this->vec[1] - substractor, this->vec[2] - substractor);
    };
    
    Vector Vector::operator |(const Vector B) const{
        return B - *this;
    };
    
    
    bool Vector::operator ==(const Vector vec) const{
        return     this->vec[0] == vec.vec[0] 
                && this->vec[1] == vec.vec[1] 
                && this->vec[2] == vec.vec[2];
    };
    
    
    bool Vector::linearTo(Vector vec){
        return isRelationForAllVectorvaluesTheSame(vec);
    };
    
    bool Vector::isRelationForAllVectorvaluesTheSame(Vector vec){
        
        double relation = this->vec[0] / vec.vec[0];
        
        if(this->vec[1] / vec.vec[1] - relation < EPSILON){
            if(this->vec[2] / vec.vec[2] - relation < EPSILON){
                return true;
            }else{
                return false;
            }
        }else{
            return false;
        }
    };
    
    double Vector::length(){
        return this->length(this);
    };
    
    void Vector::normalize(){
        this->vec[0] = vec[0]/ length();
        this->vec[1] = vec[1]/ length();
        this->vec[2] = vec[2]/ length();
    };
    
    Vector Vector::normalizedGet(){
        return  *this;
    };
    
    
    double Vector::length(Vector* vec){
        return Vector::length(vec->getX(),vec->getY(),vec->getZ());
    };
    
    Vector Vector::crossProduct(Vector vec){
        return *new Vector(this->vec[1] * vec.vec[2] - this->vec[2] * vec.vec[1],
                           this->vec[2] * vec.vec[0] - this->vec[0] * vec.vec[2],
                           this->vec[0] * vec.vec[1] - this->vec[1] * vec.vec[0]);
    };
    
    
    double Vector::scalar(Vector vec){
        return this->vec[0] * vec.vec[0] + this->vec[1] * vec.vec[1] + this->vec[2] * vec.vec[2];
    };
    
    
    
    double Vector::angle(Vector vec){
        /**
         * a * b
         * ------
         * |a||b| 
         */
        
        return this->scalar(vec) / 
                                    (this->length() * vec.length());
    };
    
    double Vector::length(double x, double y, double z){
        return sqrt(pow(x,2) + pow(y,2) + pow(z,2));
    };

    string Vector::to_string(){
        return "( " + std::to_string(this->vec[0]) + ", " + std::to_string(this->vec[1]) + ", " + std::to_string(this->vec[2]) + " )";
    };
    glm::vec3 Vector::get(){
        return glm::vec3(this->getX(), this->getY(), this->getZ());
    };