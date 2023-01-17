#include <stdio.h>
#include <math.h>

float f(float x)
{
    return x*log10(x) - 1.2;
}

int main()
{
    float x0, x1, E, x;
    int step = 0;

    do
    {
        printf("Enter x0, x1, tolerable error: ");
        scanf("%f %f %f", &x0, &x1, &E);
        if (f(x0) * f(x1) > 0)
        {
            printf("Incorrect initial guess. Enter again!\n");
        }
    } while ((f(x0) * f(x1)) > 0);

    do
    {
        x = (x0 + x1) / 2;
        if ((f(x0) * f(x)) < 0)
        {
            x1 = x;
        }
        else
        {
            x0 = x;
        }
        step++;
        printf("After %d steps, x = %f\n", step, x);
    } while (fabs(f(x)) > E);

    printf("Root: %f", x);
    return 0;
}