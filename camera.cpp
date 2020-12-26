//hier entsteht die camera Klasse
#include <cstdlib>
#include <stdlib.h>
#include <iostream>

#include <GL/glut.h>

#include <fstream>

#include <string>

#include <math.h>



#include "camera.h"


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




camera::camera(vector startPos){
        this->position = startPos;
    };
    

        float camera::getRendertexture(){
            return 0.0;
        }
    

        vector camera::getPosition(){
        return this->position;
    };
    

    void camera::setPosition(vector newPos){
        this->position = newPos;
    };
    

        mat4 camera::getViewmatrix(){
        return this->viewmatrix;
    };
    

        void camera::setnewviewmatrix(mat4 relativeviewmat){
        this->viewmatrix= relativeviewmat;
    };
    

    

//Cameraclass

