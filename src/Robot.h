/* 
 * File:   Robot.h
 * Author: Davide Aversa
 *
 * Created on March 30, 2011, 9:44 PM
 */

#ifndef ROBOT_H
#define	ROBOT_H

#include <GL/gl.h>
#include <vector>

#include "denavit.h"
#include "RLink.h"
#include "ControllerInterface.h"
#include "WorldObject.h"
#include "KeyListener.h"

#define pi2 11.0/7.0

/**
 * Class Robot.
 */
class Robot : public WorldObject, public KeyListener
{
public:
    /**
     * Constructor.
     * 
     * @param numlink  : Number of links.
     * @param dhtable  : A matrix representing a DH-Table.
     * @param textures : Textures array.
     */
    Robot(int numlink, std::vector<double> dhtable, bool zapproach, GLuint* textures);
    virtual ~Robot();
    
    /**
     * Return the q value for the selected link.
     *
     * @param idlink : ID of the selected link.
     * @return The q value of the link.
     */
    double getQ(int idlink);
    
    /**
      * Update the q value for the selected link.
      *
      * @param idlink : ID of the selected link.
      * @param newq   : New q value.
      */
    void updateQ(int idlink, double newq);

    /**
      * Update every link in the robot according to the kinematic velocity.
      */
    void update(int deltaTime);

    /**
      * Draw every link in the robot.
      */
    void draw() const;
private:
    RLink** linklist; /* List of Link */
    int numlink;      /* Total number of the link */
    int _linksel;
    GLuint* textures; /* Textures Array */
    bool zapproach;   /* True if robot approach along the z axis */
    ControllerInterface* _controllerInterface;
    
    /*
     * This private method draws the end-effector.
     */
    void drawEndEffector() const;

    // Inherited from KeyListener
    void notifyKeyEvent(unsigned char key, int x, int y);

};

#endif	/* ROBOT_H */

