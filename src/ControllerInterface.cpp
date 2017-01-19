//
// Created by elbert on 11/01/17.
//

#include "ControllerInterface.h"
#include <stdint.h>

extern "C" double get_angle(int32_t joint);
extern "C" int32_t set_dh(double* dh_matrix, uint32_t joint_count);

double ControllerInterface::getAngle(int joint)
{
    return get_angle(joint);
}

int ControllerInterface::setDenavitHartenbergParameters(std::vector<double> dhMatrix, int jointCount)
{
    return set_dh(dhMatrix.data(), (uint32_t)jointCount);
}
