/*
 * File:   main.cpp
 * Author: Davide Aversa
 *
 * Created on March 30, 2011, 7:58 PM
 */

/* C/C++ Standard Includes */
#include <cstdlib>
#include <iostream>

/* OpenGL/GLUT Includes */
#include <GL/glut.h>
#include <GL/gl.h>
#include <math.h>

#include "denavit.h"
#include "RLink.h"
#include "Robot.h"
#include "Floor.h"
#include "Camera.h"
#include "ControllerInterface.h"
#include "WorldObject.h"
#include "World.h"
#include "TextureLoader.h"
#include "InputManager.h"

using namespace std;

/* Current Link */
int linksel = 0;

/* TABELLA DH [a alpha d theta] */

#define ROBOT 2

#if ROBOT==1 // 5R Robot
int numlink = 5; // Number of Link
bool zapproach = true; // End effector has approach direction along z?
vector<double> dh({0, pi2, 5.0,  0,
                   0, pi2, 0  ,  0,
                   0, pi2, 5.0,  0,
                   0, pi2, 0  ,  0,
                   0, 0  , 5.0,  0}); // DH Table
#endif

#if ROBOT==2 // 3R Antropomorphic Robot
int numlink = 3;
bool zapproach = false;
vector<double> dh({0  , -pi2, 0, 0,
                   4.0, 0   , 0, 0,
                   3.0,  pi2, 0, 0});
#endif

#if ROBOT==3 // 3R Spherical Wrist
int numlink = 3;
bool zapproach = true;
vector<double dh({0, pi2, 5.0, 0,
                  0, pi2,   0, 0,
                  0, 0  , 5.0, 0});
#endif

int main(int argc, char** argv)
{
    cout << "---------- ROBOT ARM v1.1 ----------" << endl;
    cout << "Developed by Davide Aversa." << endl;
    cout << "-----------" << endl;

    cout << "Starting Robot Arm Controller..." << endl;
    ControllerInterface* controllerInterface = new ControllerInterface();
    controllerInterface->setDenavitHartenbergParameters(dh, numlink);

    InputManager* inputManager = new InputManager();
    World* world = new World(inputManager);
    setGlutEventHandler(world, argc, argv);

    TextureLoader* loader = new TextureLoader();
    loader->LoadGLTextures();

    Camera* camera = new Camera();
    world->addObject(static_cast<WorldObject*>(camera));
    world->getInputManager()->registerKeyListener(static_cast<KeyListener*>(camera));

    Floor* floor = new Floor(loader->getTexture(2));
    world->addObject(static_cast<WorldObject*>(floor));

    Robot* robot = new Robot(numlink, dh, zapproach, loader->getTextures());
    world->addObject(static_cast<WorldObject*>(robot));
    world->getInputManager()->registerKeyListener(static_cast<KeyListener*>(robot));

    cout << "Starting Simulator..." << endl;
    world->start();

    return EXIT_SUCCESS;
}

