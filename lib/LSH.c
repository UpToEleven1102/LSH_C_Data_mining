
#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include "LSH.h"
#include "utilities.h"

double innerProduct(int dim, double *v1, double *v2) {
    double product = 0;
    printf("debug dim : %d \n", dim);
    for (int i = 0; i < dim; i++) {
        printf("v1: %f - v2: %f \n", v1[i], v2[i]);
        product += v1[i] * v2[i];
    }

    return product;
}

int *calculateHashValue(int dim, int m, int idx, double w, double *data, double **h) {

    struct DataPoint element = getElement(dim, idx, data);

    int *hashValue = (int *) malloc(m * sizeof(int));

    for (int i = 0; i < m; i++) {
        double product = innerProduct(dim, element.data, h[i]);
        hashValue[i] = (int)(product / w);
    }

    return hashValue;
}

bool equalHashValue(int m, int* o1, int* o2) {
    bool equal = true;
    for (int i = 0; i < m; ++i) {
        if(o1[i] != o2[i]) {
            equal = false;
            break;
        }
    }

    return equal;
}

int LSH(int dim, int ndata, double *data, int m, double w, double **h, int **n_cluster_ptr, int **cluster_start,
        int **cluster_size, int ***cluster_hash_val) {
    //cluster_hash_val =
    *n_cluster_ptr = (int*) malloc(sizeof(int));
    int n_cluster = 0;

    struct LinkedListMap hashBucket = {.first = NULL, .last = NULL, .size = 0, .iterator = NULL};

    bool keyFound = false;

    for(int i= 0; i< ndata; i++) {
        int *hashValue = calculateHashValue(dim, m, i, w, data, h);

        for(int j = 0; j< hashBucket.size; j++){
            struct Map *iterator = hashBucket.first;
            if(equalHashValue(m, hashValue, iterator->key) == true){
                if(iterator->value.size == 0) {
                    struct LinkedListDataPoint listDataPoint = {.size = 0, .first = NULL, .last = NULL};
                    iterator->value = listDataPoint;
                    struct DataPoint dataPoint = getElement(dim, i, data);
                    dataPoint.next = NULL;
                    iterator->value.first = &dataPoint;
                    iterator->value.last = &dataPoint;
                } else {
                    //while
                }


                iterator->size += 1;
                keyFound = true;
                break;
            }
        }

    }


//    int *hashValue = calculateHashValue(dim, m, 0, w, data, h);
//    printf("debug - hash value:\n");
//    for (int i = 0; i < m; i++) {
//        printf("%d\n", hashValue[i]);
//    }
}
