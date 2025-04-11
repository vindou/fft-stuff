#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <complex.h>

// Implementation of the Cooley-Tukey FFT algorithm
void iterative_fft(complex double *buf, int n) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (i < j) {
            complex double temp = buf[i];
            buf[i] = buf[j];
            buf[j] = temp;
        }
        int m = n / 2;
        while (m && j >= m) {
            j -= m;
            m /= 2;
        }
        j += m;
    }

    for (int size = 2; size <= n; size *= 2) {
        double angle = -2.0 * M_PI / size;
        complex double w_size = cos(angle) + I * sin(angle);

        for (int i = 0; i < n; i += size) {
            complex double w = 1.0;
            for (int j = 0; j < size / 2; j++) {
                complex double t = w * buf[i + j + size / 2];
                complex double u = buf[i + j];
                buf[i + j] = u + t;
                buf[i + j + size / 2] = u - t;
                w *= w_size;
            }
        }
    }
}


