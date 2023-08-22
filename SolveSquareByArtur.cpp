#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <assert.h>

enum Roots {
    INFINITYROOTS,
    NOROOTS,
    ONEROOT,
    TWOROOTS,
    ERROR
};


void read ( double * a );
Roots SolveSquare ( double a, double b, double c, double * x1, double * x2 );
void cleanbufer();
bool Zero ( double number );
void input ( double * a, double * b, double * c ) ;
void output( Roots nRoots, double x1, double x2);

int main () {
    double a = 0, b = 0, c = 0;
    printf ( "Напишите значения элементов a, b и c для квадратного уравнения, записанного в таком виде: ax^2+bx+c=0\n" );

    input ( &a, &b, &c );

    double x1 = 0, x2 = 0;
    Roots nRoots = ERROR;
    nRoots = SolveSquare ( a, b, c, &x1, &x2 );

    output ( nRoots, x1, x2 ) ;

    return 0;
}

Roots SolveSquare ( double a, double b, double c, double * x1, double * x2 ) {

    assert ( isfinite (a) );
    assert ( isfinite (b) );
    assert ( isfinite (c) );

    assert ( x1 != 0 );
    assert ( x2 != 0 );
    assert ( x1 != x2 );

    if( Zero(a) ) {

        if( Zero(b) ) {

            if( Zero(c) ) {

                return INFINITYROOTS; /* -1 используется, если решений нет */

            } else {

                return NOROOTS;
            }

        } else {

            *x1 = -c/b;
            return ONEROOT;

        }

    } else { /* a!=0 */

        double D;
        D = b * b + 4 * a * c;

        if (D > 0) {

            double sqrtD = sqrt(D);
            *x1 = ( -b + sqrtD ) / ( 2 * a );
            *x2 = ( -b - sqrtD ) / ( 2 * a );
            return TWOROOTS;

        } else if ( D == 0 ) {
            *x1 = -b / (2 * a);
            return ONEROOT;

        } else {
            return NOROOTS;
        }
    }
}

void read ( double * body ) {
    char end = '0';
    while ( scanf ( "%lf", body ) != 1 || getchar() != '\n' ) {
        printf("Введи одно число:\n");
        cleanbufer();
    }
}
void cleanbufer(){
    while ( getchar() != '\n' ) {
    }
}
bool Zero ( double number ) {
    const double Eps = 1e-7f;
    if ( fabs ( number - 0 ) < Eps ) {
        return true;
    } else {
        return false;
    }
}
bool notZero ( double number ) {
    const double Eps = 1e-7f;
    if ( fabs ( number - 0 ) < Eps ) {
        return false;
    } else {
        return true;
    }
}
void input ( double * a, double * b, double * c ){
    printf("Напиши значение a:\n");
    read (a);
    printf("Напиши значение b:\n");
    read (b);
    printf("Напиши значение c:\n");
    read (c);
}
void output( Roots nRoots, double x1, double x2){
    switch ( nRoots ) {
        case NOROOTS:
            printf ( "Решений нет" );
            break;
        case ONEROOT:
            printf("Всего один корень:\nx = %f", x1);
            break;
        case TWOROOTS:
            printf ( "Уравнение имеет 2 корня:\nx1 = %f\nx2 = %f", x1, x2 );
            break;
        case INFINITYROOTS:
            printf ( "Корней нет" );
            break;
        default:
            printf ( "Возникла какая-то ошибка" );
            break;
    }
}
