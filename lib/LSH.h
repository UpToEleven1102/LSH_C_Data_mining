
#ifndef LSH_LSH_H
#define LSH_LSH_H

int LSH(int dim, int ndata, double *data, int m, double w, double **h, int **n_cluster_ptr, int **cluster_start,
        int **cluster_size, int ***cluster_hash_val);


#endif //LSH_LSH_H
