/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   object3d.cpp
 * Author: marvin
 * 
 * Created on December 24, 2020, 11:29 PM
 */

#include "object3d.h"
#include "vertice.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using std::string;
using std::endl;
using std::vector;

object3d::object3d() {};

object3d::object3d(vector<face> faces){
    this->faces = faces;
};

void object3d::addFace(face newface){
    this->faces.push_back(newface);
};

void object3d::readObj(string name){
  string line;
  ifstream myfile (name);

  if (myfile.is_open())
  {
      vector<vertice> vertices;
      vector<face> faces;
      vector<vertice> normals;

    while ( getline (myfile,line) )
    {


        if(line.substr(0,line.rfind(' ', 3))=="v"){


            int l3 = line.rfind(' ');
            int l2 = line.rfind(' ', l3-1);
            int l1 = line.rfind(' ', l2-1);

            float x = std::stof(line.substr(l1+1,l2-l1-1)) ;
            float y = std::stof(line.substr(l2+1, l3-l2-1));
            float z = std::stof(line.substr(l3+1, -1));


            vertice punkt = vertice(x,y,z);

            vertices.push_back(punkt);

        }else if(line.substr(0, line.rfind(' ',3))=="vn"){
            int l3 = line.rfind(' ');
            int l2 = line.rfind(' ', l3-1);
            int l1 = line.rfind(' ', l2-1);

            float x = std::stof(line.substr(l1+1,l2-l1-1)) ;
            float y = std::stof(line.substr(l2+1, l3-l2-1));
            float z = std::stof(line.substr(l3+1, -1));


            vertice normal = vertice(x,y,z);
            normals.push_back(normal);
        }else if (line.substr(0, line.rfind(' ',3))=="f"){
            face newface;
            int l3 = line.rfind(' ', line.rfind(' '));
            int l2 = line.rfind(' ', l3 - 1);
            int l1 = line.rfind(' ', l2 - 1);

            string one = line.substr(l1 + 1, l2 - l1 - 1);
            string two = line.substr(l2 + 1, l3 - l2 - 1);
            string three = line.substr(l3+1, -1);

            newface.setX(vertices[std::stoi(one.substr(0,one.rfind("//")))-1]);
            newface.setY(vertices[std::stoi(two.substr(0,two.rfind("//")))-1]);
            newface.setZ(vertices[std::stoi(three.substr(0,three.rfind("//")))-1]);
            newface.setNormal(normals[std::stoi(one.substr(one.rfind("//") + 2, -1)) - 1]);

            faces.push_back(newface);

        }

    }
    myfile.close();






      this->faces = faces;
      }

  else{
      cout << "Unable to open file";
  } 
  

};

object3d::object3d(string name){
    this->readObj(name);
}

object3d object3d::getFaces(){
    return this->faces;
}

void object3d::render(){
    
    glBegin(GL_TRIANGLES);
    for(auto face: this->faces){
        
        glNormal3f(face.getNormal().getX(),
                    face.getNormal().getY(), 
                    face.getNormal().getZ()); //Normal und die 3 punkte laden
        
        glVertex3f(face.getX().getX(), face.getX().getY(), face.getX().getZ());
        glVertex3f(face.getY().getX(), face.getY().getY(), face.getY().getZ());
        glVertex3f(face.getZ().getX(), face.getZ().getY(), face.getZ().getZ());
        const GLfloat mat[] = {0 , 1, 1, 1} ;
        glMaterialfv( GL_FRONT,GL_DIFFUSE,mat); //material bestimmen
    }
    glEnd();        
}