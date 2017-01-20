//
// Created by elbert on 20/01/17.
//
#include "Floor.h"


Floor::Floor(GLuint texture): WorldObject('F')
{
    _texture = texture;
}

void Floor::update(int deltaTime)
{
   return;
}

void Floor::draw() const
{
    glBindTexture(GL_TEXTURE_2D, _texture);

    float size = 20.0;
    float txsize = 5.0;
    glBegin(GL_QUADS);
        glNormal3f(0.0, 1.0, 0.0);
        glTexCoord2f(0,0);
        glVertex3d(size,0,size);
        glTexCoord2f(0,txsize);
        glVertex3d(size,0,-size);
        glTexCoord2f(txsize,txsize);
        glVertex3d(-size,0,-size);
        glTexCoord2f(txsize,0);
        glVertex3d(-size,0,size);
    glEnd();
}
