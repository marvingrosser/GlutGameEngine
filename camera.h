

#ifndef CAMERA_H
#define CAMERA_H

class camera {
    private float loc_x,loc_y, loc_z;
public:
    camera(loc_x, loc_y, loc_z){
        this->loc_x=loc_x;
        this->loc_y = loc_y;
        this->loc_z = loc_z;
    
    }
    camera(const camera& orig);
    virtual ~camera();
private:

};

#endif /* CAMERA_H */

