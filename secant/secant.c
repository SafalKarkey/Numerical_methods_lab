#include<stdio.h>
#include<math.h>
#include<stdlib.h>

float f(float x){
    return x*x*x - 2*x -5;
}

void secantMethod(){
    float x0, x1, x2, fx1, fx0, fx2, e;
    int N, step = 1;
    printf("Enter initial guesses x0 and x1: ");
    scanf("%f %f", &x0, &x1);
    printf("Enter tolerable error: ");
    scanf("%f", &e);
    printf("Enter maxm iterations: ");
    scanf("%d", &N);

    printf("\n*---------------------------------------------------------------------------------------*\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t|");
    printf("\n|Step\t\tx0\t\tx1\t\tx2\t\tf(x2)\t\t\t|\n");
    printf("|---------------------------------------------------------------------------------------|\n");
    do{
        fx1 = f(x1);
        fx0 = f(x0);
        if(fx0 == fx1){
            printf("Math error\n");
            exit(1);
        }
        x2 = x1 - (x1 - x0)*fx1/(fx1 - fx0);
        fx2 = f(x2);
        printf("|\t\t\t\t\t\t\t\t\t\t\t|");
        printf("\n|%d\t\t%f\t%f\t%f\t%f\t\t|\n", step, x0, x1, x2, fx2);
        step++;
        x0 = x1;
        x1 = x2;
        if(step > N){
            printf("Solution doesn't converge!\n");
            exit(1);
        }
    }while(fabs(fx2) > e);
    printf("*---------------------------------------------------------------------------------------*\n");
    printf("Root of the equation is: %f\n", x2);
}

int main(){
    secantMethod();
    return 0;
}