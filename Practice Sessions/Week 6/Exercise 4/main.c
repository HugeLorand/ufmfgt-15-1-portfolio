#include <stdio.h>
#include <math.h>

void impedance(double res,double cap,double ind,double freq,double *phase,double *imp){
    *imp = sqrt(pow(res,2)+pow(freq*ind-(1/(freq*cap)),2));
    *phase = acos(res / *imp);
}

int main() {
    double res,cap,ind,freq;
    double phase,imp;
    printf( "Resistance: \n");
    scanf("%lf",&res);
    printf( "Capacitance: \n");
    scanf("%lf",&cap);
    printf( "Inductance: \n");
    scanf("%lf",&ind);
    printf( "Angular Frequency: \n");
    scanf("%lf",&freq);
    impedance(res,cap,ind,freq,&phase,&imp);
    printf("Impedance: %f, Phase: %f",imp,phase);
    return 0;
}
