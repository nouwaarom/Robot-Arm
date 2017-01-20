//
// Created by elbert on 29/03/16.
//

#ifndef TOWERDEFENCE_MOUSELISTENER_H
#define TOWERDEFENCE_MOUSELISTENER_H


class MouseListener
{
public:
    virtual void notifyMouseEvent(int eventType, int startEnd, int x, int y) = 0;
protected:
private:
};


#endif //TOWERDEFENCE_MOUSELISTENER_H
