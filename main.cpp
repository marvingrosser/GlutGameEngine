/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: marvin
 *
 * Created on October 17, 2019, 2:29 PM
 */

#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <GL/glut.h>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>

using std::vector;
using namespace std;
using std::cout;
using std::endl;
using std::string;

struct POINT
{
    float x;
    float y;
    float z;
    
};

struct FACE{
    POINT x;
    POINT y;
    POINT z;
    POINT normal;
};






/*
 * 
 */

float x_mouse=0.0f,y_mouse=0.0f;
int old_x_mouse=0, old_y_mouse=0;
int width, height;
float movefb=0.0f,moverl=0.0f;
POINT LOOK = POINT();
POINT cam_pos = POINT();
float movecount=0.0f;
float sens = 0.0007f;
float mspeed = 0.01f;

GLfloat light_position[] = {0.0, 0.0, 1.0, 0.0}; 
void init();
void reshape(int w, int h);
void keyboard(unsigned char Key, int x, int y);
void render();
void releaseKey(unsigned char key, int x, int y);
vector<FACE> loadobj(string name);


vector<FACE> objmap = loadobj("land.obj");
//vector<FACE> haus = loadobj("haus.obj");



int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE);
    

    glutInitWindowSize(800, 600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("game");
    glutKeyboardUpFunc(releaseKey);
    glutIgnoreKeyRepeat(1);
    glutDisplayFunc(render);
    glutIdleFunc(render);
    glutReshapeFunc (reshape);
    glutKeyboardFunc(keyboard);


    init();
    glutMainLoop();
    
    return 0;

}
void releaseKey(unsigned char key, int x, int y) { 	

        switch (key) {
             case 'w' :
             
             case 's': movefb = 0.0f;break;
                 case 'a':
             case 'd' : moverl=0.0f;break;
        }
} 
void keyboard(unsigned char Key, int x, int y){
    switch(Key){
        case 'w': movefb=1.0f;break;
        case 's': movefb=-1.0f;break;
        case 'a': moverl=-1.0f;break;
        case 'd': moverl=1.0f;break;
        
    }
    

}
void mouse(int x, int y){
   

    
 
    

    int cx = width/2;
    int cy = height/2;
    if(x!=cx || y!=cy){
    x_mouse += (cx - x) * sens;
    y_mouse += (cy - y) * sens;
    cout << x_mouse <<' ' << y_mouse << '\n';
    
    glutWarpPointer(cx, cy);
    }
   // render();

}
void init(void)
{   
    cam_pos.x = 0.0f;
    cam_pos.y = 0.0f;
    cam_pos.z = 5.0f;
 
    glutPassiveMotionFunc(mouse);
    glEnable(GLUT_MULTISAMPLE);
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    
    
  GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};  /* Red diffuse light. */
  
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glEnable(GL_LIGHT0);
  glEnable(GL_LIGHTING);
  glShadeModel(GL_SMOOTH);
  

  /* Setup the view of the cube. */
  glMatrixMode(GL_PROJECTION);
  
  glutSetCursor(GLUT_CURSOR_NONE);
}

float rot =0.01;
/*
void render(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(-1.5f ,0.0f,-10.0f);
    
    glRotatef( rot, 1, 2, 1);
    rot = rot+ 0.02;
    if (rot >= 360)
    {
        rot=0;
    
    }
    glBegin(GL_TRIANGLES);
    

    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    
 
 
    
    
    glEnd();
    
    
    
    glutSwapBuffers();
    
    








}
*/

void render()
{
   

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
   // int randhaus[] = glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
   // glTranslatef(0.0f ,0.0f,0.0f);
    
    POINT CNORM = POINT();
  
    
    POINT Rvec = POINT();
    /*
    glRotatef( rot, 1, 2, 1);
    rot = rot+ 0.02;
    if (rot >= 360)
    {
        rot=0;
    
    }*/
    //glRotatef(y_mouse, 0,0,1);
    //glRotatef(x_mouse, 0,1,0);
 
    Rvec.x = - sin(x_mouse);
    Rvec.y =   sin(y_mouse);
    Rvec.z = - cos(x_mouse);
    
    LOOK.x = cam_pos.x + Rvec.x ;
    LOOK.y = cam_pos.y + Rvec.y ;
    LOOK.z = cam_pos.z + Rvec.z ;
    
    if(movefb==1.0f){
        
        cam_pos.x += Rvec.x * mspeed;
        cam_pos.y = 1 + sin(movecount)*0.07;
        cam_pos.z += Rvec.z * mspeed;
      
        movecount += 0.0063f;
    }else if (movefb==-1.0f){
        cam_pos.x -= Rvec.x * mspeed;
        cam_pos.y = 1 + sin(movecount)*0.07;
        cam_pos.z -= Rvec.z * mspeed;
 
        movecount += 0.0043f;
    }
    if (moverl==1.0f){
        cam_pos.x +=  -(Rvec.z) * mspeed;
        
        cam_pos.z += Rvec.x * mspeed;
      
    
    }
    else if(moverl==-1.0f){
        cam_pos.x -= (-Rvec.z) * mspeed;
        
        cam_pos.z -= Rvec.x * mspeed;
        
    }


    CNORM.x = 0.0f;
    CNORM.y = 1.0f;
    CNORM.z = 0.0f;
    
    //cout << '('<< LOOK.x<<',' << LOOK.y<< ','<< LOOK.z << ')' <<'\n';
    gluLookAt(cam_pos.x, cam_pos.y, cam_pos.z, LOOK.x, LOOK.y, LOOK.z, CNORM.x, CNORM.y, CNORM.z);
    //glRotatef(old_x_mouse, 1.0, 0.0, 0.0);
    //glRotatef(old_y_mouse, 0.0, 1.0, 0.0);
    glBegin(GL_TRIANGLES);
    
   
    for (auto face:objmap){
         
        //glColor3f(static_cast <float> (rand()) / static_cast <float> (RAND_MAX), static_cast <float> (rand()) / static_cast <float> (RAND_MAX), static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
        //glColor3f(1-abs(face.x.x),1-abs(face.y.x),1-abs(face.z.x));
        
        glNormal3f(face.normal.x,face.normal.y, face.normal.z);
        glVertex3f(face.x.x, face.x.y, face.x.z);
        glVertex3f(face.y.x, face.y.y, face.y.z);
        glVertex3f(face.z.x, face.z.y, face.z.z);
        const GLfloat mat[] = {0 , 0, 1, 1} ;
        glMaterialfv( GL_FRONT,GL_DIFFUSE,mat);
       // if(randhaus==1){
       //   for (auto faces:haus){
         
        //glColor3f(static_cast <float> (rand()) / static_cast <float> (RAND_MAX), static_cast <float> (rand()) / static_cast <float> (RAND_MAX), static_cast <float> (rand()) / static_cast <float> (RAND_MAX));
        //glColor3f(1-abs(face.x.x),1-abs(face.y.x),1-abs(face.z.x));
        
       // glNormal3f(face.normal.x,face.normal.y, face.normal.z);
       // glVertex3f(faces.x.x + faces.x.x, faces.x.y + face.x.y , faces.x.z + face.x.z);
      //  glVertex3f(faces.y.x + faces.y.x, faces.y.y + face.y.y, faces.y.z + face.y.z);
      //  glVertex3f(faces.z.x + faces.z.x, faces.z.y + face.z.y, faces.z.z + face.z.z);
     //   const GLfloat mat[] = {0 , 1, 0, 1} ;
     //   glMaterialfv( GL_FRONT,GL_DIFFUSE,mat);
    
   // }
        
      }
    
    
  
    
    
    
    
    
    
    
    glEnd();
    
    /*
    glBegin(GL_QUADS);
    glNormal3f(0,1,0);
    glVertex3f(1000,-1,1000);
    glVertex3f(1000,-1,-1000);
    glVertex3f(-1000,-1,-1000);
    glVertex3f(-1000,-1,1000);
    const GLfloat mat[] = {0 , 0, 1, 1} ;
        glMaterialfv( GL_FRONT,GL_DIFFUSE,mat);
        glEnd();
        
    */
    glutSwapBuffers();
    
    








}

void reshape(int w, int h)
{
    glViewport (0, 0, w, h);
    width = w;
    height = h;
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    gluPerspective(45.0f, (float)w/(float)h,1, 1000);
    
    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity ();


}
 vector<FACE> loadobj(string name){
  string line;
  ifstream myfile (name);
  if (myfile.is_open())
  {
      vector<POINT> vertices;
      vector<FACE> faces;
      vector<POINT> normals;

    while ( getline (myfile,line) )
    {
        
        
        if(line.substr(0,line.rfind(' ', 3))=="v"){
          
            
            int l3 = line.rfind(' ');
            int l2 = line.rfind(' ', l3-1);
            int l1 = line.rfind(' ', l2-1);
           
            float x = std::stof(line.substr(l1+1,l2-l1-1)) ;
            float y = std::stof(line.substr(l2+1, l3-l2-1));
            float z = std::stof(line.substr(l3+1, -1));
            
            
            POINT punkt = POINT();
                punkt.x = x;
                punkt.y = y;
                punkt.z = z;
                
                
                vertices.push_back(punkt);
                
        }else if(line.substr(0, line.rfind(' ',3))=="vn"){
            int l3 = line.rfind(' ');
            int l2 = line.rfind(' ', l3-1);
            int l1 = line.rfind(' ', l2-1);
           
            float x = std::stof(line.substr(l1+1,l2-l1-1)) ;
            float y = std::stof(line.substr(l2+1, l3-l2-1));
            float z = std::stof(line.substr(l3+1, -1));
            
            
            POINT normal = POINT();
                normal.x = x;
                normal.y = y;
                normal.z = z;
                
                
                normals.push_back(normal);
        }else if (line.substr(0, line.rfind(' ',3))=="f"){
            FACE face;
            int l3 = line.rfind(' ', line.rfind(' '));
            int l2 = line.rfind(' ', l3 - 1);
            int l1 = line.rfind(' ', l2 - 1);
            
            string one = line.substr(l1 + 1, l2 - l1 - 1);
            string two = line.substr(l2 + 1, l3 - l2 - 1);
            string three = line.substr(l3+1, -1);
            
            face.x = vertices[std::stoi(one.substr(0,one.rfind("//")))-1];
            face.y = vertices[std::stoi(two.substr(0,two.rfind("//")))-1];
            face.z = vertices[std::stoi(three.substr(0,three.rfind("//")))-1];
            face.normal = normals[std::stoi(one.substr(one.rfind("//") + 2, -1)) - 1];
            /*
            cout << std::stoi(one.substr(0,one.rfind("//"))) << '\n';
            cout << std::stoi(two.substr(0,two.rfind("//"))) << '\n';
            cout << std::stoi(three.substr(0,three.rfind("//"))) << '\n';
            cout << face[0].x<< '\n';
            cout << face[1].x<< '\n';
            cout << face[2].x<< '\n';
            */
            faces.push_back(face);
            
        }
    
    }
    myfile.close();
    
  
    
     
    
    
    return faces;
      }

  else cout << "Unable to open file"; 
  vector<FACE> m;
  return m;
}


    
    
    


    //loadtextfile
    
 
    









