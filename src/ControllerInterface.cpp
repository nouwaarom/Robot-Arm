//
// Created by elbert on 11/01/17.
//

#include "ControllerInterface.h"
#include <stdint.h>

extern "C" double get_angle(int32_t joint, int32_t delta_time);
extern "C" int32_t set_dh(double* dh_matrix, uint32_t joint_count);

double ControllerInterface::getAngle(int joint, int deltaTime)
{
    return get_angle(joint, deltaTime);
}

int ControllerInterface::setDenavitHartenbergParameters(std::vector<double> dhMatrix, int jointCount)
{
    return set_dh(dhMatrix.data(), (uint32_t)jointCount);
}
