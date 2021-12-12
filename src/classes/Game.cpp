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

#include "../headers/Game.h"
#define GLEW_STATIC
//SPieler nur in scene!!!
player Game::spieler{ * new player(1920,1080,0.002, 0.1)};
szene Game::scene{ * new szene()};
Game::Game(){
    Game::spieler = * new player(1920,1080,0.002, 0.1);
    Game::scene = * new szene();
};
Game::Game(player spieler, szene scene){
    Game::spieler = spieler;
    Game::scene = scene;
    Game::scene.setPlayer(this->spieler);
};
void Game::loadObjs(){
    //Game::scene.addObjFromFile("src/data/objects/axes.obj","src/data/textures/scifi2/");
    Game::scene.addObjFromFile("src/data/objects/lamp.obj","src/data/textures/lava/");
    //Game::scene.addObjFromFile("src/data/objects/land.obj","src/data/textures/scifi2/");
    Game::scene.addObjFromFile("src/data/objects/gang.obj","src/data/textures/scifi2/");
};
void Game::releaseKey(unsigned char key, int x, int y){
    Game::spieler.releaseKey(key,x,y);
};
void Game::reshape(int w, int h){
    Game::spieler.reshape(w,h);
};
void Game::keyboard(unsigned char key, int x, int y){
    Game::spieler.keyboard(key,x,y);
};
void Game::mouse(int x, int y){
    Game::spieler.mouse(x,y);
};
void Game::init(){

    glewExperimental = GL_TRUE ;
    int x=0;
    char *b = 0;
    
    glutInit(&x,  & b);//init opengl
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE); //was wollen wir wie ausgeben 
   
    //glutInitWindowSize(1920, 1080); //fenstergröße
    //glutInitWindowPosition(0,0); //wo wird Fenster gespawnt
    //glutCreateWindow("game"); //Spawn window mit Name: "game"
    
    glutGameModeString(":@60");
    glutEnterGameMode();
    
    glEnable(GLUT_MULTISAMPLE);//multisample Antialising MSAA
    //glClearColor(0.0, 0.0, 0.0, 0.0); //Dspl clear
    glEnable(GL_DEPTH_TEST);//Überprüfen des Rendervorgangs, (nach Fragmentshader) [dazu muss auch GLUT_DEPTH in DIsplay mode stehen]

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); //"Hohe Grafikqualität" bei der Perspektivkorrektion
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    /*
    GLfloat light_diffuse[] = {1.0, 1.0, 1.0, 1.0};  
    GLfloat light_pos[] = {1.0, 1.0, 1.0, 1.0};

    glLightfv(GL_LIGHT0, GL_POSITION,light_pos ); //Init Licht
    
    glEnable(GL_LIGHT0);//Licht an
    glEnable(GL_LIGHTING); //Lichtrendern an
    glShadeModel(GL_SMOOTH); //smooth shading
    */

    /* Setup the view of the cube. */
    //glMatrixMode(GL_PROJECTION); //Viewmatrix setup

    
    GLenum err = glewInit();
    if (err != GLEW_OK)
        exit(1); // or handle the error in a nicer way
    if (!GLEW_VERSION_2_1)  // check that the machine supports the 2.1 API.
        exit(1); // or handle the error in a nicer way
    this->scene.initShader("src/shaders/vertex_shader.glsl","src/shaders/fragment_shader.glsl");
    this->loadObjs();
    glutKeyboardUpFunc(Game::releaseKey); // anbinden der releaseKey an event wenn ein Key losgelassen wird
    glutIgnoreKeyRepeat(1); //wenn eine taste gehalten wird: kein rumspammen (wie wenn du in word eine Taste gedrückt hältst--> das verhindern)
    glutDisplayFunc(Game::render); //renderfunktion anbinden
    glutIdleFunc(Game::render);// ||
    glutReshapeFunc (Game::reshape);//anbinden der reshape funktion
    glutKeyboardFunc(Game::keyboard);//Keyboard funktion anbinden
    
    


    glutPassiveMotionFunc(Game::mouse); //mouse funktion einbinden
    glutSetCursor(GLUT_CURSOR_NONE); //Mauszeiger verschwinden lassen
    //Shader sh = * new Shader();
    glutMainLoop(); //renderloop
}
void Game::render(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Bufferclearing
    //glLoadIdentity(); //Identitymatrix laden (die mit diagonal 1en)
    
    Game::spieler.renderMouseKeyboard();
    GLuint id = Game::scene.getObjectByID(0).getShader();
    Game::spieler.render(Game::scene.getShader());
     
    Game::scene.render();
    
    
    glutSwapBuffers();
    //glutPostRedisplay();
    
}
