/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vetice.h
 * Author: marvin
 *
 * Created on December 26, 2020, 11:24 PM
 */

#ifndef VETICE_H
#define VETICE_H
#include <string>

class vertice {
public:
    vertice();
    
    vertice(double x, double y, double z);
    
    vertice(double vec[3]);
    
    double getX();
    
    double getY();
    
    double getZ();
    
    void set(double x, double y, double z);

    void setX(double x);
    void setY(double y);
    void setZ(double z);
    
    double distance(vertice* vec);
    
    vertice operator+(const vertice vec) const ;
    
    vertice operator-(const vertice vec) const ;
    
    vertice operator*(const double factor) const ;
    
    vertice operator/(const double divisor);
    
    double length();
    
    void normalize();
    
    vertice normalizedGet();

    std::string toString();
    
    
private:
    double x;
    double y;
    double z;
    double length(vertice* vec);
};




#endif /* VETICE_H */

