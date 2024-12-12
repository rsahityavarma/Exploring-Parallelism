#include "pthread_model.h"
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start_row, end_row;
    int rows_a, cols_a, cols_b;
    int (*matrix_a)[1000];
    int (*matrix_b)[1000];
    int (*result)[1000];
} thread_data_t;

void* multiply_section(void* arg) {
    thread_data_t* data = (thread_data_t*)arg;
    for (int i = data->start_row; i < data->end_row; i++) {
        for (int j = 0; j < data->cols_b; j++) {
            data->result[i][j] = 0;
            for (int k = 0; k < data->cols_a; k++) {
                data->result[i][j] += data->matrix_a[i][k] * data->matrix_b[k][j];
            }
        }
    }
    return NULL;
}

void run_pthread_model(int rows_a, int cols_a, int cols_b, int matrix_a[rows_a][cols_a], int matrix_b[cols_a][cols_b], int result[rows_a][cols_b]) {
    int num_threads = 4;
    pthread_t threads[num_threads];
    thread_data_t thread_data[num_threads];
    int rows_per_thread = rows_a / num_threads;

    for (int i = 0; i < num_threads; i++) {
        thread_data[i] = (thread_data_t){i * rows_per_thread, (i + 1) * rows_per_thread, rows_a, cols_a, cols_b, matrix_a, matrix_b, result};
        pthread_create(&threads[i], NULL, multiply_section, &thread_data[i]);
    }

    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("P-thread Model Complete\n");
}

