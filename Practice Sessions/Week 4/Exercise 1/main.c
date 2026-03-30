#include <stdio.h>

#define  INITIAL_VAL -1.0

int main() {
    double sensors[10];
    int i = 0;
    for (i;i<10;i++){
        sensors[i] = INITIAL_VAL;
    }
    i = 1;
    for (i;i<11;i++){
        printf("Reading of sensor %d is %f \n",i,sensors[i]);
    }
    return 0;
}
