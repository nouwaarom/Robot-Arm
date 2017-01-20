//
// Created by elbert on 20/01/17.
//
#include "TextureLoader.h"
#include <iostream>

void TextureLoader::LoadGLTextures()
{
    // Load Three Textures From File!
    std::cout << "Loading Textures..." << std::endl;
    std::cout << "-------------------" << std::endl;
    BMPImage *image1 = new BMPImage();
    BMPImage *image2 = new BMPImage();
    BMPImage *image3 = new BMPImage();

    if (!image1->loadImage("./res/copper.bmp")) {
        exit(1);
    }

    if (!image2->loadImage("./res/zink.bmp")) {
        exit(1);
    }

    if (!image3->loadImage("./res/chess.bmp")) {
        exit(1);
    }

    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

    glTexEnvf(GL_TEXTURE_ENV,GL_TEXTURE_ENV_MODE,GL_MODULATE);

    // Create Texture
    glGenTextures(3, &_texture[0]);
    glBindTexture(GL_TEXTURE_2D, _texture[0]);   // 2d texture (x and y size)
    // 2d texture, level of detail 0 (normal), 3 components (red, green, blue), x size from image, y size from image,
    // border 0 (normal), rgb color data, unsigned byte data, and finally the data itself.

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smaller than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image1->getX(), image1->getY(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image1->getData());

    glBindTexture(GL_TEXTURE_2D, _texture[1]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image2->getX(), image2->getY(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image2->getData());

    glBindTexture(GL_TEXTURE_2D, _texture[2]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image3->getX(), image3->getY(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image3->getData());

    delete image1;
    delete image2;
    delete image3;
    std::cout << "-------------------" << std::endl;
};

GLuint TextureLoader::getTexture(int index)
{
    return _texture[index];
}

GLuint* TextureLoader::getTextures()
{
    return _texture;
}

