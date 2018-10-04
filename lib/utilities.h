#ifndef LSH_UTILITIES_H
#define LSH_UTILITIES_H

#include <malloc.h>

struct dataPoint {
    double *data;
};

struct dataPoint newDataPoint(int dim);
struct dataPoint getElement(int dim, int idx, const double *data);

double square(double n);

void printArray(int length, const double* data);
void print2DimentionalArray(int n1, int n2, double **data);
void printDataSet(int dim, int ndata, const double *data) ;

#endif //LSH_UTILITIES_H
