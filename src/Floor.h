//
// Created by elbert on 20/01/17.
//

#ifndef ROBOT_ARM_FLOOR_H
#define ROBOT_ARM_FLOOR_H

#include "WorldObject.h"

class Floor : public WorldObject
{
public:
    Floor(GLuint texture);
    void update(int deltaTime);
    void draw() const;
protected:
private:
    GLuint _texture;
};

#endif //ROBOT_ARM_FLOOR_H
