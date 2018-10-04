#include <stdio.h>
#include "utilities.h"

struct dataPoint newDataPoint(int dim) {
    struct dataPoint element;
    element.data = (double*) malloc(dim * sizeof(double));
    for (int i = 0; i < dim; i++) {
        element.data[i] = 0;
    }
    return element;
}

struct dataPoint getElement(int dim, int idx, const double *data) {
    int data_idx = dim * idx;
    struct dataPoint element = newDataPoint(dim);
    int ele_idx = 0;
    for (int i = data_idx; i< data_idx + dim; i++) {
        element.data[ele_idx] = data[i];
    }

    return element;
}

double square(double n) {
    return n*n;
}

void printArray(int length, const double* data) {
    for(int i =0; i< length; i++) {
        printf("%d - %f \n", i, data[i]);
    }
}

void print2DimentionalArray(int n1, int n2, double** data) {
    for (int i =0; i< n1; i++) {
        printArray(n2, data[i]);
    }
}

void printDataSet(int dim, int ndata, const double *data) {
    for(int i = 0; i< ndata; i++) {
        printf("---%d----\n", i);
        struct dataPoint element = newDataPoint(dim);
        for (int j = dim*i ; j< dim * i + dim; j++){
            printf("%f \n", data[j]);
        }
    }
}
