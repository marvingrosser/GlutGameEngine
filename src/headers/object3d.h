/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   object3d.h
 * Author: marvin
 *
 * Created on December 24, 2020, 11:29 PM
 */
#include "Vector.h"
#include "Face.h"
#include "Shader.h"
#include "mat4.h"
#include <vector>
#include <string>
#include <fstream>
#include <glm/glm.hpp>
#include <GL/glut.h>
#include "texture.h"
#include "../headers/Vector.h"
#include <iostream>
using namespace std;
using std::endl;
using std::string;
using std::vector;
#ifndef OBJECT3D_H
#define OBJECT3D_H
class object3d {
public:
    object3d();
    
    object3d(vector<Face> faces);
    object3d(string name);
    object3d(string name, string textureName );
    
    void addFace(Face newface);
    
    void readObj(string name);
    void render();
    GLuint getShader();
private:
    void init();
    /**
     * Counts the needed Sizes of Vertexes, TextureCoords, Normals and Faces
     * @param name of file 
     * @return counter as Array like (vertexnumber, normalnumber, facenumber, texturecoordsnumber)
     */
    unsigned int * countinstances(string name);
    /**
     * loads a wavefront vector to Vector
     * @param line wavefront vertice string 
     * @param vectors array to read in Vectors
     */
    void loadVectorFromString(string &line, vector<Vector> &vectors, float *datapointer);
    /**
     * loads a Face to array faces
     * @param line wavefront string
     * @param faces facesarray
     * @param vertices read in vertices
     * @param normals  read in normals
     */
    void loadFaceFromString(string &line, vector<Face> &faces, vector<Vector> &vertices, vector<Vector> &normals, unsigned int * vertexdata);
    /**
     * loads a Face with 3 vertices into faces array
     * @param line
     * @param faces
     * @param vertices
     * @param normals
     */
    void loadFace3FromString(string &line, vector<Face> &faces, vector<Vector> &vertices, vector<Vector> &normals, unsigned int * vertexdata);
    /**
     * loads a Face with 4 vertices into faces array
     * @param line
     * @param faces
     * @param vertices
     * @param normals
     */
    void loadFace4FromString(string &line, vector<Face> &faces, vector<Vector> &vertices, vector<Vector> &normals, unsigned int * vertexdata);
    /**
     * Counts the occurences of c in str
     * @param c
     * @param str
     * @return 
     */
    int countOccurences(char c, string &str);
    
    void loadTextureCoordFromString(string &line);
    /**
     * Assigns Texturecoords to facepointer
     * @param coord index of Texturecoord in db (textureCoord [vector<vector<double>>])
     * @param face pointer to face
     */
    void assignTextureCoords(int coord_X, int coord_Y, int coord_Z, Face * face);
    
    int getTextureCoordFromString(string &substring);
    
    void setModelMatrix(mat4 model);
    void setModelMatrix(double model[16]);
    glm::mat4 getModelMatrixGLM();
    
    mat4 getModelMatrix();
    
    mat4 modelmatrix;
    Shader shader;
    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;
    unsigned int * counts;
    float *vertexdata;
    unsigned int *facedata;
    float *texturecoordsdata;
    //vector<Face> faces; //weil momentan unnütz
    vector<Vector> vertices;
    //vector<vector<double>> textureCoord; //texturing will get better
    GLuint *textureId;
    
};

#endif /* OBJECT3D_H */

