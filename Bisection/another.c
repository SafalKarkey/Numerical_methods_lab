#include<stdio.h>
#include<math.h>

float f(float x){
    return 4*exp(-x)*sin(x) - 1;
}

// float f(float x){
//     return 4*sin(x) - exp(x);
// }

int main(){
    float x0, x1, E, x;
    int itr = 0;

    printf("Enter x0, x1, tolerable error: ");
    scanf("%f %f %f", &x0, &x1, &E);

    if( f(x0) * f(x1) > 0){
        printf("Incorrect init guess\n");
        return 1;
    }

    do{
        x = (x0 + x1)/2;
        if( (f(x0) * f(x) ) < 0){
            x1 = x;
        }
        else{
            x0 = x;
        }
        itr++;
        printf("After %d itr, x = %f\n", itr, x);
    }while(fabs(f(x)) > E);

    printf("Root: %f", x);
    return 0;

}