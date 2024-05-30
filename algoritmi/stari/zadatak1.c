#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int factorial(int);
double zadatak1(int, double *);
double zadatak2(int, double *);
double zadatak3(int, double *);
double zadatak4(int, double *);
double zadatak5(int, double *);
double zadatak6(int, double *);
double zadatak7(int, double *);
double zadatak8(int, double *);
double zadatak9(int, double *);
double zadatak10(int, double *);
double zadatak11(int, double *);
double zadatak12(int, double *);
double zadatak13(int, double *);
double zadatak14(double, int, double *);
double zadatak15(double, int, double *);
double zadatak16(int, int, double *);

int main() 
{
    // Prvi broj
    int numberInput;
    printf("Place number: ");
    scanf("%d", &numberInput);

    // Drugi broj (za 14, 15, 16 zadatki)
    int deg;
    printf("Place deg (ako 16, to x): ");
    scanf("%d", &deg);

    double stvarni_broj;

    // Za 14, 15, 16 zadatak
    // double result = zadatak15(deg, numberInput, &stvarni_broj);

    // Ostale
    double result = zadatak3(numberInput, &stvarni_broj);

    printf("Suma reda: %lf\n", result);
    printf("Stvarni broj: %lf\n", stvarni_broj);

    return 0;
}
int factorial(int n) {
    // U početku uvek 1 * ...
    int res = 1;

    // Factorial: 1 * 1 * 2 * 3 * 4 * ... * n 
    for(int i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}
double zadatak1(int n, double *stvarni_broj) {
    double e = 0;
    for(int i = 0; i <= n; i++) {
        e += pow(factorial(i), -1);
        printf("1/%d\n", factorial(i));

    }
    printf("=========\n");
    *stvarni_broj = M_E;
    return e;
}
double zadatak2(int n, double *stvarni_broj) {
    double e = 0;
    for(int i = 0; i <= n; i++) {
        if(i % 2 == 0) {
            printf("+1/%d\n", factorial(i));
            e += pow(factorial(i), -1);
        }
        else {
            printf("-1/%d\n", factorial(i));
            e -= pow(factorial(i), -1); 
        }
    }
    *stvarni_broj = 1/M_E;
    return e;
}
double zadatak3(int n, double *stvarni_broj) {
    double result = 0;
    
    int isPositive = 1;
    for(int i = 1; i <= n; i++) {
        if(isPositive) {
            printf("+1/%d\n", i);
            result += pow(i, -1); 
        }
        else {
            printf("-1/%d\n", i);
            result -= pow(i, -1);
        }
        isPositive = !isPositive;
    }
    printf("==========\n");

    *stvarni_broj = log(2);
    return result;
}
double zadatak4(int n, double *stvarni_broj) {
    double result = 0;
    
    int isPositive = 1;
    for(int i = 1; i <= n; i++) {
        int formula = 2*i - 1;
        if(isPositive) {
            printf("+1/%d\n", i);
            result += pow(formula, -1);

            isPositive = 0;
        }
        else {
            printf("-1/%d\n", i);
            result -= pow(formula, -1);

            isPositive = 1; 
        }
    }

    *stvarni_broj = M_PI / 4;
    return result;
}
double zadatak5(int n, double *stvarni_broj) {
    double result = 0;

    for(int i = 1; i <= n; i++) {
        int formula = (4*i - 1)*(4*i + 1);
        result += pow(formula, -1);
    }

    *stvarni_broj = (4 - M_PI) / 8;
    return result;
}
double zadatak6(int n, double *stvarni_broj) {
    double result = 0;

    for(int i = 1; i <= n; i++) {
        int formula = pow(i, 2);
        if(i % 2 == 0)
            result -= pow(formula, -1);
        else
            result += pow(formula, -1);
    }

    *stvarni_broj = pow(M_PI, 2) / 12;
    return result;
}
double zadatak7(int n, double *stvarni_broj) {
    double result = 0;

    for(int i = 0; i <= n; i++) {
        int formula = pow((2 * i + 1), 2);
        result += pow(formula, -1);
    }

    *stvarni_broj = pow(M_PI, 2) / 8;
    return result;
}
double zadatak8(int n, double *stvarni_broj) {
    double result = 0;

    for(int i = 1; i <= n; i++) {
        int formula = pow(i, 4);
        result += pow(formula, -1);
    }

    *stvarni_broj = pow(M_PI, 4) / 90;
    return result;
}
double zadatak9(int n, double *stvarni_broj) {
    double result = 0;

    for(int i = 1; i <= n; i++) {
        int formula = pow(i, 4);
        if(i % 2 == 0)
            result -= pow(formula, -1);
        else
            result += pow(formula, -1);
    }

    *stvarni_broj = 7 * pow(M_PI, 4) / 720;
    return result;
}
double zadatak10(int n, double *stvarni_broj) {
    double result = 0;

    for(int i = 0; i <= n; i++) {
        int formula = pow((2 * i + 1), 4);
        result += pow(formula, -1);
    }

    *stvarni_broj = pow(M_PI, 4) / 96;
    return result;
}
double zadatak11(int n, double *stvarni_broj) {
    double result = 0;

    for(int i = 1; i <= n; i++) {
        int formula = pow(i, 2);
        result += pow(formula, -1);
    }

    *stvarni_broj = pow(M_PI, 2) / 6;
    return result;
}
double zadatak12(int n, double *stvarni_broj) {
    double result = 0;

    for(int i = 2; i <= n; i++) {
        int formula = (i - 1) * (i + 1);
        result += pow(formula, -1);
    }

    *stvarni_broj = 3.0 / 4.0;
    return result;
}
double zadatak13(int n, double *stvarni_broj) {
    double result = 0;

    for(int i = 1; i <= n; i++) {
        int formula = i * (i + 1) * (i + 2);
        result += pow(formula, -1);
    }

    *stvarni_broj = 1.0 / 4.0;
    return result;
}
double zadatak14(double a, int n, double *stvarni_broj) {
    double result = 0;
    double radian = a * (M_PI/180);

    int isPositive = 1;
    for(int i = 0; i <= n; i++) {
        double formulaTop = pow(radian, (2*i+1));
        double formulaBelow = factorial(2*i+1);

        

        double formula = formulaTop / formulaBelow;
        if(isPositive) {
            result += formula;
            printf("+%.2f/%.2f = %.2f\n", formulaTop, formulaBelow, formula);
        }
        else {
            result -= formula;
            printf("-%.2f/%.2f = %.2f\n", formulaTop, formulaBelow, formula);
        }
        isPositive = !isPositive;
    }

    *stvarni_broj = sin(radian);
    return result;
}
double zadatak15(double a, int n, double *stvarni_broj) {
    double result = 0;
    double radian = a * (M_PI/180);

    int isPositive = 1;
    for(int i = 0; i <= n; i++) {
        double formulaTop = pow(radian, (2*i));
        double formulaBelow = factorial(2*i);

        double formula = formulaTop / formulaBelow;
        if(isPositive) {
            result += formula;
            printf("%.2f/%.2f = +%.2f\n", formulaTop, formulaBelow, formula);
        }
        else {
            result -= formula;
            printf("%.2f/%.2f = -%.2f\n", formulaTop, formulaBelow, formula);
        }

        isPositive = !isPositive;
    }
    printf("===========\n");

    *stvarni_broj = cos(radian);
    return result;
}
double zadatak16(int x, int n, double *stvarni_broj) {
    double result = 0;

    for(int i = 0; i <= n; i++) {
        double formulaTop = pow(x, i);
        double formulaBelow = factorial(i);

        double formula = formulaTop / formulaBelow;
        result += formula;
        printf("%.2f/%.2f = +%.2f\n", formulaTop, formulaBelow, formula);
    }

    *stvarni_broj = pow(M_E, x);
    return result;
}