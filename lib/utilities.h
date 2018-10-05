#ifndef LSH_UTILITIES_H
#define LSH_UTILITIES_H

#include <malloc.h>

typedef int bool;
#define true 1
#define false 0

struct DataPoint {
    double *data;
    struct DataPoint *next;
};

struct LinkedListDataPoint {
    struct DataPoint *first, *last;
    int size;
};

struct LinkedListMap {
    struct Map *first, *last, *iterator;
    int size;
};

struct Map {
    int *key;
    struct LinkedListDataPoint value;
    int size;
};

struct DataPoint newDataPoint(int dim);
struct DataPoint getElement(int dim, int idx, const double *data);

double square(double n);

void printArray(int length, const double* data);
void print2DimentionalArray(int n1, int n2, double **data);
void printDataSet(int dim, int ndata, const double *data) ;

#endif //LSH_UTILITIES_H
