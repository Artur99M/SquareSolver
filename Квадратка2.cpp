#include <stdio.h>
#include <math.h>
float read();

int main(){
    int a, b, c;
    printf("Напишите значения элементов a, b и c для уравнения, записанного в таком виде: ax^2+bx+c=0\n");
    printf("Напишите коэфициент a:\n");
    a = read();
    printf("Напишите коэфициент b:\n");
    b = read();
    printf("Напишите коэфициент c:\n");
    c = read();
    printf("%d %d %d", a, b, c);
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
    return 0;
}

float read(){
    double qwerty;
    char x = '0';
    int a[30];
    int count, point = -1, zero;
    while(x!='\0'){
        if(x=='\0'){
            zero = count;
            break;
        }
        x=getchar();
        int y = x - 48;
        printf("%d\n", y);
        if(y>=0 && y<=9){
            a[count]=y;
        }else if(x=='.' || x==','){
            point=count;
        }else{
            printf("Введи число: ");
            return read();
        }
        count++;
    }
    int q = 0;
    if(point!=-1){
        while(q != 30){
            qwerty += a[q] * pow(10, point - q - 1);
            q++;
        }
    }else{
        while(q != 30){
            qwerty += a[q] * pow (10, zero - q - 1);
            q++;
        }
    }
    return qwerty;
}
