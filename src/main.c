#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "data_loader.h"
#include "serial_model.h"
#include "pthread_model.h"
#include "openmp_model.h"
#include "mpi_model.h"

#define ROWS 1000
#define COLS 1000

void save_execution_times(double serial, double pthread, double openmp, double mpi) {
    FILE* file = fopen("plots/execution_times.csv", "w");
    if (!file) {
        perror("Error opening execution times file");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "Model,Execution Time (seconds)\n");
    fprintf(file, "Serial,%f\n", serial);
    fprintf(file, "P-thread,%f\n", pthread);
    fprintf(file, "OpenMP,%f\n", openmp);
    fprintf(file, "MPI,%f\n", mpi);
    fclose(file);
}

int main() {
    int (*matrix_a)[COLS] = malloc(ROWS * COLS * sizeof(int));
    int (*matrix_b)[ROWS] = malloc(COLS * ROWS * sizeof(int));
    int (*result)[ROWS] = malloc(ROWS * ROWS * sizeof(int));

    if (!matrix_a || !matrix_b || !result) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    load_matrix("data/matrix_a.csv", ROWS, COLS, matrix_a);
    load_matrix("data/matrix_b.csv", COLS, ROWS, matrix_b);

    clock_t start, end;
    double time_serial, time_pthread, time_openmp, time_mpi;

    start = clock();
    run_serial_model(ROWS, COLS, ROWS, matrix_a, matrix_b, result);
    end = clock();
    time_serial = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    run_pthread_model(ROWS, COLS, ROWS, matrix_a, matrix_b, result);
    end = clock();
    time_pthread = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    run_openmp_model(ROWS, COLS, ROWS, matrix_a, matrix_b, result);
    end = clock();
    time_openmp = (double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    run_mpi_model(ROWS, COLS, ROWS, matrix_a, matrix_b, result);
    end = clock();
    time_mpi = (double)(end - start) / CLOCKS_PER_SEC;

    save_execution_times(time_serial, time_pthread, time_openmp, time_mpi);

    free(matrix_a);
    free(matrix_b);
    free(result);

    printf("Execution times saved to 'plots/execution_times.csv'.\n");

    return 0;
}

