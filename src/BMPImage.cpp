/*
 * File:   BMPImage.cpp
 * Author: Davide Aversa
 *
 * Created on April 6, 2011, 4:47 PM
 */

#include "BMPImage.h"

#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

using namespace std;

BMPImage::BMPImage() {
}

BMPImage::BMPImage(const BMPImage& orig) {
}

BMPImage::~BMPImage() {
}

int BMPImage::loadImage(string strfilename)
{
    const char *filename = strfilename.c_str();

    cout << "Loading texture: " << strfilename << endl;

    int n;
    this->data = stbi_load(filename, &this->sizeX, &this->sizeY, &n, 0);


    // we're done.
    return 1;
}

unsigned char* BMPImage::getData() {
    return this->data;
}

int BMPImage::getX(){
    return this->sizeX;
}

int BMPImage::getY() {
    return this->sizeY;
}
