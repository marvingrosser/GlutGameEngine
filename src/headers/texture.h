/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   texture.h
 * Author: marvin
 *
 * Created on April 3, 2021, 9:56 PM
 */

#ifndef TEXTURE_H
#define TEXTURE_H
#include <string>
#include <GL/glut.h>
#include <stdlib.h>
#include <fstream>
#include <iostream>
using std::string;
class Texture{
    public:
        Texture();
        Texture(string name,unsigned int number);
        GLuint getID();
    private:
        void loadTexture(string name , GLuint *id);
        GLuint id;
        unsigned int number;
};


#endif /* TEXTURE_H */

