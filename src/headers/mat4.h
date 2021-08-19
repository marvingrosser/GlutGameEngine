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
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Vector.h"
class mat4 {
    private:
        glm::mat4 mat;
        
    public:
        void rotate(Vector axis, float angle);
        void rotate(glm::vec3, float angle);
        void scale(glm::vec3 scale);
        void scale(Vector scale);
        void translate(glm::vec3 v);
        void translate(Vector v);
        GLfloat * getPtr();
        mat4();
        mat4(double startmat[16]);
        mat4(glm::mat4 startmat);
        float * getdouble();
        glm::mat4 get();
        void set(double newmat[16]);
        void set(glm::mat4 newmat);
private:

};

#endif /* MAT4_H */

