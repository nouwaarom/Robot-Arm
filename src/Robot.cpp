/* 
 * File:   Robot.cpp
 * Author: Davide Aversa
 * 
 * Created on March 30, 2011, 9:44 PM
 */

#include "Robot.h"
#include "RLink.h"

#include <GL/freeglut_std.h>

Robot::Robot(int numlink, std::vector<double> dhtable, bool zapproach, GLuint* textures) : WorldObject('R')
{
    this->linklist = new RLink*[numlink];
    this->numlink = numlink;
    this->textures = textures;
    this->zapproach = zapproach;
    _linksel = 0;
    for (int i=0; i<numlink; i++) {
        std::vector<double> dhrow(dhtable.begin()+i*4, dhtable.begin()+i*4+4);
        linklist[i] = new RLink(dhrow);
        linklist[i]->setTextures(textures);
    }
}


Robot::~Robot()
{
}

void Robot::draw() const
{
    glPushMatrix();
    // This matrix change orientation of axis: Z-up, X-right, Y-oots
    GLdouble t[] = {-1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1}; 
    glMultMatrixd(t);
    
    for (int i=0;i<this->numlink;++i) {
        this->linklist[i]->draw();
    }    
    
    //glRotated(1.9,1,1,0);
    this->drawEndEffector();
    
    glPopMatrix();
}

void Robot::updateQ(int idlink, double newq)
{
    this->linklist[idlink]->updateQ(newq);
}

double Robot::getQ(int idlink)
{
    return this->linklist[idlink]->getQ();
}

void Robot::drawEndEffector() const
{
    glEnable(GL_TEXTURE_GEN_S);
    glEnable(GL_TEXTURE_GEN_T);
    
    glBindTexture(GL_TEXTURE_2D, this->textures[0]);
    
    glTexGeni(GL_S,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
    glTexGeni(GL_T,GL_TEXTURE_GEN_MODE,GL_OBJECT_LINEAR);
    
    if (!this->zapproach) {
        GLdouble t[] = {0,0,1,0,0,-1,0,0,1,0,0,0,0,0,0,1}; 
        glMultMatrixd(t);
    }
    
    glPushMatrix();
    glTranslated(0,0.5,0);
    glutSolidCone(0.4,2,20,20);
    glPopMatrix();
    
    glPushMatrix();
    glTranslated(0,-0.5,0);
    glutSolidCone(0.4,2,20,20);
    glPopMatrix();
    
    glDisable(GL_TEXTURE_GEN_S);
    glDisable(GL_TEXTURE_GEN_T);
}

// FIXME, do this based on input
void Robot::update(int deltaTime)
{
    double q = 0;
    for (int i=0;i<this->numlink;i++) {
        this->linklist[i]->update(q);
    }
}

void Robot::notifyKeyEvent(unsigned char key, int x, int y)
{
    double newQ;

    switch (key) {
        case '+': /* Select Next Link */
            _linksel = (_linksel + 1) % numlink;
            break;
        case '-': /* Select Previous Link */
            _linksel = (_linksel - 1);
            if (_linksel<0) _linksel = numlink - 1;
            break;
        case 'p': /* Increment q-value for selected link. */
            newQ = getQ(_linksel) + 0.1;
            if (newQ > 2*pi2) {
                newQ = -2*pi2;
            }
            updateQ(_linksel, newQ);
            glutPostRedisplay();
            break;
        case 'o': /* Decrement q-value for selected link. */
            newQ = getQ(_linksel) - 0.1;
            if (newQ < -2*pi2) {
                newQ = 2*pi2;
            }
            updateQ(_linksel, newQ);
            glutPostRedisplay();
            break;
        default:
            break;
    }
}
