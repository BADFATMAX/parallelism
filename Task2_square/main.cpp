#include <stdio.h>
#include <malloc.h>
#include <math.h>
#define N 128


int main() {
    double ** u = (double **)malloc(N * sizeof(double*));
    for (int index=0;index<N;++index)
    {
        u[index] = (double *)malloc(N * sizeof(double));
        for (int i = 0; i < N; ++i) {
            u[index][i] = 0;

        }
    }

    double ** u_plus = (double **)malloc(N * sizeof(double *));
    for (int index=0;index<N;++index)
    {
        u_plus[index] = (double *)malloc(N * sizeof(double ));
    }


    u[0][0] = 10;
    u[0][N-1] = 20;
    u[N-1][0] = 20;
    u[N-1][N-1] = 30;

    for (int i = 1; i < N-1; i++){
        u[0][i] = u[0][0] + (u[0][N-1] - u[0][0]) / (N-1) * i;
        u[i][0] = u[0][0] + (u[N-1][0] - u[0][0]) / (N-1) * i;
        u[N-1][i] = u[N-1][0] + (u[N-1][N-1] - u[N-1][0]) / (N-1) * i;
        u[i][N-1] = u[0][N-1] + (u[N-1][N-1] - u[0][N-1]) / (N-1) * i;

    }


    FILE *output = fopen("u_plus.txt", "w");
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            fprintf(output, "%e ", u[i][j]);
        }
        fprintf(output, "\n");
    }
    fclose(output);

    return 0;
}
