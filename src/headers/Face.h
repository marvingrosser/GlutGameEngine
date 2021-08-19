/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Face.h
 * Author: marvin
 *
 * Created on December 24, 2020, 11:31 PM
 */

#ifndef FACE_H
#define FACE_H
#include "Vector.h"
#include <string>
#include <glm/glm.hpp>
#include <vector>
using std::string;
class Face {
    
public:
    Face();
    
    Face(Vector * x, Vector * y, Vector * z, Vector normal);

    

    
    Vector * getX();
    
    Vector * getY();
    
    Vector * getZ();
    

    
    Vector * getNormal();
    
    /**
     * sets faces normal
     * @param normal
     */
    void setNormal(Vector normal);
    
    /**
     * sets x - vertice
     * @param x vertice
     */
    void setX(Vector * x);
    
    /**
     * sets y - vertice
     * @param y vertice
     */
    void setY(Vector *y);
    
    /**
     * sets z - vertice
     * @param z vertice
     */
    void setZ(Vector * z);

    /**
     * Sets the Vector Parameters
     * @param x vertice one
     * @param y vertice two
     * @param z vertice tree
     * @param normal of the face
     */
    void set(Vector * x, Vector * y, Vector * z, Vector  normal);
    void init();
    void setTextureCoord_X(std::vector<double> & X_texturecoord);
    void setTextureCoord_Y(std::vector<double> & Y_texturecoord);
    void setTextureCoord_Z(std::vector<double> & Z_texturecoord);
    
    std::vector<double> * getTextureCoord_X();
    std::vector<double> * getTextureCoord_Y();
    std::vector<double> * getTextureCoord_Z();
    /**
     * calculates the area of the face
     * @return area
     */
    virtual double area();
    /**
     * renders the component Face
     */
    virtual void render();
    /**
     * Converts it to string
     * @return 
     */
    virtual string to_string();
    
    
    
protected:
    void setRenderTextureCoordinates(std::vector<double> * coord);
    
    double calculateTriangleArea(Vector ab ,Vector ac);
    
    Vector * X;
    
    Vector * Y;
    
    Vector * Z;
    
    Vector normal;

    std::vector<double> * X_texturecoord = nullptr;
    
    std::vector<double> * Y_texturecoord = nullptr;
    
    std::vector<double> * Z_texturecoord = nullptr;
    
    unsigned int vbo;
};

#endif /* FACE_H */

