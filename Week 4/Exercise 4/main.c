#include <stdio.h>

int main() {
    int codes[] = {12,43,2,6,9,5,3,5,27,42,35,393,76,345,4};
    int search = 42;
    printf("Please enter a value to search:\n");
    scanf("%d",&search);
    int i;
    int found = -1;
    for (i=0;i<15;i++){
        if (codes[i] == search){
            found = i;
            break;
        }
    }
    if (found > -1) {
        printf("Code found at %d", found);
    }
    else{
        printf("Code not found");
    }


    return 0;
}
