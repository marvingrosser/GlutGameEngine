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

#include "player.h"
#include <GL/glut.h>
#include<iostream>
using namespace std;
using std::cout;
using std::endl;
#include <math.h>

player::player(int width, int height, double sensitivity, double speed) {
    this->height = height;
    this->width = width;
    this->sens = sensitivity;
    this->speed=speed;
    setPosition(0,0,0);
    //this->mspeed=1.0f;
}
player::player(){
    this->height = 600;
    this->width = 800;
    this->sens = 1.0;
    this->speed=0.05;
    setPosition(0,0,0);
}
void player::setPosition(double x, double y, double z){
    position.set(x,y,z);
}

vertice player::getPosition(){
    return position;
}

double player::getRealHeight(){
    return 1.0;
}

void player::renderMouseKeyboard(){
    
    vertice CNORM = vertice();
    vertice Rvec = vertice();

    Rvec.set(- sin(x_mouse), sin(y_mouse), - cos(x_mouse)); //mausbewegung in bewegung der Camera umrechnen siehe Vektorrechnung
    
    LOOK.set(position.getX() + Rvec.getX() , position.getY() + Rvec.getY(), position.getZ() + Rvec.getZ()); 

    if(movefb==1.0f){
        //position.set(position.getX() + Rvec.getX() *speed, 1 + sin(movecount) * 0.07, position.getZ() + Rvec.getZ() *speed);
        //movecount += 0.0063f; 
        position.setX(position.getX()+Rvec.getX() *speed);
        position.setZ(position.getZ() + Rvec.getZ() *speed);
        

        
        
    }else if (movefb==-1.0f){
        //position.set(position.getX() - Rvec.getX() *speed, 1 + sin(movecount) * 0.07, position.getZ() - Rvec.getZ() *speed);
        //movecount += 0.0043f;
        position.setX(position.getX()-Rvec.getX() *speed);
        position.setZ(position.getZ() - Rvec.getZ() *speed);
       
        
        
    }
    if (moverl==1.0f){
        //position.set(position.getX() - Rvec.getZ() *speed, 1 + sin(movecount) * 0.07, position.getZ() + Rvec.getX() *speed);
        //movecount += 0.0043f;
        position.setX(position.getX() - Rvec.getZ() *speed);
        position.setZ(position.getZ() + Rvec.getX() *speed);
        
    }
    else if(moverl==-1.0f){
        //position.set(position.getX() + Rvec.getZ() *speed, 1 + sin(movecount) * 0.07, position.getZ() - Rvec.getX() *speed);
        //movecount += 0.0043f;
        position.setX(position.getX() + Rvec.getZ() *speed);
        position.setZ(position.getZ() - Rvec.getX() *speed);
        
    }

    CNORM.set(0.0, 1.0, 0.0);
    position.setY(getRealHeight());

    //cout << '('<< LOOK.x<<',' << LOOK.y<< ','<< LOOK.z << ')' <<'\n';
    gluLookAt(position.getX(), position.getY(), position.getZ(), LOOK.getX(), LOOK.getY(), LOOK.getZ(), CNORM.getX(), CNORM.getY(), CNORM.getZ()); //Camera schaut jetzt zu diesem Punkt

}
void player::mouse(int x, int y){
    int cx = width/2; //nimmt die Mauseingaben und formatiert sie auf das Fenster um
    int cy = height/2;

    //hindert kamera am überdrehen und "flippen"
    if (y_mouse>=0.9){
        y_mouse=0.9;
    }
    if (y_mouse<=-0.9){
        y_mouse=-0.9;
    }

    if(x!=cx || y!=cy){
        x_mouse += (cx - x) * sens;
        y_mouse += (cy - y) * sens;

    cout << x_mouse <<' ' << y_mouse << endl; //print mauseingaben
    
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
        }
}
void player::keyboard(unsigned char Key, int x, int y){

    switch(Key){ //setzt für jedenen Key von wasd der gedrückt wird eine Richtungsvariable
        case 'w': movefb=1.0f;break;

        case 's': movefb=-1.0f;break;

        case 'a': moverl=-1.0f;break;

        case 'd': moverl=1.0f;break;

        //spiel schließt bei "esc"
        case 27: exit(0);
    }


}
void player::reshape(int w, int h) //wird bei windowresize aufgerufen
{
    glViewport (0, 0, w, h);
    //width = w;
    //height = h;
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(45.0f, (float)w/(float)h,1, 1000);
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity ();


}