/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vector.h
 * Author: marvin
 *
 * Created on December 22, 2020, 9:12 PM
 */

#ifndef VECTOR_H
#define VECTOR_H
class vector {
public:
    vector();
    
    vector(double x, double y, double z);
    
    vector(double vec[3]);
    
    double getX();
    
    double getY();
    
    double getZ();
    
    void set(double x, double y, double z);
    
    double distance(vector* vec);
    
    vector operator+(const vector vec) const ;
    
    vector operator-(const vector vec) const ;
    
    vector operator*(const double factor) const ;
    
    vector operator/(const double divisor);
    
    double length();
    
    void normalize();
    
    vector normalizedGet();
    
    
private:
    double x;
    double y;
    double z;
    double length(vector* vec);
};




#endif /* VECTOR_H */

