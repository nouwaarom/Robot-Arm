//
// Created by elbert on 20/01/17.
//

#ifndef ROBOT_ARM_WORLDOBJECT_H
#define ROBOT_ARM_WORLDOBJECT_H

#include <GL/glut.h>
#include <GL/gl.h>

#include "World.h"

class World;

class WorldObject
{
public:
    WorldObject(char id);
    virtual ~WorldObject();
    void setWorld(World* world);
    char getId();
    bool isKeyListener();
    bool isMouseListener();

    virtual void update(int deltaTime) = 0;
    virtual void draw() const = 0;
protected:
    void setIsKeyListener();
    void setIsMouseListener();
private:
    World* _world;
    char _id;

    bool _isKeyListener = false;
    bool _isMouseListener = false;
};

#endif //ROBOT_ARM_WORLDOBJECT_H
