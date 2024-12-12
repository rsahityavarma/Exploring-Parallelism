#include "openmp_model.h"
#include <omp.h>
#include <stdio.h>

void run_openmp_model(int rows_a, int cols_a, int cols_b, int matrix_a[rows_a][cols_a], int matrix_b[cols_a][cols_b], int result[rows_a][cols_b]) {
    printf("Executing OpenMP Parallel Model...\n");

    // Parallel region for matrix multiplication
    #pragma omp parallel for collapse(2)
    for (int row = 0; row < rows_a; row++) {
        for (int col = 0; col < cols_b; col++) {
            int temp_sum = 0;  // Temporary sum for the dot product
            for (int index = 0; index < cols_a; index++) {
                temp_sum += matrix_a[row][index] * matrix_b[index][col];
            }
            result[row][col] = temp_sum;  // Assign the computed value to the result
        }
    }

    printf("OpenMP Model Execution Finished\n");
}

