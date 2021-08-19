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

unsigned int * object3d::countinstances(string name){

  string line;
  ifstream overlook (name);
  
  int vertexcounter = 0;
  int normalcounter = 0;
  int facecounter = 0;
  int texturecoordscounter = 0;
  
  if (overlook.is_open())
  {
    while ( getline (overlook,line) )
    {
        if(line.substr(0,line.rfind(' ', 3))=="v"){//vertices
            vertexcounter++;
            //std::cout << vertexcounter << std::endl;
        }else if(line.substr(0, line.rfind(' ',3))=="vn"){//normals
            
            normalcounter++;
            
        }else if (line.substr(0, line.rfind(' ',3))=="f"){ //faceline
            
            facecounter++;

        }else if(line.substr(0, line.rfind(' ',3))=="vt"){ //verticetexturecoordinates
           
            texturecoordscounter++;
            
            }
        }
        overlook.close();
    }
    else{
        cout << "Unable to open file: " << name << std::endl;
    } 
  
    
    this->counts = new unsigned int[4];
    this->counts[0] = vertexcounter;
    this->counts[1] = normalcounter;
    this->counts[2] = facecounter;
    this->counts[3] = texturecoordscounter;
    return this->counts;
};
void object3d::readObj(string name){
  string line;  
  unsigned int * counts = this->countinstances(name);
  ifstream myfile (name);
  
  std::cout << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
  std::cout << glGetString(GL_RENDERER) << std::endl;
  std::cout << glGetString(GL_VERSION) << std::endl;
  std::cout << "Number Verts:\t\t"<< counts[0]<< std::endl;
  std::cout << "Number Normals:\t\t"<< counts[1]<< std::endl;
  std::cout << "Number Faces:\t\t"<< counts[2]<< std::endl;
  std::cout << "Number TextureCoords:\t\t"<< counts[3]<< std::endl;
  this->vertexdata = new float[3*counts[0]];
  this->facedata = new unsigned int[4*counts[2]];
  if (myfile.is_open())
  {
      vector<Face> faces;
      vector<Vector> normals;

    while ( getline (myfile,line) )
    {


        if(line.substr(0,line.rfind(' ', 3))=="v"){//vertices

            this->loadVectorFromString(line,vertices,&vertexdata[0]);
            
        }else if(line.substr(0, line.rfind(' ',3))=="vn"){//normals
            
            //this->loadVectorFromString(line,normals,&vertexdata[3*counts[0]]);
            
        }else if (line.substr(0, line.rfind(' ',3))=="f"){ //faceline
            
            this->loadFaceFromString(line,faces,vertices,normals, &facedata[0]);

        }else if(line.substr(0, line.rfind(' ',3))=="vt"){ //verticetexturecoordinates
           
            //this->loadTextureCoordFromString(line);
            
        }

    }
    myfile.close();





      //this->faces = faces;
      }

  else{
      cout << "Unable to open file: " << name << std::endl;
  } 
  

};

object3d::object3d(string name){
    
    this->readObj(name);
    this->init();
    


}
void object3d::init(){
    
    
    std::cout << "Vertices"<< std::endl;
    for(int i = 0; i < 10;i++){
        std::cout << "v(" << i+1 << "):\t\t(" << this->vertexdata[i*3]<< ", "<<this->vertexdata[i*3+1]<< ", " <<this->vertexdata[i*3+2]<< ")"<<std::endl;;
    }
    std::cout << "Faces"<< std::endl;
    for(int i = 0; i < 10;i++){
        std::cout << "f(" << i+1 << "):\t\t(" << this->facedata[i*3]<< ", "<<this->facedata[i*3+1]<< ", " <<this->facedata[i*3+2]<< ")"<<std::endl;;
    }
    
    std::cout << sizeof(vertexdata) << std::endl;
    std::cout << sizeof(facedata) << std::endl;
    this->shader = *new Shader();
    this->shader.use();
    
    this->modelmatrix = * new mat4();
    GLuint model = glGetUniformLocation(shader.getID(), "model");
    
    glProgramUniformMatrix4fv(shader.getID(),model, 1, GL_FALSE, this->modelmatrix.getPtr());
    
    
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    
    
    
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER, this->counts[0]*sizeof(float)*3, this->vertexdata, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->counts[2]*sizeof(unsigned int)*3, this->facedata,GL_STATIC_DRAW);
    
    glVertexAttribPointer(0,3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *)0);
    glEnableVertexAttribArray(0);
    
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);
    
    
    
};
object3d::object3d(string name, string textureName){
    this->readObj(name);
    this->init();
    //this->textureId = new GLuint;
    //new Texture(textureName, this->textureId );
    //glEnable(GL_TEXTURE_2D);
    
}
GLuint object3d::getShader(){
    return this->shader.getID();
};
void object3d::render(){
    //glBindTexture(GL_TEXTURE_2D, *this->textureId);
    //std::cout << "render" << std::endl;
    
    this->shader.use();
    
    
    glBindVertexArray(VAO);
    
    glDrawElements(GL_TRIANGLES, this->counts[2]*3, GL_UNSIGNED_INT,(void*)0);
    
    glBindVertexArray(0);
    /*
    for(Face face: this->faces){
        Face *f = &face;
        f->render();
        
    }*/
          
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

void object3d::loadVectorFromString(string& line, vector<Vector> &vectors, float *datapointer){
            int l3 = line.rfind(' ');
            int l2 = line.rfind(' ', l3-1);
            int l1 = line.rfind(' ', l2-1);

            float x = std::stof(line.substr(l1+1,l2-l1-1)) ;
            float y = std::stof(line.substr(l2+1, l3-l2-1));
            float z = std::stof(line.substr(l3+1, -1));

            datapointer[3 * vectors.size() + 0] = x;
            datapointer[3 * vectors.size() + 1] = y;
            datapointer[3 * vectors.size() + 2] = z;
            Vector punkt = Vector(& datapointer[3*vectors.size() + 0]);
            //std::cout << punkt.to_string()<< std::endl;
            vectors.push_back(punkt);
};

void object3d::loadFaceFromString(string& line, vector<Face>& faces, vector<Vector> &vertices , vector<Vector> &normals, unsigned * vertexdata){
            
            if(object3d::countOccurences(' ', line) == 4){
                object3d::loadFace4FromString(line,faces,vertices,normals, vertexdata);
            }else{
                object3d::loadFace3FromString(line,faces,vertices,normals,vertexdata);
            }
            
};

void object3d::loadFace3FromString(string& line, vector<Face>& faces, vector<Vector>& vertices, vector<Vector>& normals, unsigned int * vertexdata){
            Face newface;
            int l3 = line.rfind(' ', line.rfind(' '));
            int l2 = line.rfind(' ', l3 - 1);
            int l1 = line.rfind(' ', l2 - 1);

            string one = line.substr(l1 + 1, l2 - l1 - 1);
            string two = line.substr(l2 + 1, l3 - l2 - 1);
            string three = line.substr(l3+1, -1);
            
            int x_index = std::stoi(one.substr(0,one.find("/")))-1;
            int y_index = std::stoi(two.substr(0,two.find("/")))-1;
            int z_index = std::stoi(three.substr(0,three.find("/")))-1;
            int normal_index = std::stoi(one.substr(one.find_last_of("/") + 1,-1)) -1;

            //std::cout << "X: " << x_index << "\t Y: "<< y_index << "\t Z: " << z_index<< "\t Normal: " << normal_index << std::endl;
            //std::cout << (( vertices[x_index])).to_string()<< std::endl;
            
            //set FaceIndexData
            vertexdata[faces.size()*3 + 0] = x_index;
            vertexdata[faces.size()*3 + 1] = y_index;
            vertexdata[faces.size()*3 + 2] = z_index;
            //vertexdata[faces.size()*4 + 3] = normal_index;
            
            
            //set FaceObject
            newface.setX(&( vertices[x_index]));
            newface.setY(&(vertices[y_index]));
            newface.setZ(&(vertices[z_index]));
            //newface.setNormal(normals[normal_index]);
            /*
            int x_texture_coord = object3d::getTextureCoordFromString(one);
            int y_texture_coord = object3d::getTextureCoordFromString(two);
            int z_texture_coord = object3d::getTextureCoordFromString(three);
            
            if(x_texture_coord >=0 && y_texture_coord >=0 && z_texture_coord>=0){
                object3d::assignTextureCoords( x_texture_coord,
                    y_texture_coord,
                    z_texture_coord,
                    &newface);
            }
                
            */
            
            
            faces.push_back(newface);
};

void object3d::loadFace4FromString(string& line, vector<Face>& faces, vector<Vector>& vertices, vector<Vector>& normals, unsigned int * vertexdata){
            Face newface1;
            Face newface2;
            
            int l3 = line.rfind(' ', line.rfind(' '));
            int l2 = line.rfind(' ', l3 - 1);
            int l1 = line.rfind(' ', l2 - 1);
            int l0 = line.rfind(' ',l1 - 1);
            
            string zero = line.substr(l0 + 1, l1 - l0 - 1);
            string one = line.substr(l1 + 1, l2 - l1 - 1);
            string two = line.substr(l2 + 1, l3 - l2 - 1);
            string three = line.substr(l3 + 1, -1);

            int x_index = std::stoi(one.substr(0,one.find("/")))-1;
            int y_index = std::stoi(two.substr(0,two.find("/")))-1;
            int z_index = std::stoi(three.substr(0,three.find("/")))-1;
            int w_index = std::stoi(zero.substr(0,zero.find("/")))-1;
            
            int normal_index=std::stoi(one.substr(one.rfind("/") + 1, -1)) - 1;
            /*
            int x_texture_coord = object3d::getTextureCoordFromString(one);
            int y_texture_coord = object3d::getTextureCoordFromString(two);
            int z_texture_coord = object3d::getTextureCoordFromString(three);
            int w_texture_coord = object3d::getTextureCoordFromString(zero);
            
            object3d::assignTextureCoords( x_texture_coord,
                    y_texture_coord,
                    z_texture_coord,
                    &newface1);
            
            object3d::assignTextureCoords(x_texture_coord,
                    w_texture_coord,
                    z_texture_coord,
                    &newface2);
            std::cout << vertices[x_index].to_string()<< std::endl;
              */
            newface1.setX(&vertices[x_index]);
            newface1.setY(&vertices[y_index]);
            newface1.setZ(&vertices[z_index]);
            //newface1.setNormal(normals[normal_index]);
            
            newface2.setX(&vertices[x_index]);
            newface2.setY(&vertices[w_index]);
            newface2.setZ(&vertices[z_index]);
            //newface2.setNormal(normals[std::stoi(one.substr(one.rfind("/") + 1, -1)) - 1]);
            vertexdata[faces.size()*3 + 0] = x_index;
            vertexdata[faces.size()*3 + 1] = y_index;
            vertexdata[faces.size()*3 + 2] = z_index;
            faces.push_back(newface1);
            vertexdata[faces.size()*3 + 0] = x_index;
            vertexdata[faces.size()*3 + 1] = w_index;
            vertexdata[faces.size()*3 + 2] = z_index;
            faces.push_back(newface2);
           
};

void object3d::loadTextureCoordFromString(string& line){
    int second_ = line.rfind(' ', line.rfind(' '));
    int first_  = line.rfind(' ', second_ - 1);
    
    
    string second_d = line.substr(second_,-1);
    string first_d = line.substr(first_,second_ -2);
    
    vector<double> textureCoord;
    /*
    textureCoord.push_back(std::stod(first_d));
    textureCoord.push_back(std::stod(second_d));
    this->textureCoord.push_back(textureCoord);*/
};

void object3d::assignTextureCoords(int coord_X, int coord_Y, int coord_Z, Face* face){
    /*
    face->setTextureCoord_X(this->textureCoord.at(coord_X));
    face->setTextureCoord_Y(this->textureCoord.at(coord_Y));
    face->setTextureCoord_Z(this->textureCoord.at(coord_Z)); 
     */
    
};

int object3d::getTextureCoordFromString(string& substring){
    
    int index_first =substring.find_first_of("/")+1;
    int index_last =substring.find_last_of("/");
    if(index_first == index_last){
        return -1;
    }
    string coord = substring.substr(index_first, index_last -index_first);
    std::cout <<"first: "<< index_first << "\tlast: "<< index_last << "\t coords: " << coord<< std::endl;
    
    return std::stoi(coord)-1;
}