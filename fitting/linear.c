#include<stdio.h>

void fitting(){
    int n;
    printf("Enter number of data: ");
    scanf("%d", &n);
    float x[n], y[n], sumx = 0, sumy = 0, sumxy = 0, sumx2 = 0, a = 0, b = 0;

    for(int i = 0; i<n; i++){
        printf("Enter x[%d] y[%d]: ", i+1, i+1);
        scanf("%f %f", &x[i], &y[i]);
        sumx += x[i];
        sumy += y[i];
        sumxy += x[i]*y[i];
        sumx2 += x[i]*x[i];
    }

    b = (n*sumxy - sumx*sumy)/(n*sumx2 - sumx*sumx);
    a = (sumy - b*sumx)/n;

    printf("The best fitted line is: y = %f + %fx", a, b);
}

int main(){
    fitting();
    return 0;
}