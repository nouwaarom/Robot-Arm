//
// Created by elbert on 29/03/16.
//

#ifndef ROBOT_ARM_KEYLISTENER_H
#define ROBOT_ARM_KEYLISTENER_H


class KeyListener
{
public:
    virtual ~KeyListener();
    virtual void notifyKeyEvent(unsigned char key, int x, int y) = 0;
protected:
private:
};


#endif //ROBOT_ARM_KEYLISTENER_H
