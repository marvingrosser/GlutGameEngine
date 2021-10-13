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
Shader::Shader(string vsPath, string fsPath){
    string vsCode =  Shader::readFile(vsPath);
    string fsCode =  Shader::readFile(fsPath);
    
    this->createShader((char *)fsCode.c_str(),(char *)vsCode.c_str());
}
Shader::Shader(){
    char * vs = (char*) "#version 460 core\n "
    "layout (location = 0) in vec3 aPos;\n"
    "layout (location = 1) in vec3 aNormal;\n"
    "layout (location = 2) in vec2 aTexCoord;\n"
    "uniform mat4 model;\n"
    "uniform mat4 view;\n"
    "uniform mat4 projection;\n"
    "out vec2 TexCoord;\n"
    "out vec3 Normal;\n"
    "out vec3 FragPos;\n"
    "void main()\n"
    "{\n"
    "gl_Position = projection * view * model * vec4(aPos, 1.0f);\n"
    "TexCoord = aTexCoord;\n"
    "Normal = aNormal;\n"
    "FragPos = vec3(model * vec4(aPos, 1.0f));\n"
    "}\n\0";

    char * fs = (char *)"#version 460 core\n"
        "out vec4 FragColor;\n"
        "in vec2 TexCoord;\n"
        "in vec3 Normal;\n"
        "in vec3 FragPos;\n"
        "uniform sampler2D DiffTexture;\n"
        "void main()\n"
        "{\n"
        "vec3 norm = normalize(Normal);\n"
        "vec3 lightDir = normalize(vec3(3.0f,4.0f,8.0f) - FragPos);\n"
        "float diff = max(dot(norm, lightDir), 0.0);\n"
        "vec3 diffuse = diff * vec3(1.0f,1.0f,1.0f);\n"
        "FragColor = vec4(diffuse + vec3(0.1f, 0.1f, 0.1f), 1.0f) * texture(DiffTexture, TexCoord);\n"
        " }\n\0";
   //this->createShader(fs,vs);
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
void Shader::setVector(string name, Vector data){
    std::cout << data.to_string()<< std::endl;
    glUniform3f(glGetUniformLocation(this->programID,name.c_str()), data.getX(), data.getY(), data.getZ());
}
void Shader::set2DVector(string name, float x, float y){
    glUniform2f(glGetUniformLocation(this->programID,name.c_str()),x,y);
}
void Shader::setConstant(string name, float data){
    glUniform1f(glGetUniformLocation(this->programID,name.c_str()), data);
}
string Shader::readFile(string name){
    string code = "";
    string line;
    ifstream file (name);
    vector<string> lines;

  
    if (file.is_open()){
        while ( getline (file,line) ){
            code.append(line);
            code.push_back('\n');
        }
        code.push_back('\0');
        //std::cout <<"Shader-Code:" << std::endl;
        //std::cout << code << std::endl;
        file.close();
    }else{
        cout << "Unable to open file: " << name << std::endl;
    }
    return code;
}