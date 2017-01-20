//
// Created by elbert on 19/01/17.
//

#ifndef ROBOT_ARM_CAMERA_H
#define ROBOT_ARM_CAMERA_H

#define WINDOWS_SIZE 500
#define WINDOWS_X_POSITION 100
#define WINDOWS_Y_POSITION 100

#define STEP 0.1f

#include "WorldObject.h"
#include "KeyListener.h"

class Camera : public WorldObject, public KeyListener
{
public:
    Camera();

    // Glut callbacks
    void reshape(int w, int h);

    void predraw() const;
    void postdraw() const;

    // Inherited from WorldObject
    void draw() const;
    void update(int deltaTime);
    // Inherited from KeyListener
    void notifyKeyEvent(unsigned char key, int x, int y);
protected:
private:
    /* Camera Position */
    float cameray = 5;
    float camerax = 0;
    float cameraz = -15;
    /* Current Camera Angle */
    float cameraangle = 0;
};

#endif //ROBOT_ARM_CAMERA_H
