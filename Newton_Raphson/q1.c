#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define f(x) 3*x-cos(x)-1
#define df(x) 3+sin(x)

int main(){
    float x0, x1, error;
    float f0, f1, df0, df1;
    int N, steps;
    steps = 0;
    printf("Enter initial value: ");
    scanf("%f", &x0);

    printf("Enter max error: ");
    scanf("%f", &error);

    printf("Enter number of iterations: ");
    scanf("%d", &N);

    printf("\nStep\t\tx0\t\tx1\t\tfx0\t\tfx1\t\tdfx0\t\tdfx1\n");

    do{
        df0 = df(x0);
        if(df0 == 0){
            printf("Math error! Choose another initial guess.");
            exit(1);
        }

        f0 = f(x0);

        x1 = x0 - (f0)/(df0);
        printf("\n%d\t%f\t%f  \t%f\t\t%f  \t%f\t%f\n", steps, x0, x1, f(x0), f(x1), df(x0), df(x1));

        if(steps > N){
            printf("Not convergent!");
            exit(1);
        }
        steps++;

        x0 = x1;
        f1 = f(x1);
    }while( f1 > error);

    printf("\nRoot: %f", x1);

    return 0;
}