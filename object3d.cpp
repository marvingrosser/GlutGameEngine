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

double det3(double mat[3][3]){ //noch verkürzbar da 0
    return mat[0][0]*mat[1][1]*mat[2][2]+mat[0][1]*mat[1][2]*mat[2][0]+mat[0][2]*mat[1][0]*mat[2][1]-mat[0][2]*mat[1][1]*mat[2][0]-mat[0][1]*mat[1][0]*mat[2][2]-mat[0][0]*mat[1][2]*mat[2][1];
}

double det2(double mat[2][2]){
    return mat[0][0]*mat[1][1]-mat[0][1]*mat[1][0];

}

vertice vectorMult(double mat[3][3],double v[3]){
    vertice b;
    b.set(mat[0][0]*v[0]+mat[0][1]*v[1]+mat[0][2]*v[2],mat[1][0]*v[0]+mat[1][1]*v[1]+mat[1][2]*v[2],mat[2][0]*v[0]+mat[2][1]*v[1]+mat[2][2]*v[2]);
    return b;
}


bool object3d::playerInTriangle (vertice edges[3],vertice playerPosition){ //getter für höhe in dieser klasse?
    //Ax=b
    double b[3];
    b[0]=playerPosition.getX()-edges[0].getX();
    b[1]=playerPosition.getY()-edges[0].getY();
    b[2]=playerPosition.getZ()-edges[0].getZ();

    double A[3][3];
    A[0][0]=edges[1].getX()-edges[0].getX();
    A[1][0]=edges[1].getY()-edges[0].getY();
    A[2][0]=edges[1].getZ()-edges[0].getZ();
    A[0][1]=edges[2].getX()-edges[0].getX();
    A[1][1]=edges[2].getY()-edges[0].getY();
    A[2][1]=edges[2].getZ()-edges[0].getZ();
    A[0][2]=0;
    A[1][2]=1;
    A[2][2]=0;

    double d=det3(A);

    double invA[3][3]; 
    if (d!=0){ 
        invA[0][0]=(1/d)*(A[1][1]*A[2][2]-A[1][2]*A[2][1]);
        invA[0][1]=(1/d)*(A[0][2]*A[2][1]-A[0][1]*A[2][2]);
        invA[0][2]=(1/d)*(A[0][1]*A[1][2]-A[1][1]*A[0][2]);

        invA[1][0]=(1/d)*(A[1][2]*A[2][0]-A[2][2]*A[1][0]);
        invA[1][1]=(1/d)*(A[0][0]*A[2][2]-A[2][0]*A[0][2]);
        invA[1][2]=(1/d)*(A[0][2]*A[1][0]-A[1][2]*A[0][0]);

        invA[2][0]=(1/d)*(A[1][0]*A[2][1]-A[2][0]*A[1][1]);
        invA[2][1]=(1/d)*(A[0][1]*A[2][0]-A[0][0]*A[2][1]);
        invA[2][2]=(1/d)*(A[0][0]*A[1][1]-A[1][0]*A[0][1]);
    }

    vertice s=vectorMult(invA,b); //Lösungsvektor
    if (s.getX()<=1.2 && s.getX()>=-0.2 && s.getY()<=1.2 && s.getY()>=-0.2){//vielleicht anpassen
        playerHeight=edges[0].getY()+(edges[1].getY()-edges[0].getY())*s.getX()+(edges[2].getY()-edges[0].getY())*s.getY();
        return true;
    }
    else{ 
        return false;
    }


}

double object3d::getPlayerHeight(){
    return playerHeight;

}

void object3d::render(vertice playerPosition){
    vertice edges[3];
    glBegin(GL_TRIANGLES);
    for(auto face: this->faces){
        
        glNormal3f(face.getNormal().getX(),
                    face.getNormal().getY(), 
                    face.getNormal().getZ()); //Normal und die 3 punkte laden
        
        glVertex3f(face.getX().getX(), face.getX().getY(), face.getX().getZ());
        glVertex3f(face.getY().getX(), face.getY().getY(), face.getY().getZ());
        glVertex3f(face.getZ().getX(), face.getZ().getY(), face.getZ().getZ());

        
        edges[0].set(face.getX().getX(),face.getX().getY(),face.getX().getZ());
        edges[1].set(face.getY().getX(),face.getY().getY(),face.getY().getZ());
        edges[2].set(face.getZ().getX(),face.getZ().getY(),face.getZ().getZ());

        if (playerInTriangle(edges,playerPosition)){
            //cout<<"spieler gefunden"<<endl;
        }

        const GLfloat mat[] = {0 , 1, 1, 1} ;
        glMaterialfv( GL_FRONT,GL_DIFFUSE,mat); //material bestimmen
    }
    glEnd();        
}