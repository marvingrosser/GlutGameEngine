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

#include "../headers/Game.h"

int main(int argc, char** argv) {
    Game myGame= * new Game();
    myGame.init();
    return 0;
}
