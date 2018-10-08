#ifndef LSH_SEARCH_LSH_H
#define LSH_SEARCH_LSH_H

int search_LSH( int dim, int ndata, double *data, int m, double W, double **h, int ncluster, int *cluster_start, int *cluster_size, int **cluster_hash_val, double *query, double *result_ptr);

#endif //LSH_SEARCH_LSH_H
