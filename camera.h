#include "mat4.h"
#include "vector.h"

#ifndef CAMERA_H
#define CAMERA_H

class camera {
    private: 
        vector position;

        mat4 viewmatrix;

        vector LOOK;
    
    public: 
        camera(vector startPos);
    

        float getRendertexture();
    

        vector getPosition();
    

        void setPosition(vector newPos);
    

        mat4 getViewmatrix();
    

        void setnewviewmatrix(mat4 relativeviewmat);
    

    
};

#endif /* CAMERA_H */

