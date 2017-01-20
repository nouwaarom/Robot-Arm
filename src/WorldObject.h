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

    virtual void update(int deltaTime) = 0;
    virtual void draw() const = 0;
protected:
private:
    World* _world;
    char _id;
};

#endif //ROBOT_ARM_WORLDOBJECT_H
