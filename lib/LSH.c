
#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include "LSH.h"
#include "utilities.h"

double innerProduct(int dim, double *v1, double *v2) {
    double product = 0;
    for (int i = 0; i < dim; i++) {
        product += v1[i] * v2[i];
    }
    return product;
}

int *calculateHashValue(int dim, int m, int idx, double w, double *data, double **h) {

    DataPoint *element = getElement(dim, idx, data);

    int *hashValue = (int *) malloc(m * sizeof(int));

    for (int i = 0; i < m; i++) {
        double product = innerProduct(dim, element->data, h[i]);
        hashValue[i] = (int) (product / w);
    }

    return hashValue;
}

bool equalHashValue(int m, int *o1, int *o2) {
    bool equal = true;
    for (int i = 0; i < m; ++i) {
        if (o1[i] != o2[i]) {
            equal = false;
            break;
        }
    }

    return equal;
}

void setOutputValues(int dim, int n_cluster, int m, HashBucket *headBucket, int *cluster_start,
                     int *cluster_size, int **cluster_hash_val, double *data) {
    //initialize outputs:
    for (int i = 0; i < n_cluster; i += 1) {
        cluster_hash_val[i] = (int *) malloc(m * sizeof(int));
    }

    int cluster_idx = 0, start_idx = 0, data_idx = 0;
    HashBucket *ite_bucket = headBucket;
    DataPoint *ite_data = NULL;
    while (ite_bucket != NULL) {
        //copy cluster hash values
        for (int i = 0; i < m; ++i) {
            cluster_hash_val[cluster_idx][i] = ite_bucket->key[i];
        }

        //override data:
        ite_data = ite_bucket->value;
        while(ite_data !=NULL) {
            for (int i = 0; i < dim; ++i) {
                data[data_idx++] = ite_data->data[i];
            }
            ite_data= ite_data->next;
        }

        cluster_size[cluster_idx] = ite_bucket->cluster_size;
        cluster_start[cluster_idx] = start_idx;
        start_idx += cluster_size[cluster_idx];

        cluster_idx++;
        ite_bucket = ite_bucket->next;
    }
}

HashBucket *LSH(int dim, int ndata, double *data, int m, double w, double **h, int **n_cluster_ptr, int **cluster_start,
                int **cluster_size, int ***cluster_hash_val) {
    //cluster_hash_val =
    //initialize outputs:
    *n_cluster_ptr = (int *) malloc(sizeof(int));
    **n_cluster_ptr = 0;

    //local variables
    bool clusterFound = false;

    //pointers to hash buckets
    HashBuckets *head_bucket_ptr = NULL;
    HashBucket *bucket_iterator, *last_bucket_ptr;
    int *hashValue;

    for (int i = 0; i < ndata; ++i) {
        bucket_iterator = head_bucket_ptr;
        last_bucket_ptr = head_bucket_ptr;
        hashValue = calculateHashValue(dim, m, i, w, data, h);
        clusterFound = false;

        DataPoint *dataPoint = getElement(dim, i, data);

        if (head_bucket_ptr != NULL) {
            while (bucket_iterator != NULL) {
                if (equalHashValue(m, hashValue, bucket_iterator->key)) {
                    clusterFound = true;
                    dataPoint->next = bucket_iterator->value;
                    bucket_iterator->value = dataPoint;
                    bucket_iterator->cluster_size++;
                    break;
                }
                if (bucket_iterator->next == NULL) {
                    last_bucket_ptr = bucket_iterator;
                }
                bucket_iterator = bucket_iterator->next;
            }

            if (clusterFound == false) {
                **n_cluster_ptr += 1;
                last_bucket_ptr->next = (HashBucket *) malloc(sizeof(HashBucket));
                last_bucket_ptr = last_bucket_ptr->next;
                last_bucket_ptr->key = hashValue;
                last_bucket_ptr->value = dataPoint;
                last_bucket_ptr->cluster_number = **n_cluster_ptr;
                last_bucket_ptr->next = NULL;
                last_bucket_ptr->cluster_size = 1;
            }
        } else {
            **n_cluster_ptr = 1;
            head_bucket_ptr = (HashBucket *) malloc(sizeof(HashBucket));
            head_bucket_ptr->cluster_number = **n_cluster_ptr;
            head_bucket_ptr->key = hashValue;
            head_bucket_ptr->value = dataPoint;
            head_bucket_ptr->next = NULL;
            head_bucket_ptr->cluster_size = 1;
        }
    }

    *cluster_start = (int *) malloc(**n_cluster_ptr * sizeof(int));
    *cluster_size = (int *) malloc(**n_cluster_ptr * sizeof(int));
    *cluster_hash_val = (int **) malloc(**n_cluster_ptr * sizeof(int *));

    setOutputValues(dim, **n_cluster_ptr, m, head_bucket_ptr, *cluster_start, *cluster_size, *cluster_hash_val, data);

    //printHashBuckets(dim, m, head_bucket_ptr);
    printf("number of cluster: %d\n", **n_cluster_ptr);

    return head_bucket_ptr;
}
