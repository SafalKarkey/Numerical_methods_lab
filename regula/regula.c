#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f(double x)
{
    return cos(x) - x * exp(x);
}

void regulaFalsiMethod()
{
    double x0, x1, x2, e;
    double fx1, fx0, fx2;
    int N;
    int step = 1;
    
    do{
        printf("Enter intial guess: ");
        scanf("%lf %lf", &x0, &x1);
        fx1 = f(x1);
        fx0 = f(x0);
        if(fx0 * fx1 > 0) {
            printf("Wrong initial guess\n");
        }
    }while(f(x0) * f(x1) > 0);

    printf("Enter tolerable error: ");
    scanf("%lf", &e);
    
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
        printf("\n|%d\t\t%lf\t%lf\t%lf\t%lf\t\t|\n", step, x0, x1, x2, fx2);
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
    printf("Root of the equation is: %lf\n", x2);
}

int main()
{
    regulaFalsiMethod();
    return 0;
}