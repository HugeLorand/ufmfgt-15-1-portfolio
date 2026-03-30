#include <stdio.h>

int main() {
    int sig;
    printf("what sginal strength\n");
    scanf("%d",&sig);
    sig /= 10;
    switch (sig){
        case 1:
        case 2: printf("Your grade is F"); break;
        case 3: printf ("Your grad3e is D"); break;
        case 4:
        case 5: printf("Your grade is C"); break;
        case 6:
        case 7: printf("Your grade is B"); break;
        case 8:
        case 9:
        case 10: printf("Your grade is A"); break;
        default: printf("error: value outside expected range");
    }
    return 0;
}
