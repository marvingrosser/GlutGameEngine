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
#include "Vector.h"
using std::string;

class Shader {
public:
    Shader();
    /**
     * loads String from given File
     * @param vsPath the path pointing to the Vertex Shader file
     * @param fsPath the path pointing to the Fragment Shader file
     */
    Shader(string vsPath, string fsPath);
    /**
     *  Creates Shader with Shadercode provided in cstring
     * @param fsCode Fragment Shader-Code
     * @param vsCode Vertex Shader-Code
     */
    void createShader(char * fsCode, char * vsCode);
    void setMatrix(string name, GLfloat * data);
    /**
     * Sends Vectordata to Shader (vec3)
     * @param name Identifyier the Data will be called in the shader
     * @param data Data to send
     */
    void setVector(string name, Vector data);
    /**
     * Sends 2d Vectordata to shader
     * @param name Identifyer the Data will be called in the Shader
     * @param x first data part
     * @param y second data part
     */
    void set2DVector(string name, float x, float y);
    /**
     * Sends single float to shader
     * @param name Identifyer the Data will be called in the Shader
     * @param data the Float data that will be sent to the shader
     */
    void setConstant(string name, float data);
    void setInt(string name, int data);
    /**
     * 
     * @return Fragment shader Code 
     */
    string getFSCode();
    /**
     * 
     * @return Vertex shader Code 
     */
    string getVSCode();
    /**
     * 
     * @return OPENGL-ID associated with the Shader
     */
    GLuint getID();
    /**
     * Use the Shader in RenderPipeline
     */
    void use();
private:
    /**
     * reads file and returns c-string
     * @param name filepath
     * @return 
     */
    string readFile(string name);
    char * fsCode;
    char * vsCode;
    GLuint fsID;
    GLuint vsID;
    GLuint programID;
};

#endif /* SHADER_H */

