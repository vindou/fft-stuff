#include <math.h>
#include <complex.h>

float* even_idx(float input_array[]) {


}

float* odd_idx(float input_array[]) {

}


float* FFT(float input_array[]) {
    int arr_length = (int) sizeof(input_array) / sizeof(input_array[0]);

    if (arr_length == 1) return input_array;

    float* even = even_idx(input_array);
    float* odd = odd_idx(input_array);

    float resultant_arr[(int) arr_length];

    for (int i = 0; i <= floor((float) arr_length / 2) - 1; i++) {
        float twiddle = exp(-2 * M_PI * I * i / arr_length);

        resultant_arr[i] = even[i] + twiddle * odd[i];
        resultant_arr[(int) (i + floor((float) arr_length / 2))] = even[i] - twiddle * odd[i];
    }

    return resultant_arr;
}
