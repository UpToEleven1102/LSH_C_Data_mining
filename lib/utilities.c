#include <stdio.h>
#include "utilities.h"

DataPoint *newDataPoint(int dim) {
    DataPoint *element = (DataPoint*)malloc(sizeof(DataPoint));
    element->data = (double*) malloc(dim * sizeof(double));
    for (int i = 0; i < dim; i++) {
        element->data[i] = 0;
    }
    return element;
}

DataPoint *getElement(int dim, int idx, const double *data) {
    int data_idx = dim * idx;
    DataPoint *element = newDataPoint(dim);
    int ele_idx = 0;
    for (int i = data_idx; i< data_idx + dim; i++) {
        element->data[ele_idx] = data[i];
        ele_idx++;
    }
    element->next = NULL;

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

void print2DimentionalArray(int m, int dim, double** array) {
    for (int i = 0; i < m; ++i) {
        printf("%d----\n", i);
        for (int j = 0; j < dim; ++j) {
            printf("%f \n", array[i][j]);
        }
    }
}

void printDataSet(int dim, int ndata, const double *data) {
    for(int i = 0; i< ndata; i++) {
        printf("---%d----\n", i);
        for (int j = dim*i ; j< dim * i + dim; j++){
            printf("%f \n", data[j]);
        }
    }
}

void printHashBuckets(int dim, int m, HashBucket* hashBucket){
    HashBucket *ite = hashBucket;
    printf("-----Buckets:------\n");
    while(ite != NULL) {
        printf("--cluster#: %d-- \n", ite->cluster_number-1);
        printf("-cluster hash val-\n");
        for (int i = 0; i < m; ++i) {
            printf("%d\n", ite->key[i]);
        }
        printf("-data points-\n");
        DataPoint *ite_data = ite->value;
        while(ite_data!=NULL){
            printf("--\n");
            for (int j = 0; j < dim; ++j) {
                printf("%f\n", ite_data->data[j]);
            }
            ite_data = ite_data->next;
        }
        ite = ite->next;
    }
}

void printResult(int dim, int m, int ndata, int n_cluster, int *cluster_start, int *cluster_size, int **cluster_hash_val, double *data){
    printf("\n\n Result: \n\n");
    printf("-cluster hash val & cluster size & cluster start-\n");
    for (int i = 0; i < n_cluster; ++i) {
        printf("\n\n\ncluster %d \n hash values: \n", i);
        for (int j = 0; j < m; ++j) {
            printf("%d\n", cluster_hash_val[i][j]);
        }
        printf("size: %d \n", cluster_size[i]);
        printf("start: %d \n", cluster_start[i]);
    }

    printf("-new data set- \n");
    printDataSet(dim, ndata, data);
}

