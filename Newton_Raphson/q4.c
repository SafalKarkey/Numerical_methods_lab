#include<stdio.h>
#include<math.h>
#include<stdlib.h>

float f(float x){
    return x*x - 3*x + 2;
}

float df(float x){
    return 2*x - 3;
}

int main(){
    float x0, x1, error;
    int N, steps;
    steps = 1;
    printf("Enter initial value: ");
    scanf("%f", &x0);

    printf("Enter max error: ");
    scanf("%f", &error);

    printf("Enter number of iterations: ");
    scanf("%d", &N);

    // printf("\nStep\t\tx0\t\tf(x0)\t\tdf(x0)\t\tx1\t\tf(x1)\n");
    printf("*-----------------------------------------------------------------------------------------*\n");
    printf("\nStep\t\tx0\t\tf(x0)\t\tdf(x0)\t\tx1\t\tf(x1)\n");
    printf("-------------------------------------------------------------------------------------------\n");

    do{
        if(df(x0) == 0){
            printf("Math error! Choose another initial guess.");
            exit(1);
        }

        x1 = x0 - f(x0)/df(x0);
        // printf("\n%d\t\t%f\t%f\t%f\t%f\t%f\n", steps, x0, f(x0), df(x0), x1, f(x1));
        printf("\n%d\t\t%f\t%f\t%f\t%f\t%f\n", steps, x0, f(x0), df(x0), x1, f(x1));
        printf("-------------------------------------------------------------------------------------------\n");

        if(steps > N){
            printf("Not convergent!");
            exit(1);
        }
        steps++;

        x0 = x1;
    }while( fabs(f(x1)) > error);

    printf("\nRoot: %f", x1);

    return 0;
}