//
// Created by elbert on 29/03/16.
//

#ifndef ROBOT_ARM_MOUSELISTENER_H
#define ROBOT_ARM_MOUSELISTENER_H


class MouseListener
{
public:
    virtual ~MouseListener();
    virtual void notifyMouseEvent(int eventType, int startEnd, int x, int y) = 0;
protected:
private:
};


#endif //ROBOT_ARM_MOUSELISTENER_H
