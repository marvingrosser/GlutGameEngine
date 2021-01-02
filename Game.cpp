/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.cpp
 * Author: marvin
 * 
 * Created on January 1, 2021, 6:55 PM
 */

#include "Game.h"

Game::Game(){
    spieler = new spieler();
    scene = new szene();
}
Game::Game(player spieler, szene scene){
    this->spieler = spieler;
    this->scene = scene;
}
Game::init(){
    glutInit(&argc, argv);//init opengl
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH | GLUT_MULTISAMPLE); //was wollen wir wie ausgeben
    glutInitWindowSize(800, 600); //fenstergröße
    glutInitWindowPosition(0,0); //wo wird Fenster gespawnt
    glutCreateWindow("game"); //Spawn window mit Name: "game"
    glutKeyboardUpFunc(releaseKey); // anbinden der releaseKey an event wenn ein Key losgelassen wird
    glutIgnoreKeyRepeat(1); //wenn eine taste gehalten wird: kein rumspammen (wie wenn du in word eine Taste gedrückt hältst--> das verhindern)
    glutDisplayFunc(render); //renderfunktion anbinden
    glutIdleFunc(render);// ||
    glutReshapeFunc (reshape);//anbinden der reshape funktion
    glutKeyboardFunc(keyboard);//Keyboard funktion anbinden


        cam_pos.x = 0.0f; //Cameraursprungsposition
    cam_pos.y = 0.0f;
    cam_pos.z = 5.0f;

    glutPassiveMotionFunc(mouse); //mouse funktion einbinden
    glEnable(GLUT_MULTISAMPLE);//multisample Antialising MSAA
    glClearColor(0.0, 0.0, 0.0, 0.0); //Dspl clear
    glEnable(GL_DEPTH_TEST);//Überprüfen des Rendervorgangs, (nach Fragmentshader) [dazu muss auch GLUT_DEPTH in DIsplay mode stehen]

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); //"Hohe Grafikqualität" bei der Perspektivkorrektion
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);


  GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};  /* Licht*/

  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse); //Init Licht
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glEnable(GL_LIGHT0);//Licht an
  glEnable(GL_LIGHTING); //Lichtrendern an
  glShadeModel(GL_SMOOTH); //smooth shading


  /* Setup the view of the cube. */
  glMatrixMode(GL_PROJECTION); //Viewmatrix setup

  glutSetCursor(GLUT_CURSOR_NONE); //Mauszeiger verschwinden lassen
    glutMainLoop(); //renderloop
}
Game::render(){
}
