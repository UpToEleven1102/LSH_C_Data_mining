#ifndef LSH_UTILITIES_H
#define LSH_UTILITIES_H

#include <malloc.h>

typedef int bool;
#define true 1
#define false 0

typedef struct DataPoint DataPoint;

struct DataPoint {
    double *data;
    int cluster_number;
    DataPoint *next;
};

typedef struct HashBucket HashBucket, HashBuckets;

struct HashBucket {
    int *key;
    DataPoint *value;
    int cluster_number;
    int cluster_size;
    HashBucket *next;
};


DataPoint *newDataPoint(int dim);
DataPoint *getElement(int dim, int idx, const double *data);

double square(double n);

void printArray(int length, const double* data);
void printDataSet(int dim, int ndata, const double *data) ;
void printHashBuckets(int dim, int m, HashBucket* hashBucket);
void printResult(int dim, int m, int ndata, int n_cluster, int *cluster_start, int *cluster_size, int **cluster_hash_val, double *data);


#endif //LSH_UTILITIES_H
