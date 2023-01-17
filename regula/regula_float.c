#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float f(float x)
{
    return cos(x) - x * exp(x);
}

void regulaFalsiMethod()
{
    float x0, x1, x2, e;
    float fx1, fx0, fx2;
    int N;
    int step = 1;
    
    do{
        printf("Enter intial guess: ");
        scanf("%f %f", &x0, &x1);
        fx1 = f(x1);
        fx0 = f(x0);
        if(fx0 * fx1 > 0) {
            printf("Wrong initial guess\n");
        }
    }while(f(x0) * f(x1) > 0);
    
    printf("\n*---------------------------------------------------------------------------------------*\n");
    printf("|\t\t\t\t\t\t\t\t\t\t\t|");
    printf("\n|Step\t\tx0\t\tx1\t\tx2\t\tf(x2)\t\t\t|\n");
    printf("|---------------------------------------------------------------------------------------|\n");
    do
    {
        fx1 = f(x1);
        fx0 = f(x0);
        if (fx0 == fx1)
        {
            printf("Math error\n");
            exit(1);
        }
        x2 = x1 - (x0 - x1) * fx1 / (fx0 - fx1);
        fx2 = f(x2);
        printf("|\t\t\t\t\t\t\t\t\t\t\t|");
        printf("\n|%d\t\t%f\t%f\t%f\t%f\t\t|\n", step, x0, x1, x2, fx2);
        step++;
        if (fx2 * fx0 < 0)
        {
            x1 = x2;
        }
        else
        {
            x0 = x2;
        }
    } while (fabs(fx2) > e);
    printf("*---------------------------------------------------------------------------------------*\n");
    printf("Root of the equation is: %f\n", x2);
}

int main()
{
    regulaFalsiMethod();
    return 0;
}