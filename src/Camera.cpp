//
// Created by elbert on 19/01/17.
//
#include "Camera.h"

#include <iostream>


Camera::Camera() : WorldObject('C')
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(WINDOWS_SIZE,WINDOWS_SIZE);
    glutInitWindowPosition(WINDOWS_X_POSITION,WINDOWS_Y_POSITION);
    glutCreateWindow("ROBOT ARMS v1.1");

    /* Material and lights */
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0};
    GLfloat mat_shininess[] = { 25.0};
    GLfloat light_position[] = { 20.0, 20.0, 20.0, 0.0};
    GLfloat white_light[] = { 1, 1, 1, 1.0 };

    glClearColor(0.8,0.8,1.0,1.0);
    glClearDepth(10.0);
    glShadeModel(GL_SMOOTH);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);

    /* Enable */
    glEnable(GL_LIGHTING);
    glEnable(GL_NORMALIZE);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_CULL_FACE);
    glEnable(GL_FOG);
    glDepthMask(GL_TRUE);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    /* Fog */
    GLfloat fogColor[4]= {0.8f, 0.8f, 1.0f, 1.0f};	// Fog Color
    glFogi(GL_FOG_MODE, GL_LINEAR);                 // Fog Mode
    glFogfv(GL_FOG_COLOR, fogColor);			    // Set Fog Color
    glFogf(GL_FOG_DENSITY, 0.3f);                   // How Dense Will The Fog Be
    glHint(GL_FOG_HINT, GL_DONT_CARE);			    // Fog Hint Value
    glFogf(GL_FOG_START,10.0f);				        // Fog Start Depth
    glFogf(GL_FOG_END, 40.0f);				        // Fog End Depth
}

void Camera::notifyKeyEvent(unsigned char key, int x, int y)
{
    switch (key) {
        case 'd' : /* Turn Right */
            cameraangle = cameraangle - (STEP * 10);
            glutPostRedisplay();
            break;
        case 'a' : /* Turn Left */
            cameraangle = cameraangle + (STEP * 10);
            glutPostRedisplay();
            break;
        default:
            break;
    }
}

void Camera::predraw() const
{
    /* Clear Screen */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);
    /* Camera Transformation */
    glLoadIdentity();
    glPushMatrix();
    gluLookAt(camerax,cameray,cameraz,camerax,cameray,cameraz + 5,0,1,0);
    glRotated(cameraangle, 0, 1, 0);
}

void Camera::draw() const
{
}

void Camera::postdraw() const
{
    /* Pop Matrix */
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

void Camera::reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0,(GLsizei) w/(GLsizei) h, 0.1, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Camera::update(int deltaTime)
{

}
