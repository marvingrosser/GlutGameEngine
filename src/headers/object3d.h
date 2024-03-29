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
#include <algorithm>
using namespace std;
using std::endl;
using std::string;
using std::vector;
#ifndef OBJECT3D_H
#define OBJECT3D_H
struct TexCoord{
    float x;
    float y;
};

struct LinearVertice{
    int vertIndex;
    int texCoordIndex;
    int normalIndex;
    int newLinearIndex;
}; 
class object3d {
public:
    object3d();
    
    object3d(vector<Face> faces);
    object3d(string name, string textureName ,Shader * shader); 
    /**
     * Translates the object from LOCATION to LOCATION + vec
     * @param vec amount to translate
     */
    void translate(Vector vec);
    void addFace(Face newface);
    
    void readObj(string name);
    void render();
    GLuint getShader();
    /**
     * Sets Transformationmatrix for Model (mat4)
     * @param model transformation matrix 
     */
    void setModelMatrix(mat4 model);
    /**
     * Sets Transformationmatrix for Model (double[16])
     * @param model transformation matrix 
     */
    void setModelMatrix(double model[16]);
    /**
     * 
     * @return Transformation Matrix for this Model (glm::mat4)
     */
    glm::mat4 getModelMatrixGLM();
     /**
     * 
     * @return Transformation Matrix for this Model (mat4)
     */
    mat4 getModelMatrix();
private:
    void init(Shader * shader);
    /**
     * fills the Face-Index data of the EBO with the new calculated Indeces 
     * @param faces
     * @param combinations new calculated indeces
     */
    void fillFaceIndexData(vector<LinearVertice> faces, vector<LinearVertice> combinations);
    /**
     * fills the VertexData Array with Vertices,Normals, TextureCoords with the Unique Combinations Indeces
     * @param vertices  
     * @param normals
     * @param textureCoords
     * @param combinations
     */
    void fillVertexData(vector<Vector> vertices, vector<Vector> normals, vector<TexCoord> textureCoords, vector<LinearVertice> combinations);
    /**
     * Reads in the Vertex/Face index Data
     * @param name
     * @return 
     */
    vector<LinearVertice> getFaceIndecesFromOBJ(string name);
    /**
     * Linearizes the Combination Vertex data for sending it to the Graphics card
     * @param combinations The Combinations 
     * @return every LinearVertice has now an not empty newLinearIndex
     */
    vector<LinearVertice> linearizeIndeces(vector<LinearVertice> combinations);
    /**
     * Checks if a vector of LinearVertice contains certain combinations already
     * @param combinations 
     * @param newCombi
     * @return 
     */
    bool hasCombination(vector<LinearVertice> combinations, LinearVertice newCombi );
    /**
     * Reads Vertice-String (obj) to Vector Object
     * @param line String containing the Vertice-Data
     * @return Vector-Object
     */
    Vector getVerticeFromString(string line);
    /**
     * Reads single Texturecoord from Line
     * @param substring String with wavefront texture-coords-data
     * @return texture-Coord as Int
     */
    TexCoord getTextureCoordFromString(string line);
    /**
     * Reads Vector-Type data from OBJ-File
     * @param name obj-file
     * @param attribute 
     * @return 
     */
    vector<Vector> getVectorObjectFromOBJ(string name, string attribute);
    /**
     * Reads all Vertices from OBJ-File in Array
     * @param name the obj-file
     * @return Vertices as vector-Array
     */
    vector<Vector> getVerticesFromOBJ(string name);
    /**
     * Reads all Normals from OBJ-File in Array
     * @param name the obj-file
     * @return Normals as vector-Array
     */
    vector<Vector> getNormalsFromOBJ(string name);
    
    /**
     * Reads all Texture-Coords from OBJ-File in Array
     * @param name the obj-file
     * @return Texture Coords as vector-Array
     */
    vector<TexCoord> getTextureCoordsFromOBJ(string name);
    /**
     * Reads all Vertice-Normal-Texcoord-Indeces-Combinations from OBJ-File in Array
     * @param name the obj-file
     * @return Array of 3 Indeces per unique Vertice-Normal-Texcoord-Index-Combination
     */
    vector<LinearVertice> getVerticeCombinationsFromOBJ(string name);
    /**
     * Reads OBJ-File-Data and returns all lines with the given Attribute at the beginning
     * @param name the obj-file
     * @param attribute the needed Attribute
     * @return all Lines with the Attribute
     */
    vector<string> getLinesWithAttributeFromOBJ(string name,string attribute);

    /**
     * reads Wavefront face data e.g. f 1/2/1 2/2/1 3/4/1
     * @param line
     */
    vector<LinearVertice> getFace3FromString(string line);
    /**
     * reads Wavefront face data e.g. f 1/2/1 2/2/1 3/4/1 5/6/1
     * @param line
     * 
     */
    vector<LinearVertice> getFace4FromString(string line);
    /**
     * Reads FaceIndexData from OBJ (dont care about Face3 or Face4)
     * @param line 
     * @return 
     */
    vector<LinearVertice> getFaceFromString(string line);

    /**
     * Counts the occurences of c in str
     * @param c
     * @param str
     * @return 
     */
    int countOccurences(char c, string &str);

    
    
    
    mat4 modelmatrix;
    Shader * shader;
    unsigned int VBO;
    unsigned int VAO;
    unsigned int EBO;
    unsigned int vertexDataSize;
    unsigned int faceDataSize;
    float *vertexdata;
    unsigned int *facedata;
    //vector<Face> faces; //weil momentan unnütz
    //vector<vector<double>> textureCoord; //texturing will get better
    Texture diffuse;
    Texture specular;
    Texture normal;
    
};

#endif /* OBJECT3D_H */

