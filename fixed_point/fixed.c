#include<stdio.h>
#include<math.h>
#include<stdlib.h>

float f(float x){
    return cos(x) - 3*x +1;
}

float g(float x){
    return (cos(x) + 1)/3;
}

float dg(float x){
    return (sin(x))/3;
}

void fixedPointMethod(){
    float x0, x1, fx1, gx0, e, fx0;
    int N, step;

    printf("Enter intial guess: ");
    scanf("%f", &x0);
    
    printf("Tolerable error: ");
    scanf("%f", &e);
    printf("Maxm iterations: ");
    scanf("%d", &N);

    step = 1;
    printf("\n*---------------------------------------------------------------------------------------*\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t|");
    printf("\n|Step\t\tx0\t\tx1\t\tf(x0)\t\tf(x1)\t\t\t|\n");
    printf("|---------------------------------------------------------------------------------------|\n");

    do{
        gx0 = g(x0);
        fx0 = f(x0);


        x1 = gx0;
        fx1 = f(x1);

        printf("|\t\t\t\t\t\t\t\t\t\t\t|");
        printf("\n|%d\t\t%f\t%f\t%f\t%f\t\t|\n", step, x0, x1, fx0, fx1);

        step++;
        fx1 = f(x1);

        x0 = x1;
        if(step > N){
            printf("Not convergent\n");
            exit(1);
        }

    }while(fabs(fx1) > e);
    printf("*---------------------------------------------------------------------------------------*\n");

    printf("Root: %f", x1);

}

int main(){
    fixedPointMethod();
    return 0;
}