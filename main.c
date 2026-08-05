#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

extern void dot_product_asm(int n, double* A, double* B, double* sdot);

void dot_product_c(int n, double* A, double* B, double* sdot) {
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        sum += A[i] * B[i];
    }
    *sdot = sum;
}

void run_test(int n) {
    printf("\n--- Running test for vector size n = %d ---\n", n);
    
    double* A = (double*)malloc(n * sizeof(double));
    double* B = (double*)malloc(n * sizeof(double));
    
    if (A == NULL || B == NULL) {
        printf("Memory allocation failed for size %d. Try reducing n.\n", n);
        return;
    }

    for (int i = 0; i < n; i++) {
        A[i] = (double)rand() / RAND_MAX;
        B[i] = (double)rand() / RAND_MAX;
    }

    double sdot_c = 0.0;
    double sdot_asm = 0.0;
    double total_time_c = 0.0;
    double total_time_asm = 0.0;
    int num_runs = 20;

    LARGE_INTEGER frequency, start, end;
    QueryPerformanceFrequency(&frequency);

    for (int i = 0; i < num_runs; i++) {
        QueryPerformanceCounter(&start);
        dot_product_c(n, A, B, &sdot_c);
        QueryPerformanceCounter(&end);
        total_time_c += (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
    }
    double avg_time_c = total_time_c / num_runs;

    for (int i = 0; i < num_runs; i++) {
        QueryPerformanceCounter(&start);
        dot_product_asm(n, A, B, &sdot_asm);
        QueryPerformanceCounter(&end);
        total_time_asm += (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;
    }
    double avg_time_asm = total_time_asm / num_runs;

    double diff = fabs(sdot_c - sdot_asm);
    const double EPSILON = 1e-5;
    
    printf("C Result:   %lf\n", sdot_c);
    printf("ASM Result: %lf\n", sdot_asm);
    
    if (diff < EPSILON) {
        printf("Correctness Check: PASSED (Results match)\n");
    } else {
        printf("Correctness Check: FAILED (Difference: %lf)\n", diff);
    }

    printf("Average Execution Time (C):   %lf seconds\n", avg_time_c);
    printf("Average Execution Time (ASM): %lf seconds\n", avg_time_asm);

    free(A);
    free(B);
}

int main() {
    srand((unsigned int)GetTickCount64());

    int n1 = 1 << 20;
    int n2 = 1 << 24;
    int n3 = 1 << 28;

    run_test(n1);
    run_test(n2);
    run_test(n3);

    return 0;
}