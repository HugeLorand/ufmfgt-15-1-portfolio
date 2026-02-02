#include <stdio.h>
#include <math.h>
#define pi 3.14159265358979323846264338327


int main() {
    double x1;
    double x2;
    double x3;
    double x4;
    double interval;
    double y1;
    double y2;
    double y3;
    double y4;

    printf("Enter an initial value for x, and an interval\n");
    scanf("%lf",&x1);
    scanf("%lf", &interval);
    y1 = 3*sin(pi*x1) + 2*cos(pi*x1);
    x2 = x1 + interval;
    y2 = 3*sin(pi*x2) + 2*cos(pi*x2);
    x3 = x2 + interval;
    y3 = 3*sin(pi*x3) + 2*cos(pi*x3);
    x4 = x3 + interval;
    y4 = 3*sin(pi*x4) + 2*cos(pi*x4);

    printf("Value of x              Value of f(x)\n");
    printf("    %f                          %f\n",x1,y1);
    printf("    %f                          %f\n",x2,y2);
    printf("    %f                          %f\n",x3,y3);
    printf("    %f                          %f\n",x4,y4);
    return 0;
}
