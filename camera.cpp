//hier entsteht die camera Klasse
#include <cstdlib>
#include <stdlib.h>
#include <iostream>

#include <GL/glut.h>

#include <fstream>

#include <string>

#include <math.h>

#include <vector>

#include "camera.h"

using std::vector;
using namespace std;
using std::cout;
using std::endl;
using std::string;


struct matrix4{
    float get[16];
};

struct POINT //3D Punkt
{
    float x;
    float y;
    float z;

};

class camera {
    private: 
        POINT position;
    private: 
        matrix4 viewmatrix;
    
    public: 
        camera(POINT startPos){
        this->position = startPos;
    }
    
    public: 
        float getRendertexture();
    
    public: 
        POINT getPosition(){
        return this->position;
    }
    
    public: 
        void setPosition(POINT newPos){
        this->position = newPos;
    }
    
    public: 
        matrix4 getViewmatrix(){
        return this->viewmatrix;
    }
    
    public: 
        void setnewviewmatrix(matrix4 relativeviewmat){
        this->viewmatrix= relativeviewmat;
    }
    
};
//Cameraclass

