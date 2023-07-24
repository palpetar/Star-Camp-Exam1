#include <stdio.h>
#include <math.h>

int cylinder(double r, double h, double *V, double *S);

int main(void){

    double r, h, V, S;

    do{
        scanf("%lf %lf", &r, &h);

        cylinder(r, h, &V, &S);

        printf("V = %.2lf, S = %.2lf", V, S);


    } while(r == 0 && h == 0);

    return 0;
    
}

int cylinder(double r, double h, double *V, double *S){

    if(r <= 0 || h <= 0){
        printf("Invalid Data");
        return -1;
    }

    *V = M_PI * pow(r, 2) * h;

    *S = 2 * M_PI * r * h;

    return 0;

}

