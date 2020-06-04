#include "calc.h"
#include "input.h"
#include <math.h>
#include <stdio.h>

int pw(int x, int y)
{
    if (y == 0)
        return 1;
    if (y < 0)
        return (1 / (x * pw(1 / x, y + 1)));
    return x * pw(x, y - 1);
}
double Digit(char* str, int x1, int x2)
{
    double res = 0, redouble = 0;
    int i, d;
    for (i = x1; i <= x2; i++) {
        if (str[i] != '.')
            res = ((str[i] - '0') + res) * 10;
        else
            break;
    }

    d = i;
    res /= 10;
    for (i = i + 1; i <= x2; i++)
        if (str[i] != '.')
            res = res + (redouble + (str[i] - '0')) / pw(10, i - d);
        else
            break;
    return res;
}

double Calc(char* str, int launch, int end)
{
    int i = launch, Opbr, Clbr, opbr, clbr, q = 0;
    if ((str[end] == ')') && (str[launch] == '(')) {
        i++;
        Opbr = 1;
        Clbr = 0;

        while (Opbr != Clbr) {
            if (str[i] == '(')
                Opbr++;
            if (str[i] == ')')
                Clbr++;
            i++;
        }
        i--;
        if (i == end)
            return Calc(str, launch + 1, end - 1);
    }

    for (i = launch; i <= end; i++) {
        switch (str[i]) {
        case '+':
            return Calc(str, launch, (i - 1)) + Calc(str, (i + 1), end);
        case '-':
            if (i > q) {
                q = i;
            }
            break;
        case '*':
            if (q == 0) {
                q = i;
            }
            break;
        case '/':
            if ((q == 0) || (str[q] == '/')) {
                q = i;
            }
            break;
        case '(':
            i++;
            opbr = 1;
            clbr = 0;
            while (opbr != clbr) {
                if (str[i] == '(')
                    opbr++;
                if (str[i] == ')')
                    clbr++;
                i++;
            }
            i--;
            break;
        case '^':
            if (q == 0) {
                q = i;
            }
            break;
        }
    }

    if (q > 0) {
        switch (str[q]) {
        case '-':
            return Calc(str, launch, q - 1) - Calc(str, q + 1, end);
        case '*':
            return Calc(str, launch, q - 1) * Calc(str, q + 1, end);
        case '/':
            return Calc(str, launch, q - 1) / Calc(str, q + 1, end);
        case '^':
            return pow(Calc(str, launch, q - 1), Calc(str, q + 1, end));
        }
    }
    return Digit(str, launch, end);
}

