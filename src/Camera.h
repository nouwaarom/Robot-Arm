//
// Created by elbert on 19/01/17.
//

#ifndef ROBOT_ARM_CAMERA_H
#define ROBOT_ARM_CAMERA_H

#define WINDOWS_SIZE 500
#define WINDOWS_X_POSITION 100
#define WINDOWS_Y_POSITION 100

#include <GL/glut.h>
#include <GL/gl.h>

#include "BMPImage.h"


class Camera
{
public:
    void init(int argc, char **argv);
    GLuint* getRobotTexture();
    // Glut callbacks
    void display();
    void reshape();
protected:
private:
    void LoadGLTextures();
    void drawFloor();
    /* Textures Buffer */
    GLuint texture[3];
    /* Camera Position */
    float cameray = 5;
    float camerax = 0;
    float cameraz = -15;
    /* Current Camera Angle */
    float cameraangle = 0;
};

#endif //ROBOT_ARM_CAMERA_H
