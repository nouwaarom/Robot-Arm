//
// Created by elbert on 11/01/17.
//

#ifndef ROBOTARM_CONTROLLERINTERFACE_H
#define ROBOTARM_CONTROLLERINTERFACE_H

#include <vector>


class ControllerInterface
{
public:
    double getAngle(int joint, int deltaTime);
    int setDenavitHartenbergParameters(std::vector<double> dhMatrix, int jointCount);
protected:
private:
};


#endif //ROBOTARM_CONTROLLERINTERFACE_H
