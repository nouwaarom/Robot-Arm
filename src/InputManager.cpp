//
// Created by elbert on 28/03/16.
//

#include "InputManager.h"
#include <iostream>

void InputManager::registerMouseListener(MouseListener* mouseListener)
{
    _mouseListeners.push_back(mouseListener);
}

void InputManager::unregisterMouseListener(MouseListener* mouseListener)
{
    _mouseListeners.remove(mouseListener);
}

void InputManager::mouseCallback(int eventType, int startEnd, int x, int y)
{
    for (MouseListener* mouseListener : _mouseListeners) {
        mouseListener->notifyMouseEvent(eventType, startEnd, x, y);
    }
}
