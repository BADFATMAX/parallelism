#include <stdio.h>
#include <malloc.h>
#include <math.h>
#define N 10
#define solvecond 0.0000001

int main() {
    double * u = (double*) malloc(N * sizeof (double));
    double * u_plus = (double*) malloc(N * sizeof (double));


    double xmax = 1;
    double h = xmax/N;
    for (size_t i = 0; i < N-1; ++i) {
        u[i] = 0;
    }
    u[N-1] = 1;
    int a = 1;
    double tau = pow(10, -3);
    u_plus[0] = 0;
    u_plus[N-1] = 1;
    int num_of_iter = 0;
    double maxdiff = 1;
    for (int j = 0; j < 1000; j++) {
        maxdiff = fabs(u[0] - u_plus[0]);
        for (size_t i = 1; i < N - 1; i++) {
            u_plus[i] = u[i] + a * tau * (u[i - 1] - 2 * u[i] + u[i + 1]) / h / h;
            printf ("%e %e %e \n", u[i], u_plus[i], fabs(u[i] - u_plus[i]));
            if (fabs(u[i] - u_plus[i]) > maxdiff)
            {
                maxdiff = fabs(u[i] - u_plus[i]);
            }
        }
        if (maxdiff < 1.0e-6)
        {
            printf ("%d", num_of_iter);
            break;
        }
        num_of_iter++;
        for (size_t i = 1; i < N - 1; i++) {
            u[i] = u_plus[i];
        }
    }

    return 0;
}
