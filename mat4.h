/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   mat4.h
 * Author: marvin
 *
 * Created on December 23, 2020, 2:27 PM
 */

#ifndef MAT4_H
#define MAT4_H

class mat4 {
    private:
        double mat[16];
        
    public:
        
        mat4();
        mat4(double startmat[16]);
        double * get();
        void set(double newmat[16]);
private:

};

#endif /* MAT4_H */

