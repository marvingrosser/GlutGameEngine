/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Shader.cpp
 * Author: marvin
 * 
 * Created on August 5, 2021, 4:47 PM
 */

#include "../headers/Shader.h"
 

GLuint Shader::getID(){
    return this->programID;
};
Shader::Shader(){
    char * vs = (char*) "#version 460 core\n "
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec3 aNormal;\n"
    "layout (location = 2) in vec2 aTexCoord;\n"
    "uniform mat4 model;\n"
    "uniform mat4 view;\n"
    "uniform mat4 projection;\n"
    "out vec2 TexCoord;\n"
    "void main()\n"
    "{\n"
    "gl_Position = projection * view * model * vec4(aPos, 1.0f);\n"
    "TexCoord = aTexCoord;"
    "}\n\0";

    char * fs = (char *)"#version 460 core\n"
        "out vec4 FragColor;\n"
        "in vec2 TexCoord;\n"
        "uniform sampler2D DiffTexture;\n"
        "void main()\n"
        "{\n"
        " FragColor = texture(DiffTexture, TexCoord);\n"
        " }\n\0";
   this->createShader(fs,vs);
};
void Shader::createShader(char * ifsCode, char * ivsCode) {
  
    this->fsCode= ifsCode;
    this->vsCode = ivsCode;
        //Init fragmentshader and compile
    this->fsID = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(this->fsID,1,&this->fsCode,NULL);
    glCompileShader(this->fsID);
            
        // Init vertexshader and compile
    this->vsID = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(this->vsID, 1, &this->vsCode, NULL);
    glCompileShader(this->vsID);
        
        //get Errors for Vertexshader
    int success;
    char infoLog[512];
    glGetShaderiv(this->vsID, GL_COMPILE_STATUS, &success);
    
    if(!success){
        glGetShaderInfoLog(this->vsID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" <<
        infoLog << std::endl;
    }
        //get Errors for Fragment shader

    glGetShaderiv(this->fsID, GL_COMPILE_STATUS, &success);
    
    if(!success){
        glGetShaderInfoLog(this->fsID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" <<
        infoLog << std::endl;
    }
    
    programID = glCreateProgram();
    glAttachShader(this->programID, this->vsID);
    glAttachShader(this->programID, this->fsID);
    glLinkProgram(this->programID);
    glDetachShader(this->programID, this->vsID);
    glDetachShader(this->programID, this->fsID);
    
    glGetProgramiv(this->programID, GL_LINK_STATUS, &success);
    
    if(!success) {
        glGetProgramInfoLog(this->programID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" <<
        infoLog << std::endl;
    }
    
    glDeleteShader(this->vsID);
    glDeleteShader(this->fsID);
    
    
}

string Shader::getFSCode(){
    return this->fsCode;
}

string Shader::getVSCode(){
    return this->vsCode;
}

void Shader::use(){
    glUseProgram(this->programID);
}

