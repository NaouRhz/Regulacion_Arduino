#ifndef POLYNOMFUN_H
#define POLYNOMFUN_H

#include <Arduino.h>
#include <math.h>

typedef struct{
    float* fx;
    int fx_num;
}results_t;

typedef struct{
    float* coefficients;
    int degree;
}degreeANDcoeffi_t;

const String IntroducingText = "\t\tFunctions calculator\n\nPlease enter your ecuation as is indicated\n\n f(x): a4x^4+a3x^3+a2x^2+a1x+2 --> Introduce a4 a3 a2 a1 2\n\n NOTE: if any term is 0 introduce 0 like is indicated\n\n f(x): a4x^4+a3x^3+a1x --> Introduce a4 a3 0 a1 0";

results_t get_funResults(String cmd);
degreeANDcoeffi_t get_coefficients(String cmd);
bool verify_fx(degreeANDcoeffi_t parameters);

#endif /*   POLYNOMFUN_H   */