#include <stdio.h>

int main() {
    int report[] = {1, 5, -2, 0, 8, -1, 0, 0, 9, -4, 2, 1};
    int poscount = 0, negcount = 0, zerocount = 0;
    int i;
    for (i=0;i<12;i++){
        if (report[i] == 0){
            zerocount++;
        }
        else{
            if (report[i] > 0){
                poscount++;
            }
            else{
                negcount++;
            }
        }
    }
    printf("%d positive codes, %d negative codes, and %d zeros",poscount,negcount,zerocount);
    return 0;
}
