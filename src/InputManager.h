//
// Created by elbert on 28/03/16.
//

#ifndef ROBOT_ARM_INPUTMANAGER_H
#define ROBOT_ARM_INPUTMANAGER_H

#include <functional>
#include <list>

#include "MouseListener.h"
#include "KeyListener.h"


class InputManager
{
public:
    void registerMouseListener(MouseListener* mouseListener);
    void unregisterMouseListener(MouseListener* mouseListener);

    void registerKeyListener(KeyListener* keyListener);
    void unregisterKeyListener(KeyListener* keyListener);

    void mouseCallback(int eventType, int startEnd, int x, int y);
    void keyCallback(unsigned char key, int x, int y);
protected:
private:
    std::list<MouseListener*> _mouseListeners;
    std::list<KeyListener*> _keyListeners;
};


#endif // ROBOT_ARM_INPUTMANAGER_H
