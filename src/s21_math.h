#ifndef S21_MATH_H
#define S21_MATH_H

#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define S21_PI 3.141592653589793238462643380
#define S21_EXP 2.7182818284590452353602874
#define S21_INF 1.0 / 0.0
#define S21_INFF -1.0 / 0.0
#define S21_NAN 0.0 / 0.0
#define S21_EPS 1e-17
#define is_finite(x) __builtin_isfinite(x)
#define is_nan(x) __builtin_isnan(x)
#define is_inf(x) __builtin_isinf(x)
#define S21_INFF -1.0 / 0.0

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

long double pow_ceil(double base, double exp);

#endif


