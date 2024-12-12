#include "data_loader.h"
#include <stdio.h>
#include <stdlib.h>

void load_matrix(const char* filename, int rows, int cols, int matrix[rows][cols]) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (fscanf(file, "%d,", &matrix[i][j]) != 1) {
                fprintf(stderr, "Error reading file %s at [%d][%d]\n", filename, i, j);
                fclose(file);
                exit(EXIT_FAILURE);
            }
        }
    }
    fclose(file);
}

