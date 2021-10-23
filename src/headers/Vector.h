/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vetice.h
 * Author: marvin
 *
 * Created on December 26, 2020, 11:24 PM
 */

#ifndef VECTOR_H
#define VECTOR_H
#include <glm/glm.hpp>
#include <string>
using std::string;
class Vector {
public:
    /**
     *  Default constructor, sets:  this.x = this.y = this.z = 0
     */
    Vector();
    /**
     * Constructor for working with VBO's
     * 
     * @param vec the Point in the VBO where the Vertex is
     */
    Vector(float &vec);
    /**
     * Constructor for working with VBO's
     * @param vec pointer to vec
     */
    Vector(float * vec);
    /**
     * constructor with 3 doubles
     * @param x coordinate
     * @param y coordinate
     * @param z coordinate
     */
    Vector(float x, float y, float z);
    
    /**
     * constructor with double array of length 3
     * @param vec double array like: [x,y,z]
     */
    Vector(double vec[3]);
    
    glm::vec3 get();
    /**
     * 
     * @return x-coordinate of this vector
     */
    double getX();
    /**
     * 
     * @return y-coordinate of this vector
     */
    double getY();
    
    /**
     * 
     * @return z-coordinate of this vector
     */
    double getZ();
    
    /**
     * sets the coordinates of this vector  
     * @param x coordinate
     * @param y coordinate
     * @param z coordinate
     */
    void set(float x, float y, float z);
    
    /**
     * calculates the distance between itself and given vector
     * @param vec vector the distance should be calculated
     * @return [double] distance 
     */
    double distance(Vector* vec);
    Vector operator +=(const Vector vec) const;
   /**
     * adds two vectors: (x1 + x2, y1 + y2, z1 + z2)
     * @param vec vector to add
     * @return [vector] the result of the addition
     */
    Vector operator +(const Vector vec) const ;
    
   /**
     * substracts two vectors: (x1 - x2, y1 - y2, z1 - z2)
     * @param vec vector to substract vec = (x2, y2, z2)
     * @return [vector] the result of the substraction
     */
    Vector operator -(const Vector &vec);
    
   /**
     * multiplies two vectors: (x1 * x2, y1 * y2, z1 * z2)
     * @param vec vector to multiply
     * @return [vector] the result of the multiplication
     */
    Vector operator *(const Vector vec) const;
    
    /**
     * multiplies a vector with a coefficient (factor).
     * @param factor coefficient
     * @return [vector] with same direction and a length times the coefficient
     */
    Vector operator *(const double factor) const ;
    
    /**
     * divides a vector by a divisor.
     * @param divisor 
     * @return [vector] with same direction and a length divided by divisor
     */
    Vector operator /(const double divisor);
    
    /**
     * adds a single value to every value of the vector
     * @param addend 
     * @return [vector] (x + addend, y + addend, z + addend)
     */
    Vector operator +(const double addend) const;
    
    /**
     * substracts a single value from every value of the vector
     * @param substractor
     * @return [vector] (x - substractor, y - substractor, z - substractor)
     */
    Vector operator -(const double substractor) const;
    /**
     * Calculates the Vector to connect this and B.
     * @param B Endpoint
     * @return connecting vector
     */
    Vector operator |(const Vector B) const;
    
    /**
     * Compares to vectors;
     * @param vec Vector to compare this to
     * @return true if same vector, false if not
     */
    bool operator ==(const Vector vec) const;
    

    
    /**
     * Checks for linear dependency
     * @param vec vector to check
     * @return true if the both are linear depended, false if not
     */
    bool linearTo(Vector vec);
    
    /**
     * Calculates relation of this.x and vec.x and compares if this relation is right for y and z
     * @param vec 
     * @return true if all relations are equal, false if not
     */
    bool isRelationForAllVectorvaluesTheSame(Vector vec);
    /**
     * Calculates the crossproduct of this and a given Vector.
     * @param vec given vector
     * @return crossproduct
     */
    Vector crossProduct(Vector vec);
    /**
     * 
     * @return [double] length of the vector 
     */
    double length();
    
    /**
     * normalizes this vector
     */
    void normalize();
    
    /**
     * 
     * @return [vertice] this vector but normalized 
     */
    Vector normalizedGet();
    /**
     * scalar-product of this and the given vector 
     * @param vec 
     * @return 
     */
    double scalar(Vector vec);
    /**
     * calculates the angle between this and vec
     * @param vec 
     * @return angle
     */
    double angle(Vector vec);
    /**
     * String for output to cout
     * @return nice formated vector as string 
     */
    string to_string();
    
    
private:
   
    float * vec;

    /**
     * calculates the length of a given vector
     * @param vec vector which length should be calculated
     * @return [double] length of the given vector
     */
    double length(Vector* vec);
    /**
     * calculates the length of a given vector as doubles
     * @param x value of the vector the length should be calculated
     * @param y value of the vector the length should be calculated
     * @param z value of the vector the length should be calculated
     * @return  length
     */
    double length(double x, double y, double z);
};




#endif /* VECTOR_H */

