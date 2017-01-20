//
// Created by elbert on 19/01/17.
//
#include "Renderer.h"

#include <iostream>


GLuint* Renderer::getRobotTexture()
{
    return texture;
}

void Renderer::init(int argc, char** argv)
{
    glutInit(&argc,argv);
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

    LoadGLTextures();
}

void Renderer::LoadGLTextures()
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
    glGenTextures(3, &texture[0]);
    glBindTexture(GL_TEXTURE_2D, texture[0]);   // 2d texture (x and y size)
    // 2d texture, level of detail 0 (normal), 3 components (red, green, blue), x size from image, y size from image,
    // border 0 (normal), rgb color data, unsigned byte data, and finally the data itself.

    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR); // scale linearly when image bigger than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR); // scale linearly when image smaller than texture
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image1->getX(), image1->getY(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image1->getData());

    glBindTexture(GL_TEXTURE_2D, texture[1]);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image2->getX(), image2->getY(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image2->getData());

    glBindTexture(GL_TEXTURE_2D, texture[2]);
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

/* Draw a simple chess floor. */
void Renderer::drawFloor()
{
    glBindTexture(GL_TEXTURE_2D, texture[2]);

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

void Renderer::display(void)
{
    /* Clear Screen */
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);

    /* Camera Transformation */
    glLoadIdentity();
    glPushMatrix();
    gluLookAt(camerax,cameray,cameraz,camerax,cameray,cameraz + 5,0,1,0);
    glRotated(cameraangle, 0, 1, 0);

    /* Drawing Object */
    drawFloor();
    r->draw();

    /* Pop Matrix */
    glPopMatrix();

    glFlush();
    glutSwapBuffers();
}

void Renderer::reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0,(GLsizei) w/(GLsizei) h, 0.1, 100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}
