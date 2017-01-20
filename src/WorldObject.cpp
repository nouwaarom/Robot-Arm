//
// Created by elbert on 20/01/17.
//
#include "WorldObject.h"

WorldObject::WorldObject(char id)
{
   _id = id;
}

WorldObject::~WorldObject()
{

}

void WorldObject::setWorld(World* world)
{
    _world = world;
}

char WorldObject::getId()
{
    return _id;
}
