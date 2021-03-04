#include "mat4.h"
#include "vertice.h"

#ifndef CAMERA_H
#define CAMERA_H

class camera {
    protected: 
        vertice position;

        mat4 viewmatrix;

        vertice LOOK;
    
    public: 
        camera();
        camera(vertice startPos);
    

        float getRendertexture();
    

        vertice getPosition();
    
       
        void setPosition(vertice newPos);
    

        mat4 getViewmatrix();
    

        void setnewviewmatrix(mat4 relativeviewmat);
    

    
};

#endif /* CAMERA_H */

