#include <stdio.h>
#define pi 3.14159

void print_welcome_message(){
    printf("****************************************\n"
           "*      ENGINEERING CALCULATOR v1.0     *\n"
           "*     System Ready. Awaiting Input.    *\n"
           "****************************************\n");
}

int add_numbers(int a, int b){
    return (a+b);
}

double calculate_circumference(double r){
    return (2*pi*r);
}

double calculate_area(double r){
    return (pi*r*r);
}

int is_even(int num){
    if (num%2==0){
        return 1;
    }
    else{
        return 0;
    }

}



double power(double base, int exponent){
    int i;
    double result = 1.0;
    for (i=0;i<exponent;i++){
        result *= base;
    }
    return result;
}

int main() {
    print_welcome_message();
    char choice;
    scanf("%c",&choice);

    if (choice=='p'){
        int x,y;
        printf("Input two numbers\n");
        scanf("%d",&x);
        scanf("%d",&y);
        int z = add_numbers(x,y);
        printf("%d + %d = %d",x,y,z);
    }

    else if (choice=='e'){
        double x;
        int y;
        printf("Input two numbers\n");
        scanf("%lf",&x);
        scanf("%d",&y);
        int z = power(x,y);
        printf("%d ^ %d = %d",x,y,z);
    }

    else if (choice=='c'){
        double x;
        printf("Input a number\n");
        scanf("%lf",&x);
        int z = calculate_circumference(x);
        printf("A circle with radius %lf has circumference %lf",x,z);
    }

    else if (choice=='a'){
        double x;
        printf("Input a number\n");
        scanf("%lf",&x);
        int z = calculate_area(x);
        printf("A circle with radius %lf has area %lf",x,z);
    }

    else if (choice=='o'){
        int x;
        printf("Input a number\n");
        scanf("%d",&x);
        int parity = is_even(x);

        if (parity){
            printf("%d is even\n",x);
        }
        else {
            printf("%d is odd\n",x);
        }
    }

    else{
        return -1;
    }

    return 0;
}

