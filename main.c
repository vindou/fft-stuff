#include "CTFFT.h"

int main(void) {
    int n = 8;
    complex double data[] = {1, 1, 1, 1, 0, 0, 0, 0};
    iterative_fft(data, n);
    printf("FFT Result:\n");
    for (int i = 0; i < n; i++) {
        printf("[%d] = %.5f + %.5fi\n", i, creal(data[i]), cimag(data[i]));
    }

    return 0;
}