#include "../src/calc.h"
#include "../thirdparty/ctest.h"
#include "../src/input.h"
#include "../test/calculation.h"
#include <ctest.h>
#include <gtk/gtk.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double Calc(char* str, int launch, int end);

char* input;

CTEST(plus, CALCULATION)
{
    const double exp1 = 18;
    const double exp2 = 21;
    const double exp3 = 1304;
    const double exp4 = 203;

    input = malloc(10);

    strcpy(input, "18");
    int s1 = strlen(input);
    double c1 = Calc(input, 0, s1 - 1);

    strcpy(input, "13+8");
    int s2 = strlen(input);
    double c2 = Calc(input, 0, s2 - 1);

    strcpy(input, "1245+51+8");
    int s3 = strlen(input);
    double c3 = Calc(input, 0, s3 - 1);

    strcpy(input, "74+129");
    int s4 = strlen(input);
    double c4 = Calc(input, 0, s4 - 1);

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
}

CTEST(minus, CALCULATION)
{
    const double exp1 = 11;
    const double exp2 = 129;
    const double exp3 = 1773;
    const double exp4 = 93;

    input = malloc(10);

    strcpy(input, "16-5");
    int s1 = strlen(input);
    double c1 = Calc(input, 0, s1 - 1);

    strcpy(input, "154-25");
    int s2 = strlen(input);
    double c2 = Calc(input, 0, s2 - 1);

    strcpy(input, "1842-61-8");
    int s3 = strlen(input);
    double c3 = Calc(input, 0, s3 - 1);

    strcpy(input, "194-101");
    int s4 = strlen(input);
    double c4 = Calc(input, 0, s4 - 1);

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
}

CTEST(multiply, CALCULATION1)
{
    const double exp1 = 75;
    const double exp2 = 198;
    const double exp3 = 1887;
    const double exp4 = -58;

    input = malloc(10);

    strcpy(input, "15*5");
    int s1 = strlen(input);
    double c1 = Calc(input, 0, s1 - 1);

    strcpy(input, "18*11");
    int s2 = strlen(input);
    double c2 = Calc(input, 0, s2 - 1);

    strcpy(input, "1258*1.5");
    int s3 = strlen(input);
    double c3 = Calc(input, 0, s3 - 1);

    strcpy(input, "58*(-1)");
    int s4 = strlen(input);
    double c4 = Calc(input, 0, s4 - 1);

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
}

CTEST(divide, CALCULATION)
{
    const double exp1 = 9;
    const double exp2 = 30;
    const double exp3 = 93.1;
    const double exp4 = -8.4;

    input = malloc(10);

    strcpy(input, "18/2");
    int s1 = strlen(input);
    double c1 = Calc(input, 0, s1 - 1);

    strcpy(input, "15/0.5");
    int s2 = strlen(input);
    double c2 = Calc(input, 0, s2 - 1);

    strcpy(input, "1865/4/5");
    int s3 = strlen(input);
    double c3 = Calc(input, 0, s3 - 1);

    strcpy(input, "72/(-5)");
    int s4 = strlen(input);
    double c4 = Calc(input, 0, s4 - 1);

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
}

CTEST(pow, CALCULATION)
{
    const double exp1 = 169;
    const double exp2 = 16105100000;
    const double exp3 = 41.7852;
    const double exp4 = 0.0135;

    input = malloc(10);

    strcpy(input, "13^2");
    int s1 = strlen(input);
    double c1 = Calc(input, 0, s1 - 1);

    strcpy(input, "110^5");
    int s2 = strlen(input);
    double c2 = Calc(input, 0, s2 - 1);

    strcpy(input, "1746^(1.2)");
    int s3 = strlen(input);
    double c3 = Calc(input, 0, s3 - 1);

    strcpy(input, "74^(-1)");
    int s4 = strlen(input);
    double c4 = Calc(input, 0, s4 - 1);

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
}

CTEST(sqrt, CALCULATION)
{
    const double exp1 = 169;
    const double exp2 = 16105100000;
    const double exp3 = 41.7852;
    const double exp4 = 0.0135;

    input = malloc(10);

    strcpy(input, "13^(0.5)");
    int s1 = strlen(input);
    double c1 = Calc(input, 0, s1 - 1);

    strcpy(input, "110^(0.5)");
    int s2 = strlen(input);
    double c2 = Calc(input, 0, s2 - 1);

    strcpy(input, "1746^(0.5)");
    int s3 = strlen(input);
    double c3 = Calc(input, 0, s3 - 1);

    strcpy(input, "74^(0.5)");
    int s4 = strlen(input);
    double c4 = Calc(input, 0, s4 - 1);

    ASSERT_EQUAL(exp1, c1);
    ASSERT_EQUAL(exp2, c2);
    ASSERT_EQUAL(exp3, c3);
    ASSERT_EQUAL(exp4, c4);
}
