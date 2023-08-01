#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int cylinder(double r, double h, double *V, double *S);

int main(void){

    double r, h, V, S;

    while(true){
        scanf("%lf %lf", &r, &h);

        if(r == 0 && h == 0){
            return 0;
        }

        cylinder(r, h, &V, &S);
    }

    
}

int cylinder(double r, double h, double *V, double *S){

    if(r <= 0 || h <= 0){
        printf("Invalid Data\n");
        return -1;
    } else{
        *V = M_PI * pow(r, 2) * h;
        *S = 2 * M_PI * r * h;
        printf("V = %.2lf, S = %.2lf\n", *V, *S);

    }
    return 0;
}

