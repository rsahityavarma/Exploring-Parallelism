#include "mpi_model.h"
#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

void run_mpi_model(int rows_a, int cols_a, int cols_b, int matrix_a[rows_a][cols_a], int matrix_b[cols_a][cols_b], int result[rows_a][cols_b]) {
    int rank, size;
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int rows_per_proc = rows_a / size;
    int (*local_result)[cols_b] = malloc(rows_per_proc * cols_b * sizeof(int));
    for (int i = rank * rows_per_proc; i < (rank + 1) * rows_per_proc; i++) {
        for (int j = 0; j < cols_b; j++) {
            local_result[i - rank * rows_per_proc][j] = 0;
            for (int k = 0; k < cols_a; k++) {
                local_result[i - rank * rows_per_proc][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }

    MPI_Gather(local_result, rows_per_proc * cols_b, MPI_INT, result, rows_per_proc * cols_b, MPI_INT, 0, MPI_COMM_WORLD);
    free(local_result);

    if (rank == 0) {
        printf("MPI Model Complete\n");
    }
    MPI_Finalize();
}

