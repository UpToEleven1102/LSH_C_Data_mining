#ifndef LSH_UTILITIES_H
#define LSH_UTILITIES_H

#include <malloc.h>

typedef int bool;
#define true 1
#define false 0

typedef struct DataPoint DataPoint, ListDataPoint;

struct DataPoint {
    double *data;
    int cluster_number;
    DataPoint *next;
};

typedef struct HashValue HashValue, ListHashValue;

struct HashValue {
    int *value;
    HashValue *next;
};

DataPoint newDataPoint(int dim);
DataPoint getElement(int dim, int idx, const double *data);

double square(double n);

void printArray(int length, const double* data);
void print2DimentionalArray(int n1, int n2, double **data);
void printDataSet(int dim, int ndata, const double *data) ;

#endif //LSH_UTILITIES_H
