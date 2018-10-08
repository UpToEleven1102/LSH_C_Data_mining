#include <math.h>
#include "Search_LSH.h"
#include "LSH.h"

double calculateDistance(int dim, const double *data, const double *query) {
    double distance = 0;
    for (int i = 0; i < dim; ++i) {
        distance += square(data[i]- query[i]);
    }
    return sqrt(distance);
}

int search_LSH(int dim, int ndata, double *data, int m, double w, double **h, int ncluster, int *cluster_start,
               int *cluster_size, int **cluster_hash_val, double *query, double *result_ptr) {
    int *query_hash_val = calculateHashValue(dim, m, 0, w, query, h);

    int cluster_target = 0;
    for (int i = 0; i < ncluster; ++i) {
        if (equalHashValue(m, query_hash_val, cluster_hash_val[i]) == true) {
            cluster_target = i;
            break;
        }
    }

    int closest_idx = cluster_start[cluster_target];
    double closest_distance = 999999;

    for (int j = 0; j < cluster_size[cluster_target]; ++j) {
        DataPoint *e = getElement(dim, cluster_start[cluster_target] + j, data);
        double distance = calculateDistance(dim, e->data, query);
        if (distance < closest_distance) {
            closest_idx = cluster_start[cluster_target] + j;
            closest_distance = distance;
        }
    }

    double *closest_point = getElement(dim, closest_idx, data)->data;
    for (int i = 0; i < dim; i++) {
        result_ptr[i] = closest_point[i];
    }
}
