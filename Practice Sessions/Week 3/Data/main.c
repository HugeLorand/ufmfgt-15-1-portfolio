#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Guess a number between 1 and 100! you have 3 guesses\n");
    srand(time(NULL));
    int OTP = rand() % 100 + 1;
    int guess;
    scanf("%d",&guess);
    if (guess == OTP) {
        printf("You got it!\n");
        scanf("%d", &guess);
    }
    else{
        if (guess > OTP){
            printf("Too high!\n");
        }
        else{
            printf("Too Low\n");
        }

        scanf("%d",&guess);
        if (guess == OTP) {
            printf("You got it!\n");
            scanf("%d", &guess);
        }
        else{
            if (guess > OTP){
                printf("Too high!\n");
            }
            else{
                printf("Too Low\n");
            }

            scanf("%d",&guess);
            if (guess == OTP) {
                printf("You got it!\n");
                scanf("%d", &guess);
            }
            else{
                if (guess > OTP){
                    printf("Too high!\n");
                }
                else{
                    printf("Too Low\n");
                }

                printf("Out of guesses!");
            }
        }
    }

    return 0;
}
