/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   player.cpp
 * Author: marvin
 * 
 * Created on December 28, 2020, 9:59 AM
 */

#include "../headers/player.h"

using namespace std;
using std::cout;
using std::endl;
void player::render(GLuint shaderId){
    this->cam.render(shaderId);
};
player::player(int width, int height, double sensitivity, double walk_sens){
    this->cam = * new camera(width, height);
    this->cam.setPosition(*new Vector(0.0f,0.0f,-1.0f));
    this->width = width;
    this->height= height;
    this->sens = sensitivity;
    this->walk_sens = walk_sens;

}
player::player(){
    this->cam = * new camera(800,600);
    this->width = 800;
    this->height= 600;
    this->sens = 0.002;
    this->walk_sens = 0.2;
    this->cam.setPosition(*new Vector(0.0f,0.0f,-1.0f));
}
void player::setPosition(float x, float y, float z){
    this->cam.setPosition(*new Vector(x,y,z));
}
void player::renderMouseKeyboard(){
    
    Vector CNORM = Vector();
    
    Vector Rvec = Vector(- sin(x_mouse), sin(y_mouse),  -cos(x_mouse));
    
    CNORM.set(0.0, 1.0, 0.0);
        
    //Rvec.set(); //mausbewegung in bewegung der Camera umrechnen siehe Vektorrechnung
    //cout << Rvec.to_string()<< endl;
    
    this->calculateKeyboardmovement(&Rvec);
    
    this->calculateCamMovement(&Rvec, &CNORM);
    
}
void player::mouse(int x, int y){
    int cx = width/2; //nimmt die Mauseingaben und formatiert sie auf das Fenster um
    int cy = height/2;
    if(x!=cx || y!=cy){
        x_mouse += (cx - x) * sens;
        y_mouse += (cy - y) * sens;
    //cout << x_mouse <<' ' << y_mouse << endl; //print mauseingaben
    
        glutWarpPointer(cx, cy);
    }
   // render();
}
void player::releaseKey(unsigned char key, int x, int y) {

        switch (key) {//wenn wasd Key losgelassen: jeweilige laufrichtungsvar wird genullt
             case 'w' :
             case 's': movefb = 0.0f;break;

             case 'a':
             case 'd' : moverl=0.0f;break;
             case 'q': exit(1);
        }
}
void player::keyboard(unsigned char Key, int x, int y){

    switch(Key){ //setzt für jedenen Key von wasd der gedrückt wird eine Richtungsvariable
        case 'w': movefb=1.0f;break;

        case 's': movefb=-1.0f;break;

        case 'a': moverl=-1.0f;break;

        case 'd': moverl=1.0f;break;
    }


}
void player::reshape(int w, int h) //wird bei windowresize aufgerufen
{
    glViewport (0, 0, w, h);
    //width = w;
    //height = h;
    /*glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(55.0f, (float)w/(float)h , 0.1, 1000);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity ();*/


}

void player::calculateKeyboardmovement(Vector* direction){

    if(movefb==1.0f){
        this->cam.setPosition(this->cam.getPosition().getX() + direction->getX() * walk_sens,
                    this->cam.getPosition().getY() +  direction->getY()*walk_sens ,
                    this->cam.getPosition().getZ() + direction->getZ() * walk_sens);
        movecount += 0.063f;
        
    }else if (movefb==-1.0f){
        this->cam.setPosition(this->cam.getPosition().getX() - direction->getX() * walk_sens,
                    this->cam.getPosition().getY() + sin(movecount)*0.1 ,
                    this->cam.getPosition().getZ() - direction->getZ() * walk_sens);
        movecount += 0.043f;
        
    }
    if (moverl==1.0f){
        this->cam.setPosition(this->cam.getPosition().getX() - direction->getZ() * walk_sens,
                    this->cam.getPosition().getY() + sin(movecount)*0.1 ,
                    this->cam.getPosition().getZ() + direction->getX() * walk_sens);
        movecount += 0.043f;
    }
    else if(moverl==-1.0f){
        this->cam.setPosition(this->cam.getPosition().getX() + direction->getZ() * walk_sens,
                    this->cam.getPosition().getY() + sin(movecount)*0.1 ,
                    this->cam.getPosition().getZ() - direction->getX() * walk_sens);
        movecount += 0.043f;
    }
};

void player::calculateCamMovement(Vector* direction, Vector * CNORM){
    this->cam.setDirection(this->cam.getPosition().getX() + direction->getX() ,
                            this->cam.getPosition().getY() + direction->getY(),
                            this->cam.getPosition().getZ() + direction->getZ()); 
    this->cam.setViewMatrix(glm::lookAt(this->cam.getPosition().get(),
                            this->cam.getDirection().get(), 
                            CNORM->get()));

};