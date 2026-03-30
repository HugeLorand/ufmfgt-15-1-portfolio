#include <stdio.h>

int main() {
    float signals[] = {88.5,92.1,85.0,95.3,89.9,91.2,84.8,90.5};
    float min = signals[0];
    float max = signals[0];
    int i;
    float sum = 0;
    for (i=0;i<8;i++){
        if (signals[i] > max){
            max = signals[i];
        }
        if (signals[i] < min){
            min = signals[i];
        }
        sum += signals[i];
    }
    float avg = sum/8;
    printf("Minimum value: %f\nMaximum value: %f\nAverage: %f",min,max,avg);
}
