//
// Created by elbert on 28/03/16.
//

#ifndef TOWERDEFENCE_INPUTMANAGER_H
#define TOWERDEFENCE_INPUTMANAGER_H

#include <functional>
#include <list>

#include "MouseListener.h"


class InputManager
{
public:
    void registerMouseListener(MouseListener* mouseListener);
    void unregisterMouseListener(MouseListener* mouseListener);

    void mouseCallback(int eventType, int startEnd, int x, int y);
protected:
private:
    std::list<MouseListener*> _mouseListeners;
};


#endif //TOWERDEFENCE_INPUTMANAGER_H
