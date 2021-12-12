#include "../headers/texture.h"

void Texture::loadTexture(string name, GLuint *id){
    std::ifstream myimage (name);
    char header[138];
    char *data;
    if(myimage.is_open()){
        myimage.read(header,138);
        
        if(header[0]=='B' && header[1]=='M'){
            
            int dataPos    = *(int*)&(header[10]);
            int imageSize  = *(int*)&(header[34]);
            int width      = *(int*)&(header[18]);
            int height     = *(int*)&(header[22]);
            
            
            //check ob right muss hier noch hin falls corrupted
            std::cout << "Header zu Textur \'"<< name <<" \'geladen:: \t width: " << width << "\t height: "<< height<<  "\t img-size: " << imageSize/1000 << "kB\t dataPosition: " << dataPos << std::endl;
            data=new char [imageSize];
            myimage.read(data, imageSize);
            
            
            glGenTextures(1, id);

            glActiveTexture(GL_TEXTURE0+this->number);
            glBindTexture(GL_TEXTURE_2D, *id);


            glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
            glGenerateMipmap(GL_TEXTURE_2D);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
            
            
            
            myimage.close();
            
        }else{
            std::cout << "Fehler beim Lesen der Textur: kein BMP" << std::endl;
            return;
        }
    }else{
        std::cout << "Fehler beim Lesen der Textur: Datei konnte nicht geöffnet werden" << std::endl;
        return;
    }
}

Texture::Texture(string name,unsigned int number){
    this->id = *new GLint;
    this->number = number;
    this->loadTexture(name,&this->id);
}
Texture::Texture(){
}
GLuint Texture::getID(){
    return this->id;
}