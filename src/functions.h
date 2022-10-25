#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <Arduino.h>
#include <math.h>

typedef struct{
    float* fx;
    int fx_num;
}results_t;


float get_FloatUART();
float* get_PolynoImages(int degree, float* coeffi, int images_num, float inc);
results_t get_ImagFunctions();

#endif /*   FUNCTIONS_H   */

