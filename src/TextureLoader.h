//
// Created by elbert on 20/01/17.
//

#ifndef ROBOT_ARM_TEXTURELOADER_H
#define ROBOT_ARM_TEXTURELOADER_H

#include <GL/glut.h>
#include <GL/gl.h>
#include "BMPImage.h"

class TextureLoader
{
public:
    void LoadGLTextures();
    GLuint getTexture(int index);
    GLuint* getTextures();
protected:
private:
    /* Textures Buffer */
    GLuint _texture[3];
};

#endif //ROBOT_ARM_TEXTURELOADER_H
