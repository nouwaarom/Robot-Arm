#include"denavit.h"
#include<math.h>

#include<iostream>

using namespace std;

dhmatrix* updateMatrix(dhmatrix* dhm, double a, double alpha, double d, double theta)
{
    dhm->a = a;
    dhm->alpha = alpha;
    dhm->d = d;
    dhm->theta = theta;

    dhm->matrix = {
        cos(theta),             sin(theta),             0,          0,
        -sin(theta)*cos(alpha), cos(theta)*cos(alpha),  sin(alpha), 0,
        sin(theta)*sin(alpha),  -cos(theta)*sin(alpha), cos(alpha), 0,
        a*cos(theta),           a*sin(theta),           d,          1
    };

    return dhm;
}

dhmatrix* createMatrix(double a, double alpha, double d, double theta)
{
    dhmatrix* result = new dhmatrix;
    result->a = a;
    result->alpha = alpha;
    result->d = d;
    result->theta = theta;
    
    // First Row
    result->matrix = {
        cos(theta),             sin(theta),             0,          0,
        -sin(theta)*cos(alpha), cos(theta)*cos(alpha),  sin(alpha), 0,
        sin(theta)*sin(alpha),  -cos(theta)*sin(alpha), cos(alpha), 0,
        a*cos(theta),           a*sin(theta),           d,          1
    };

    return result;
}

dhmatrix* createMatrix(std::vector<double> parameters) {
    return createMatrix(parameters[0], parameters[1], parameters[2], parameters[3]);
}
