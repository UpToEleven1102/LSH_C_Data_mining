# Local_Sensitive_Hashing ReadME File
 - CS 4331 Data Mining & High Performance Computing - 9/23/2018
 - Huyen Vu
 - Kurtis Jackson
 - Samuel Eash



## File compilation

1. Windows
 - GNU bash, version 4.1.11(2)-release (x86_64-unknown-cygwin)
 - gcc main.c lib/LSH.c lib/utilities.c lib/Search_LSH.c -o LSH -std=gnu99
 - run LSH.exe file in Windows

2. Ubuntu Linux 18.04 LTS
 - gcc version 7.3.0 (Ubuntu 7.3.0-16ubuntu3)
 - gcc main.c ./lib/LSH.c ./lib/utilities.c ./lib/Search_LSH.c -std+gnu99 -o LSH
 - run ./LSH in ubuntu



## main.c Documentation
main.c is used to generate the dataset and hash functions that will be sorted by LSH into clusters
 - delacares and pre-initializes output values for the LSH function
 - generates random dataset data by using (double) (rand() % 10) / 10 to generate numbers between 0 and 1
 - generated datasets are of size, dim X ndata
 - generates a unit vector of each data point which is used in generating the hash function of each data point
 - passes generated dataset to the LSH function for sorting alongside with other inputs
 - inputs: DIM: dimension of data points. N_DATA: number of data points in the set. M: number of hash functions. W: scaling factor. h: the list of hash functions.
 - outputs: nclusters: number of clusters. cluster_start: indicates first element of each cluster. cluster_size: number of element in each cluster. cluster_hashval: hash value of each cluster



## LHS.c Documentation
LHS.c receives data from main.c for generating clusters based on approximate hash value
 - LHS() use data structure as a HashTable. Elements of the table are linked to each other as a LinkedList
 - hash values are generated by using the inner product of data points and hash function divided by a scaling factor (for the fact that the dataset is generated values between 0 and 1)
 - new clusters are created when no cluster is found to have the same hash value as the one being generated
 - each cluster is a linked list data structure with a one to many mapping of the hash values to data point(s)
 - comparisons and sorting of new hash values is done during computation to reduce compilation time to O(m X dim X ndata)
 - the LSH function finds the start of each cluster and the size of the cluster as well as  assigning the unique hash vlaue to each cluster



## utilities.c Documentation
utilities.c is a group of helper functions used to facilitate the coding process
