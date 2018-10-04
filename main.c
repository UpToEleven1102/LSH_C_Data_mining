#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "lib/utilities.h"

int generateDataSet(int dim, int ndata, double *data) {
    for (int i = 0; i < dim * ndata; i++) {
        data[i] = (double) (rand() % 10) / 10;
    }
}

double *newUnitVector(int dim) {
    double *unitVector = (double*) malloc(dim * sizeof(double));
    //generate unit vector
    generateDataSet(dim, 1, unitVector);

    double vectorLength = 0;
    for (int i = 0; i < dim; ++i) {
        vectorLength += square(unitVector[i]);
    }
    vectorLength = sqrt(vectorLength);

    for (int i = 0; i < dim; ++i) {
        unitVector[i] = unitVector[i]/vectorLength;
    }

    return unitVector;
}

double **generateHashFunctionSet(int m, int dim) {
    double **h = (double**) malloc(m * sizeof(double*));
    for (int i = 0; i< m; i++) {
        h[i] = newUnitVector(dim);
    }

    return h;
}

int main() {
    srand(time(NULL));

    const int DIM = 4;
    const int N_DATA = 20;
    const int M = 2;
    const double W = .25;

    double *data, **h;
    data = (double *) malloc(DIM*N_DATA * sizeof(double));

    generateDataSet(DIM, N_DATA, data);

    //TODO: remove after testing
    //printDataSet(DIM, N_DATA, data);

    h = generateHashFunctionSet(M, DIM);
    print2DimentionalArray(M, DIM, h);

    int *n_cluster_ptr, **cluster_start, **cluster_size, **cluster_hash_val;


    return 0;
}