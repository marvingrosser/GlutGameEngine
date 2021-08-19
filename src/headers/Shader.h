/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Shader.h
 * Author: marvin
 *
 * Created on August 5, 2021, 4:47 PM
 */

#ifndef SHADER_H
#define SHADER_H
#include <string.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <string.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdlib.h>
using std::string;

class Shader {
public:
    Shader();
    void createShader(char * fsCode, char * vsCode);

    string getFSCode();
    string getVSCode();
    GLuint getID();
    void use();
private:
    char * fsCode;
    char * vsCode;
    GLuint fsID;
    GLuint vsID;
    GLuint programID;
};

#endif /* SHADER_H */

