#include "mat4.h"
#include "Vector.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.h"
#ifndef CAMERA_H
#define CAMERA_H

class camera {
    private: 
        int width;
        int height;
        Vector position;
        mat4 viewmatrix;
        mat4 projectionmatrix;
        Vector direction;
    
    public: 
        void render(Shader * shader);
        void init(Vector pos, int width, int height, float fov, Vector direction);
        
        camera();
        camera(Vector startPos, int width, int height);
        camera(Vector startPos);
        camera(int width, int height);
    

        float getRendertexture();
    
        mat4 getProjectionMatrix();
        glm::mat4 getProjectionMatrixGLM();
        
        void setProjectionMatrix(mat4 projectmat);
        
        void setProjectionMatrix(glm::mat4 projectmat);
        
        Vector getPosition();
    
        void setDirection(float x, float y, float z);
        void setPosition(Vector newPos);
        void setPosition(float x, float y, float z);
        void setDirection(Vector newDir);
        
        Vector getDirection();
        mat4 getViewmatrix();
        glm::mat4 getViewmatrixGLM();

        void setViewMatrix(mat4 relativeviewmat);
        void setViewMatrix(glm::mat4 viewmat);

    
};

#endif /* CAMERA_H */

