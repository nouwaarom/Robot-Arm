/* 
 * File:   denavit.h
 * Author: Davide Aversa
 *
 * Created on March 30, 2011, 8:00 PM
 */

#ifndef DENAVIT_H
#define	DENAVIT_H

#include <vector>

// TODO, make this a proper object
typedef struct {
    std::vector<double> matrix; // 4x4 matrix representing DH-Transformation for a
    double a;       // link in column-major order with parameters
    double alpha;   // a, alpha, d and theta.
    double d;
    double theta;
} dhmatrix;

// Compute a numeric DH-transformation matrix.
dhmatrix* updateMatrix(dhmatrix* dhm, double a, double alpha, double d, double theta);
dhmatrix* createMatrix(double a, double alpha, double d, double theta);
dhmatrix* createMatrix(std::vector<double> parameters);

#endif	/* DENAVIT_H */

