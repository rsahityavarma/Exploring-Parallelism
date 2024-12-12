#include "serial_model.h"
#include <stdio.h>

void run_serial_model(int rows_a, int cols_a, int cols_b, int matrix_a[rows_a][cols_a], int matrix_b[cols_a][cols_b], int result[rows_a][cols_b]) {
    printf("Starting Serial Matrix Multiplication...\n");

    // Loop over each element in the result matrix
    for (int row = 0; row < rows_a; row++) {
        for (int col = 0; col < cols_b; col++) {
            int total = 0;  // Accumulator for dot product
            for (int index = 0; index < cols_a; index++) {
                total += matrix_a[row][index] * matrix_b[index][col];
            }
            result[row][col] = total;  // Store the result in the output matrix
        }
    }

    printf("Serial Matrix Multiplication Complete\n");
}

