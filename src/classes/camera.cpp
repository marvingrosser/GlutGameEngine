//hier entsteht die camera Klasse
#include <cstdlib>
#include <stdlib.h>
#include <iostream>

#include <GL/glut.h>

#include <fstream>

#include <string>

#include <math.h>


#include "../headers/camera.h"


using namespace std;
using std::cout;
using std::endl;
using std::string;

void camera::setDirection(float x, float y, float z){
    this->direction.set(x,y,z);
};
void camera::setPosition(float x, float y, float z){
    this->position.set(x,y,z);
};
void camera::setDirection(Vector newDir){
    this->direction = newDir;
};

Vector camera::getDirection(){
    return this->direction;
};
void camera::render(Shader *shader){
    shader->setMatrix("projection", this->projectionmatrix.getPtr());
    shader->setMatrix("view", this->viewmatrix.getPtr());
    

};
camera::camera(Vector startPos, int width, int height){
    this->init(startPos, width, height, 45.0f,*new Vector(0.0f,1.0f,0.0f));
};
camera::camera(int width, int height){
    this->init(*new Vector(), width, height, 45.0f, *new Vector(0.0f,1.0f,0.0f));
};
void camera::init(Vector pos, int width, int height, float fov, Vector direction){
    this->height = height;
    this->width = width;
    this->position = pos;
    this->direction = direction;
    this->projectionmatrix=* new mat4();
    this->projectionmatrix.set(glm::perspective(glm::radians(fov),(float)width/(float)height, 0.01f, 1000.0f));
    this->viewmatrix = * new mat4();
    this->viewmatrix.translate(glm::vec3(0.0f,0.0f,-1.0f));
}

camera::camera(){
    this->init(* new Vector(), 800, 600, 45.0f,*new Vector(0.0f,1.0f,0.0f));
};



mat4 camera::getProjectionMatrix(){
    return this->projectionmatrix;
};

glm::mat4 camera::getProjectionMatrixGLM(){
    return this->projectionmatrix.get();
};
void camera::setViewMatrix(glm::mat4 viewmat){
    this->viewmatrix.set(viewmat);
};  

glm::mat4 camera::getViewmatrixGLM(){
    return this->viewmatrix.get();
};
void camera::setProjectionMatrix(mat4 projectmat){
    this->projectionmatrix = projectmat;
};

void camera::setProjectionMatrix(glm::mat4 projectmat){
    this->projectionmatrix.set(projectmat);
};
camera::camera(Vector startPos){
    this->init(startPos, 800, 600, 45.0f,*new Vector(0.0f,1.0f,0.0f));
    };
    

        float camera::getRendertexture(){
            return 0.0;
            
        }
    

        Vector camera::getPosition(){
        return this->position;
    };
    

    void camera::setPosition(Vector newPos){
        this->position = newPos;
    };
    

        mat4 camera::getViewmatrix(){
        return this->viewmatrix;
    };
    

        void camera::setViewMatrix(mat4 relativeviewmat){
        this->viewmatrix= relativeviewmat;
    };
    

    

//Cameraclass

