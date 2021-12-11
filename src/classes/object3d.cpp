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

#include "../headers/object3d.h"


using std::string;
using std::endl;
using std::vector;

void object3d::setModelMatrix(double model[]){
    modelmatrix=*new mat4(model);
}
void object3d::setModelMatrix(mat4 model){
    modelmatrix =* new mat4(model);
    
};
glm::mat4 object3d::getModelMatrixGLM(){
    return this->modelmatrix.get();
};

mat4 object3d::getModelMatrix(){
    return this->modelmatrix;
};
object3d::object3d() {};

object3d::object3d(vector<Face> faces){
    //this->faces = faces;

};

void object3d::addFace(Face newface){
    //this->faces.push_back(newface);
};


void object3d::readObj(string name){
  
    vector<Vector> vertices = object3d::getVerticesFromOBJ(name);
    vector<Vector> normals = object3d::getNormalsFromOBJ(name);
    vector<TexCoord> textureCoords = object3d::getTextureCoordsFromOBJ(name);
    vector<LinearVertice> verticeCombinations = object3d::getVerticeCombinationsFromOBJ(name);
    vector<LinearVertice> faceIndeces = object3d::getFaceIndecesFromOBJ(name);
    vector<Vector> tangent_bitangent = object3d::calculate_tangent_bitangent(faceIndeces, verticeCombinations, normals, vertices, textureCoords);
    
    for(Vector vec:vertices){
        std::cout << "vertices:" << std::endl;
        std::cout << vec.to_string() << std::endl;
    }
    for(Vector norm:normals){
        std::cout << "normals:" << std::endl;
        std::cout << norm.to_string() << std::endl;
    }
    for(TexCoord t:textureCoords){
        std::cout << "TexCoords:" << std::endl;
        std::cout << t.x << ", "<< t.y << std::endl;
    }
    for(LinearVertice lin:verticeCombinations){
        std::cout << "Combinations:" << std::endl;
        std::cout << lin.vertIndex << " / " << lin.normalIndex << " / " << lin.texCoordIndex << " -:- " << lin.newLinearIndex<< std::endl;
    }
    for(LinearVertice lin:faceIndeces){
        std::cout << "face:" << std::endl;
        std::cout << lin.vertIndex << " / " << lin.normalIndex << " / " << lin.texCoordIndex << " -:- " << lin.newLinearIndex<< std::endl;
    }
    for(int i = 0; i< tangent_bitangent.size(); i=i+2){
        Vector tangents[2] = {tangent_bitangent.at(i),tangent_bitangent.at(i+1)};
        std::cout << "Tangent: \t"<< tangents[0].to_string()<< std::endl;
        std::cout << "Bitangent: \t"<< tangents[1].to_string()<< std::endl;
    }
    
    

    this->fillVertexData(vertices,normals, textureCoords, verticeCombinations, tangent_bitangent);
    this->fillFaceIndexData(faceIndeces, verticeCombinations);
    std::cout << "vertexdata:" << std::endl;
    for(int i=0; i < this->vertexDataSize; i++){
        std::cout << this->vertexdata[i] << std::endl;
    }
    std::cout << "facedata:" << std::endl;
    for(int i=0; i < this->faceDataSize; i++){
        std::cout << this->facedata[i] << std::endl;
    }
    std::cout << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
    std::cout << glGetString(GL_RENDERER) << std::endl;
    std::cout << glGetString(GL_VERSION) << std::endl;
    std::cout << "Number Verts:\t\t"<< vertices.size()<< std::endl;
    std::cout << "Number Normals:\t\t"<< normals.size()<< std::endl;
    std::cout << "Number Faces:\t\t"<< faceIndeces.size()<< std::endl;
    std::cout << "Number TextureCoords:\t\t"<< textureCoords.size()<< std::endl;
    std::cout << "Number Unique Vertex-Normal-TexCoord Combinations:\t"<<  this->vertexDataSize/8 << std::endl; 
};

void object3d::createVertexAttributesBuffers(){

    //position
    glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 14 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    
    //normal
    glVertexAttribPointer(1,3, GL_FLOAT, GL_FALSE, 14 * sizeof(float), (void*)(3* sizeof(float)));
    glEnableVertexAttribArray(1);
    
    //texture coords
    glVertexAttribPointer(2,2, GL_FLOAT, GL_FALSE, 14 * sizeof(float), (void*)(6* sizeof(float)));
    glEnableVertexAttribArray(2);
    
    //tangent
    glVertexAttribPointer(3,3, GL_FLOAT, GL_FALSE, 14 * sizeof(float), (void*)(8* sizeof(float)));
    glEnableVertexAttribArray(3);
    
    //bitangent
    glVertexAttribPointer(4,3, GL_FLOAT, GL_FALSE, 14 * sizeof(float), (void*)(11* sizeof(float)));
    glEnableVertexAttribArray(4);
    
    glBindBuffer(GL_ARRAY_BUFFER,0);
    
}

void object3d::fillVertexBuffer(){
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER, this->vertexDataSize * sizeof(float) * 14, this->vertexdata, GL_STATIC_DRAW);
}

void object3d::fillElementBuffer(){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->faceDataSize * sizeof(unsigned int), this->facedata, GL_STATIC_DRAW);
}
void object3d::linkTexturesToShader(){
    this->shader->setInt("diffusemap",  0);
    this->shader->setInt("specularmap", 1);
    this->shader->setInt("normalmap",   2);
    this->shader->setInt("heightmap",   3);
}

void object3d::generateBuffersAndVAO(){
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1,      &VBO);
    glGenBuffers(1,      &EBO);
}

void object3d::init(Shader * shader){
    
    //init shader
    this->shader = shader;
    this->shader->use();
    
    //create modelmatrix
    this->modelmatrix = * new mat4();
    
    //link modelmatrix to shader
    this->shader->setMatrix("model", this->modelmatrix.getPtr());
        
    this->generateBuffersAndVAO();
        
    this->linkTexturesToShader();
    
    //fill buffers  
        glBindVertexArray(VAO);
        this->fillVertexBuffer();
        this->fillElementBuffer();
    
    //segment the vertexdata
    this->createVertexAttributesBuffers();
    
    
    glBindVertexArray(0);
    
 
    
};

void object3d::loadTextures(string textureName){
    this->diffuse = * new Texture(textureName+"diffuse.bmp",0);
    this->specular = * new Texture(textureName+"specular.bmp",1);
    this->normal = * new Texture(textureName+"normal.bmp",2);
    this->height = * new Texture(textureName+"height.bmp",3);
}

object3d::object3d(string name, string textureName,Shader * shader){
    this->readObj(name);
    

    this->loadTextures(textureName);
    
    
    glEnable(GL_TEXTURE_2D);
    this->init(shader);
    
}

GLuint object3d::getShader(){
    return this->shader->getID();
};
void object3d::bindTextures(){
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, this->diffuse.getID());
    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, this->specular.getID());
    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, this->normal.getID());
    glActiveTexture(GL_TEXTURE3);
    glBindTexture(GL_TEXTURE_2D, this->height.getID());
}

void object3d::render(){
    
    
    this->shader->use();
    
    this->bindTextures();
    
    
    glBindVertexArray(VAO);
    
    glDrawElements(GL_TRIANGLES, this->faceDataSize, GL_UNSIGNED_INT,(void*)(0));
    
    glBindVertexArray(0);
    

          
}

int object3d::countOccurences(char c, string& str){
    int count = 0;
    
    for(char str_c : str){
        if(c == str_c){
            count++;
        }
    }
    
    return count;
};



vector<LinearVertice> object3d::getFace3FromString(string line){
                
        int l3 = line.rfind(' ', line.rfind(' '));      //find the the Spaces seperating the index Parts: "1/2/2 3/4/2 6/2/1 "
        int l2 = line.rfind(' ', l3 - 1);
        int l1 = line.rfind(' ', l2 - 1);
        
        string one = line.substr(l1 + 1, l2 - l1 - 1);  //Seperate the String with the Indeces from the Spaces: "1/2/2","3/4/2","6/2/2"
        string two = line.substr(l2 + 1, l3 - l2 - 1);
        string three = line.substr(l3+1, -1);
        
        LinearVertice x;
        LinearVertice y;
        LinearVertice z;
        
        x.vertIndex = std::stoi(one.substr(0,one.find("/")))-1; //take from each Substring the Vertex-Index-Part: 1,3,6
        y.vertIndex = std::stoi(two.substr(0,two.find("/")))-1;
        z.vertIndex = std::stoi(three.substr(0,three.find("/")))-1;
        
        x.normalIndex = std::stoi(one.substr(one.find_last_of("/") + 1,-1)) -1; //take from each substring the Normal-Index-Part: 2,2,2
        y.normalIndex = std::stoi(two.substr(two.find_last_of("/") + 1,-1)) -1;
        z.normalIndex = std::stoi(three.substr(three.find_last_of("/") + 1,-1)) -1;
        
        
        x.texCoordIndex = std::stoi(one.substr(one.find("/") + 1, one.find_last_of("/") -1 ))-1; //take from each Substring the Text-Coord-Index Part: 2,4,2 
        y.texCoordIndex = std::stoi(two.substr(two.find("/") + 1, two.find_last_of("/") -1 ))-1;
        z.texCoordIndex = std::stoi(three.substr(three.find("/") + 1, three.find_last_of("/") -1 ))-1;
        
        vector<LinearVertice> face; 
        face.push_back(x);
        face.push_back(y);
        face.push_back(z);
                 
        return face;      
};
vector<LinearVertice> object3d::getFace4FromString(string line){
    
    vector<LinearVertice> face = object3d::getFace3FromString(line);
    
    int l4_1 = line.find(' ');
    int l4_2 = line.find(' ', line.find(' ')+1);
    string four = line.substr(l4_1+1,l4_2-1);
    
    LinearVertice fourth;

    fourth.vertIndex = std::stoi(four.substr(0,four.find("/")))-1;
    fourth.normalIndex = std::stoi(four.substr(four.find_last_of("/") + 1,-1)) -1;
    fourth.texCoordIndex = std::stoi(four.substr(four.find("/") + 1, four.find_last_of("/") -1 ))-1;

    face.push_back(fourth);

    return face;
};

vector<string> object3d::getLinesWithAttributeFromOBJ(string name, string attribute){
    string line;
    ifstream file (name);
    vector<string> lines;

  
    if (file.is_open()){
        
        while ( getline (file,line) ){
        
            if(line.substr(0,line.rfind(' ', 3))==attribute){//is Attribute at beginning?
                lines.push_back(line);
            }
            
        }
        
        file.close();
        
    }
    else{
        cout << "Unable to open file: " << name << std::endl;
    }
    return lines;
};

Vector object3d::getVerticeFromString(string line){
    int l3 = line.rfind(' ');
    int l2 = line.rfind(' ', l3-1);
    int l1 = line.rfind(' ', l2-1);

    float x = std::stof(line.substr(l1+1,l2-l1-1)) ;
    float y = std::stof(line.substr(l2+1, l3-l2-1));
    float z = std::stof(line.substr(l3+1, -1));
    Vector vec = *new Vector(x,y,z);
    return vec;
};

vector<Vector> object3d::getVerticesFromOBJ(string name){
    return object3d::getVectorObjectFromOBJ(name,"v");
};

vector<Vector> object3d::getNormalsFromOBJ(string name){
    return object3d::getVectorObjectFromOBJ(name, "vn");
};

vector<Vector> object3d::getVectorObjectFromOBJ(string name, string attribute){
    vector<string> lines = object3d::getLinesWithAttributeFromOBJ(name, attribute);
    vector<Vector> vertices;
    for(string line:lines){
        vertices.push_back(object3d::getVerticeFromString(line));
    }
    return vertices;
};
TexCoord object3d::getTextureCoordFromString(string line){
    
    int l2 = line.rfind(' ');
    int l1 = line.rfind(' ', l2-1);

    float x = std::stof(line.substr(l1+1,l2-1)) ;
    float y = std::stof(line.substr(l2+1, -1));
    
    TexCoord textureCoord = *new TexCoord();

    textureCoord.x = x;
    textureCoord.y = y;
    
    return textureCoord;
    
};

vector<TexCoord> object3d::getTextureCoordsFromOBJ(string name){
    vector<string> lines = object3d::getLinesWithAttributeFromOBJ(name, "vt");
    vector<TexCoord> textureCoords;
    for(string line:lines){
        textureCoords.push_back(object3d::getTextureCoordFromString(line));
    }
    return textureCoords;
};
vector<LinearVertice> object3d::getFaceFromString(string line){
    vector<LinearVertice> face;
    if(object3d::countOccurences(' ', line) == 4){
        face = object3d::getFace4FromString(line);
    }else{
        face = object3d::getFace3FromString(line);       
    }   
    return face;
    
};
bool object3d::hasCombination(vector<LinearVertice> combinations, LinearVertice newCombi){
    for(LinearVertice combi:combinations){
        if(combi.vertIndex == newCombi.vertIndex && 
           combi.normalIndex== newCombi.normalIndex && 
           combi.texCoordIndex == newCombi.texCoordIndex){
            return true;            
        }
    }
    return false;
};

vector<LinearVertice> object3d::getVerticeCombinationsFromOBJ(string name){
    vector<string> lines = object3d::getLinesWithAttributeFromOBJ(name, "f"); 
    vector<LinearVertice> vertexCombinations;
    for(string line:lines){
        
        vector<LinearVertice> face = object3d::getFaceFromString(line);
        
        
        
        for(LinearVertice vertexCombi: face){
        
            if(!object3d::hasCombination(vertexCombinations, vertexCombi)){
            
                vertexCombinations.push_back(vertexCombi);
            
            }
        }
    }
    
    return object3d::linearizeIndeces(vertexCombinations);
};

vector<LinearVertice> object3d::linearizeIndeces(vector<LinearVertice> combinations){
    bool found= true;
    int vertexIndex = -1;
    int lastWroteIndex = -1;
    while(found){
        vertexIndex++;
        found = false;
        for(int i = 0; i < combinations.size();i++){
            if(combinations.at(i).vertIndex == vertexIndex){
                combinations.at(i).newLinearIndex = lastWroteIndex + 1;
                lastWroteIndex++;
                found = true;
            }
        }
    }
    
    return combinations;
};
vector<LinearVertice> object3d::getFaceIndecesFromOBJ(string name){
    vector<string> lines = object3d::getLinesWithAttributeFromOBJ(name, "f"); 
    vector<LinearVertice> vertexCombinations;
    for(string line:lines){
        
        vector<LinearVertice> face = object3d::getFaceFromString(line);
        vertexCombinations.push_back(face.at(0));
        vertexCombinations.push_back(face.at(1));
        vertexCombinations.push_back(face.at(2));
        if(face.size()==4){
            vertexCombinations.push_back(face.at(0));
            vertexCombinations.push_back(face.at(2));
            vertexCombinations.push_back(face.at(3));
        }
                    
    }
    return vertexCombinations;
};

void object3d::fillVertexData(vector<Vector> vertices, vector<Vector> normals, vector<TexCoord> textureCoords, vector<LinearVertice> combinations,vector<Vector> tangents_bitangents){
    this->vertexdata = new float[combinations.size()*14];
    this->vertexDataSize = combinations.size();
    for(LinearVertice combi:combinations){
        this->vertexdata[combi.newLinearIndex*14 +  0] = vertices.at(combi.vertIndex).getX();   //Vertex
        this->vertexdata[combi.newLinearIndex*14 +  1] = vertices.at(combi.vertIndex).getY();
        this->vertexdata[combi.newLinearIndex*14 +  2] = vertices.at(combi.vertIndex).getZ();
        
        this->vertexdata[combi.newLinearIndex*14 +  3] = normals.at(combi.normalIndex).getX();  //Normal
        this->vertexdata[combi.newLinearIndex*14 +  4] = normals.at(combi.normalIndex).getY();
        this->vertexdata[combi.newLinearIndex*14 +  5] = normals.at(combi.normalIndex).getZ();
        
        this->vertexdata[combi.newLinearIndex*14 +  6] = textureCoords.at(combi.texCoordIndex).x; //TextureCoord
        this->vertexdata[combi.newLinearIndex*14 +  7] = textureCoords.at(combi.texCoordIndex).y;
        
        this->vertexdata[combi.newLinearIndex*14 +  8] = tangents_bitangents.at(combi.newLinearIndex*2).getX(); //Tangent
        this->vertexdata[combi.newLinearIndex*14 +  9] = tangents_bitangents.at(combi.newLinearIndex*2).getY();
        this->vertexdata[combi.newLinearIndex*14 + 10] = tangents_bitangents.at(combi.newLinearIndex*2).getZ();
        
        this->vertexdata[combi.newLinearIndex*14 + 11] = tangents_bitangents.at(combi.newLinearIndex*2+1).getX(); //Bitangent
        this->vertexdata[combi.newLinearIndex*14 + 12] = tangents_bitangents.at(combi.newLinearIndex*2+1).getY();
        this->vertexdata[combi.newLinearIndex*14 + 13] = tangents_bitangents.at(combi.newLinearIndex*2+1).getZ();
        
    }
};

void object3d::fillFaceIndexData(vector<LinearVertice> faces, vector<LinearVertice> combinations){
    this->facedata = new unsigned int[faces.size()];
    this->faceDataSize = faces.size();
    for(int j = 0; j < faces.size(); j++){
        for(int i = 0; i < combinations.size(); i++){
            if(faces.at(j).vertIndex == combinations.at(i).vertIndex &&
               faces.at(j).normalIndex == combinations.at(i).normalIndex &&
               faces.at(j).texCoordIndex == combinations.at(i).texCoordIndex){
                this->facedata[j] = combinations.at(i).newLinearIndex;
                
            }
        }
    }
};

void object3d::translate(Vector vec){
    this->modelmatrix.translate(vec);
    
}

vector<Vector> object3d::calculate_tangent_bitangent(vector<LinearVertice> faces, 
                                                           vector<LinearVertice> combinations,
                                                           vector<Vector> normals, 
                                                           vector<Vector> vertices,
                                                           vector<TexCoord> textureCoords){
    vector<Vector> tangents_bitangents (combinations.size()*2);
    for(int j=0; j < faces.size(); j=j+3){
        
        Vector pos1 = vertices.at(faces.at(j+0).vertIndex);
        Vector pos2 = vertices.at(faces.at(j+1).vertIndex);
        Vector pos3 = vertices.at(faces.at(j+2).vertIndex);
        
        
        TexCoord uv1 = textureCoords.at(faces.at(j+0).texCoordIndex);
        TexCoord uv2 = textureCoords.at(faces.at(j+1).texCoordIndex);
        TexCoord uv3 = textureCoords.at(faces.at(j+2).texCoordIndex);
        
        Vector e1 = * new Vector(pos2.getX() - pos1.getX(), pos2.getY() - pos1.getY(), pos2.getZ() - pos1.getZ());
        Vector e2 = * new Vector(pos3.getX() - pos1.getX(), pos3.getY() - pos1.getY(), pos3.getZ() - pos1.getZ());
        
        TexCoord duv1;
            duv1.x = uv2.x - uv1.x;
            duv1.y = uv2.y - uv1.y;
        TexCoord duv2;
            duv2.x = uv3.x - uv1.x;
            duv2.y = uv3.y - uv1.y;
        
        float factor = 1.0f / (duv1.x * duv2.y - duv2.x * duv1.y);
        
        Vector tangents[2];
        
        tangents[0] = * new Vector( factor * (e1.getX() * duv2.y - e2.getX() * duv1.y)
                                    ,factor * (e1.getY() * duv2.y - e2.getY() * duv1.y)
                                    ,factor * (e1.getZ() * duv2.y - e2.getZ() * duv1.y));
        
        tangents[1] = * new Vector( factor * (- e1.getX() * duv2.x + e2.getX() * duv1.x)
                                    ,factor * (- e1.getY() * duv2.x + e2.getY() * duv1.x)
                                    ,factor * (- e1.getZ() * duv2.x + e2.getZ() * duv1.x));
        std::cout << "Tangents:\t"<<tangents[0].to_string()<< std::endl;
        for(int i = 0; i < combinations.size(); i++){
            for(int z=0; z<3; z++){
                if(faces.at(j+z).vertIndex == combinations.at(i).vertIndex &&
                    faces.at(j+z).normalIndex == combinations.at(i).normalIndex &&
                    faces.at(j+z).texCoordIndex == combinations.at(i).texCoordIndex){
                tangents_bitangents.at(combinations.at(i).newLinearIndex*2) += tangents[0];
                tangents_bitangents.at(combinations.at(i).newLinearIndex*2+1) += tangents[1];
                
                }
            }
        }
    }
    
    
    return tangents_bitangents;
}