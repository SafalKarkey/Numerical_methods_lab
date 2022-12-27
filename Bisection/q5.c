#include<stdio.h>
#include<math.h>

float f(float x){
    return 4*sin(x) - exp(x);
}

void bisect(float *x, float a, float b, int *itr){
    *x = (a+b)/2;
    (*itr)++;
    printf("Iteration no. %d X = %f\n", *itr, *x);
}

int main(){
    int itr = 0, maxitr;
    float x, a, b, E, x1;
    printf("Enter values of a, b, allowed error, maxm iterations: ");
    scanf("%f %f %f %d", &a, &b, &E, &maxitr);

    bisect(&x, a, b, &itr);
    do{
        if( f(a) * f(x) < 0){
            b = x;
        }
        else{
            a = x;
        }
        bisect(&x1, a, b, &itr);
        if(fabs(x1-x) < E){
            printf("After %d iterations, root = %f\n", itr, x1);
            return 0;
        }
        x = x1;
    }while(itr<maxitr);
    printf("Not convergent");
    return 1;
}