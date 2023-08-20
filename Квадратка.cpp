
#include <stdio.h>
#include <math.h>
void x();
int main() {
    printf("Напишите значения элементов a, b и c для уравнения, записанного в таком виде: ax^2+bx+c=0\n");
    printf("Напишите коэфициенты a, b, c через пробел:\n");
    x();
    return 0;
}
void x(){
    double a=0.0f, b=0.0f, c=0.0f;
    if (scanf("%lf%lf%lf", &a, &b, &c) ==3){
        if(a==0){
            if(b==0){
                if(c==0){
                    printf("Любое число\n");
                }else{
                    printf("Нет решений\n");
                }
            }else{
                double x;
                x = -c/b;
                printf("%lf", x);
            }
        }else{
            double D, x1, x2;
            D=b*b-4*c*a;
            if(D>0){
                x1=(-b+sqrt(D))/2*a;
                x2=(-b-sqrt(D))/2*a;
                printf("%lf %lf\n", x1, x2);
            }else if(D==0){
                x1=-b/2*a;
                printf("%lf", x1);
            }else{
                printf("Нет решений\n");
            }

        }
    }else{
        printf("Надо было ввести 3 числа!\n");
        x();
    }
}
