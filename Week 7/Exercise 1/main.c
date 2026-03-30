#include <stdio.h>



int main() {
    typedef struct c{
       double real;
       double imaginary;
    }c;
    c c1 = {0.0,1.0};
    c c2 = {1.0,0.0};
    c2 = c1;
    c c3 = {c1.real+c2.real,c1.imaginary+c2.imaginary};

    printf("%f+ %fi",c3.real,c3.imaginary);
    return 0;
}
