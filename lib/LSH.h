
#ifndef LSH_LSH_H
#define LSH_LSH_H

#include "utilities.h"

HashBucket *LSH(int dim, int ndata, double *data, int m, double w, double **h, int **n_cluster_ptr, int **cluster_start,
                int **cluster_size, int ***cluster_hash_val);

int *calculateHashValue(int dim, int m, int idx, double w, double *data, double **h);
bool equalHashValue(int m, int *o1, int *o2);

#endif //LSH_LSH_H
