//
// Created by elbert on 20/01/17.
//

#ifndef ROBOT_ARM_WORLD_H
#define ROBOT_ARM_WORLD_H

#include <list>

#include <GL/glut.h>

#include "InputManager.h"
#include "WorldObject.h"

class World;
class WorldObject;

void setGlutEventHandler(World* world, int argc, char** argv);

void _display();
void _reshape(int w, int h);
void _idle();
void _keycontrol(unsigned char key, int x, int y);
void _mousecontrol(int eventType, int startEnd, int x, int y);

class World
{
public:
    World(InputManager* inputManager);

    void start();
    void update(int deltaTime);
    // Glut callbacks
    void display() const;
    void reshape(int w, int h);
    void idle();

    InputManager* getInputManager();

    void addObject(WorldObject* object);
    WorldObject* getObjectById(char id) const;
protected:
private:
    std::list<WorldObject*> _objects;
    InputManager* _inputManager;
};

#endif //ROBOT_ARM_WORLD_H
