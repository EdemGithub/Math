#include "s21_math.h"

#include <check.h>

START_TEST(abs_test) {
        ck_assert_int_eq(s21_abs(0), abs(0));
        ck_assert_int_eq(s21_abs(-1), abs(-1));
        ck_assert_int_eq(s21_abs(5), abs(5));
        ck_assert_int_eq(s21_abs(-2147483647), abs(-2147483647));
        ck_assert_int_eq(s21_abs(-0xA13), abs(-0xA13));
        ck_assert_int_eq(s21_abs(13), abs(13));
        ck_assert_int_eq(s21_abs(-0), abs(-0));
        ck_assert_int_eq(s21_abs(-05), abs(-05));
        ck_assert_int_eq(s21_abs(-00002345670), abs(-00002345670));
        ck_assert_int_eq(s21_abs(123456789), abs(123456789));
        ck_assert_int_eq(s21_abs(100), abs(100));
        ck_assert_int_eq(s21_abs(-100), abs(-100));
}
END_TEST

START_TEST(fabs_test) {
    ck_assert_ldouble_eq(s21_fabs(-5.53151413431), fabs(-5.53151413431));
    ck_assert_double_eq_tol(s21_fabs(-11245123.23), fabs(-11245123.23), 1e-6);
    ck_assert_double_eq_tol(s21_fabs(1023.l), fabs(1023.f), 1e-6);
    ck_assert_double_eq_tol(s21_fabs(0.l), fabs(0.f), 1e-6);
    ck_assert_double_eq_tol(s21_fabs(-12.456), fabs(-12.456), 1e-6);
    ck_assert_double_eq_tol(s21_fabs(-1.1), fabs(-1.1), 1e-6);
}
END_TEST

START_TEST(sin_test) {
    ck_assert_double_eq_tol(s21_sin(-1), sin(-1), 1e-6);
    ck_assert_double_eq_tol(s21_sin(1), sin(1), 1e-6);
    ck_assert_double_eq_tol(s21_sin(10), sin(10), 1e-6);
    ck_assert_double_eq_tol(s21_sin(0), sin(0), 1e-6);
    ck_assert_double_eq_tol(s21_sin(0x14BD), sin(0x14BD), 1e-6);
    ck_assert_double_eq_tol(s21_sin(145), sin(145), 1e-6);
    ck_assert_double_eq_tol(s21_sin(16), sin(16), 1e-6);
    ck_assert_double_eq_tol(s21_sin(5), sin(5), 1e-6);
    ck_assert_double_eq_tol(s21_sin(7), sin(7), 1e-6);
    ck_assert_double_eq_tol(s21_sin(-16), sin(-16), 1e-6);
    ck_assert_double_eq_tol(s21_sin(145986), sin(145986), 1e-6);
    ck_assert_int_eq(isnan(s21_sin(S21_NAN)), 1);
}
END_TEST

START_TEST(cos_test) {
    ck_assert_double_eq_tol(s21_cos(-3 * M_PI/2), cos(-3 * M_PI/2), 1e-6);
    ck_assert_double_eq_tol(s21_cos(1), cos(1), 1e-6);
    ck_assert_double_eq_tol(s21_cos(10), cos(10), 1e-6);
    ck_assert_double_eq_tol(s21_cos(0), cos(0), 1e-6);
    ck_assert_double_eq_tol(s21_cos(0x14BD), cos(0x14BD), 1e-6);
    ck_assert_double_eq_tol(s21_cos(145), cos(145), 1e-6);
    ck_assert_double_eq_tol(s21_cos(16), cos(16), 1e-6);
    ck_assert_double_eq_tol(s21_cos(5), cos(5), 1e-6);
    ck_assert_double_eq_tol(s21_cos(7), cos(7), 1e-6);
    ck_assert_double_eq_tol(s21_cos(-16), cos(-16), 1e-6);
    ck_assert_double_eq_tol(s21_cos(145986), cos(145986), 1e-6);
    ck_assert_int_eq(isnan(s21_cos(S21_NAN)), 1);
}
END_TEST

START_TEST(tan_test) {
    ck_assert_double_eq_tol(s21_tan(1), tan(1), 1e-6);
    ck_assert_double_eq_tol(s21_tan(10), tan(10), 1e-6);
    ck_assert_double_eq_tol(s21_tan(0), tan(0), 1e-6);
    ck_assert_double_eq_tol(s21_tan(0x14BD), tan(0x14BD), 1e-6);
    ck_assert_double_eq_tol(s21_tan(145), tan(145), 1e-6);
    ck_assert_double_eq_tol(s21_tan(16), tan(16), 1e-6);
    ck_assert_double_eq_tol(s21_tan(-16), tan(-16), 1e-6);
    ck_assert_int_eq(isnan(s21_tan(S21_NAN)), 1);
}
END_TEST

START_TEST(tan_2) {
    double num = 0.55;
    long double orig_res = s21_tan(num), our_res = s21_tan(num);
    int suc = 0;
    if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(tan_3) {
    ck_assert_float_eq(-9999999999, -9999999999);
}
END_TEST

START_TEST(tan_4) {
    double num = NAN;
    long double orig_res = tan(num), our_res = s21_tan(num);
    int suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(tan_5) {
    double num = INFINITY;
    long double orig_res = tan(num), our_res = s21_tan(num);
    int suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(tan_6) {
    double num = -INFINITY;
    long double orig_res = tan(num), our_res = s21_tan(num);
    int suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(tan_7) {
    double x = 0;
    ck_assert_double_eq_tol(s21_tan(x), tanl(x), 1e-06);
}
END_TEST

START_TEST(tan_8) {
    ck_assert_ldouble_nan(s21_tan(-INFINITY));
    ck_assert_ldouble_nan(tanl(-INFINITY));
}
END_TEST

START_TEST(tan_9) {
    ck_assert_ldouble_nan(s21_tan(INFINITY));
    ck_assert_ldouble_nan(tanl(INFINITY));
}
END_TEST

START_TEST(tan_10) {
    ck_assert_ldouble_nan(s21_tan(NAN));
    ck_assert_ldouble_nan(tanl(NAN));
}
END_TEST

START_TEST(tan_11) { ck_assert_double_eq_tol(s21_tan(0.0), tanl(0.0), 1e-06); }
END_TEST

START_TEST(tan_12) {
    ck_assert_double_eq_tol(s21_tan(M_PI / 6), tanl(M_PI / 6), 1e-06);
}
END_TEST

START_TEST(tan_13) {
    ck_assert_double_eq_tol(s21_tan(M_PI / 4), tanl(M_PI / 4), 1e-06);
}
END_TEST

START_TEST(tan_14) {
    ck_assert_double_eq_tol(s21_tan(-2 * M_PI), tanl(-2 * M_PI), 1e-06);
}
END_TEST

START_TEST(tan_15) {
    ck_assert_double_eq_tol(s21_tan(M_PI), tanl(M_PI), 1e-06);
}
END_TEST

START_TEST(tan_16) {
    ck_assert_double_eq_tol(s21_tan(M_PI / 3), tanl(M_PI / 3), 1e-06);
}
END_TEST

START_TEST(tan_17) {
    ck_assert_double_eq_tol(s21_tan(3 * M_PI / 3), tanl(3 * M_PI / 3), 1e-06);
}
END_TEST

START_TEST(tan_18) {
    ck_assert_double_eq_tol(s21_tan(174.532925199433), tanl(174.532925199433),
                            1e-06);
}
END_TEST

START_TEST(tan_19) {
    ck_assert_double_eq_tol(s21_tan(-174.532925199433), tanl(-174.532925199433),
                            1e-06);
}
END_TEST

START_TEST(tan_20) {
    ck_assert_double_eq_tol(s21_tan(S21_PI / 2), tanl(S21_PI / 2), 1e-06);
}
END_TEST

START_TEST(tan_21) {
    ck_assert_double_eq_tol(s21_tan(-S21_PI / 2), tanl(-S21_PI / 2), 1e-06);
}
END_TEST


START_TEST(atan_test) {
    double value1 = 0.43;
    ck_assert_uint_eq(s21_atan(value1), atan(value1));
    double value2 = 0.12;
    ck_assert_uint_eq(s21_atan(value2), atan(value2));
    double value3 = 1;
    ck_assert_uint_eq(s21_atan(value3), atan(value3));
    double value4 = -1;
    ck_assert_uint_eq(s21_atan(value4), atan(value4));
    double value5 = 0;
    ck_assert_uint_eq(s21_atan(value5), atan(value5));
    double value6 = 12345;
    ck_assert_uint_eq(s21_atan(value6), atan(value6));
    double value7 = 0.001;
    ck_assert_uint_eq(s21_atan(value7), atan(value7));
    double value8 = -12345;
    ck_assert_uint_eq(s21_atan(value8), atan(value8));
    for (double i = -1; i <= 1; i += 0.01) {
        ck_assert_uint_eq(s21_atan(i), atan(i));
    }
    ck_assert_double_eq_tol(s21_atan(-3*S21_PI/2), atan(-3*S21_PI/2), 1e-6);
} END_TEST

START_TEST(acos_test) {
    double value1 = 0.43;
    ck_assert_uint_eq(s21_acos(value1), acos(value1));
    double value2 = -1;
    ck_assert_uint_eq(s21_acos(value2), acos(value2));
    double value3 = -0.999;
    ck_assert_uint_eq(s21_acos(value3), acos(value3));
    for (double i = -10.; i < 10.; i += 1.) {
        ck_assert_uint_eq(s21_acos(i), acos(i));
    }
    for (double i = -1; i < 1; i += 0.01) {
        ck_assert_uint_eq(s21_acos(i), acos(i));
    }
} END_TEST

START_TEST(asin_test) {
    double value1 = 0.43;
    ck_assert_uint_eq(s21_asin(value1), asin(value1));
    double value2 = 0.12;
    ck_assert_uint_eq(s21_asin(value2), asin(value2));
    for (double i = 0.; i < 2; i += 1) {
        ck_assert_uint_eq(s21_asin(i), asin(i));
    }
    for (double i = -1; i < 5; i += 0.01) {
        ck_assert_uint_eq(s21_asin(i), asin(i));
    }
} END_TEST

START_TEST(cos_1) {
    double num = 0.55;
    long double orig_res = s21_cos(num), our_res = s21_cos(num);
    int suc = 0;
    if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cos_2) {
    double num = -0.999999;
    long double orig_res = cos(num), our_res = s21_cos(num);
    int suc = 0;
    if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cos_3) {
    double num = 628;
    long double orig_res = cos(num), our_res = s21_cos(num);
    int suc = 0;
    if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cos_4) { ck_assert_float_eq(s21_cos(0), cos(0)); }
END_TEST

START_TEST(cos_5) { ck_assert_float_eq(s21_cos(-1), cos(-1)); }
END_TEST

START_TEST(cos_6) {
    double num = NAN;
    long double orig_res = cos(num), our_res = s21_cos(num);
    int suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cos_7) {
    double num = INFINITY;
    long double orig_res = cos(num), our_res = s21_cos(num);
    int suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cos_8) {
    double num = -INFINITY;
    long double orig_res = cos(num), our_res = s21_cos(num);
    int suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(cos_9) {
    double x = 0;
    ck_assert_double_eq_tol(s21_cos(x), cosl(x), 1e-06);
}
END_TEST

START_TEST(cos_10) {
    ck_assert_ldouble_nan(s21_cos(-INFINITY));
    ck_assert_ldouble_nan(cosl(-INFINITY));
}
END_TEST

START_TEST(cos_11) {
    ck_assert_ldouble_nan(s21_cos(INFINITY));
    ck_assert_ldouble_nan(cosl(INFINITY));
}
END_TEST

START_TEST(cos_12) {
    ck_assert_ldouble_nan(s21_cos(NAN));
    ck_assert_ldouble_nan(cosl(NAN));
}
END_TEST

START_TEST(cos_13) { ck_assert_double_eq_tol(s21_cos(0.0), cosl(0.0), 1e-06); }
END_TEST

START_TEST(cos_14) {
    ck_assert_double_eq_tol(s21_cos(M_PI / 4), cosl(M_PI / 4), 1e-06);
}
END_TEST

START_TEST(cos_15) {
    ck_assert_double_eq_tol(s21_cos(M_PI / 6), cosl(M_PI / 6), 1e-06);
}
END_TEST

START_TEST(cos_16) {
    ck_assert_double_eq_tol(s21_cos(M_PI / 3), cosl(M_PI / 3), 1e-06);
}
END_TEST

START_TEST(cos_17) {
    ck_assert_double_eq_tol(s21_cos(M_PI / 2), cosl(M_PI / 2), 1e-06);
    ck_assert_double_eq_tol(s21_cos(M_PI / 2), cos(M_PI / 2), 1e-06);
}
END_TEST

START_TEST(cos_18) {
    ck_assert_double_eq_tol(s21_cos(3 * M_PI / 2), cosl(3 * M_PI / 2), 1e-06);
}
END_TEST

START_TEST(cos_19) {
    ck_assert_double_eq_tol(s21_cos(2 * M_PI), cosl(2 * M_PI), 1e-06);
}
END_TEST

START_TEST(cos_20) {
    ck_assert_double_eq_tol(s21_cos(174.532925199433), cosl(174.532925199433),
                            1e-06);
}
END_TEST

START_TEST(cos_21) {
    ck_assert_double_eq_tol(s21_cos(-174.532925199433), cosl(-174.532925199433),
                            1e-06);
}
END_TEST



START_TEST(pow_test) {
    // подаем целые положительные числа, положительная степень
    ck_assert_double_eq_tol(pow(5, 2), s21_pow(5, 2), 1e-6);
    ck_assert_double_eq_tol(pow(5, 0), s21_pow(5, 0), 1e-6);
    ck_assert_double_eq_tol(pow(5, 1), s21_pow(5, 1), 1e-6);
    ck_assert_double_eq_tol(pow(1, 5), s21_pow(1, 5), 1e-6);
    ck_assert_double_eq_tol(pow(0, 2), s21_pow(0, 2), 1e-6);
    ck_assert_double_eq_tol(pow(0, 0), s21_pow(0, 0), 1e-6);
    ck_assert_double_eq_tol(pow(1, 1), s21_pow(1, 1), 1e-6);
    ck_assert_double_eq_tol(pow(5, 234), s21_pow(5, 234), 1e-6);
    ck_assert_double_eq_tol(pow(2, 999), s21_pow(2, 999), 1e-6);
    ck_assert_ldouble_infinite(pow(7, 8479274));
    ck_assert_ldouble_infinite(s21_pow(7, 8479274));
    ck_assert_double_eq_tol(pow('f', 2), s21_pow('f', 2), 1e-6);
    ck_assert_double_eq_tol(pow(' ', 2), s21_pow(' ', 2), 1e-6);

    // подаем целые положительные числа, отрицательная степень степень
    ck_assert_double_eq_tol(pow(5, -2), s21_pow(5, -2), 1e-6);
    ck_assert_double_eq_tol(pow(5, -3), s21_pow(5, -3), 1e-6);
    ck_assert_double_eq_tol(pow(5, -1), s21_pow(5, -1), 1e-6);
    ck_assert_double_eq_tol(pow(5, -7), s21_pow(5, -7), 1e-6);
    ck_assert_double_eq_tol(pow(5, -12), s21_pow(5, -12), 1e-6);
    ck_assert_double_eq_tol(pow(5, -100), s21_pow(5, -100), 1e-6);
    ck_assert_double_eq_tol(pow(5, -234), s21_pow(5, -234), 1e-6);
    ck_assert_double_eq_tol(pow(5, -0), s21_pow(5, -0), 1e-6);
    ck_assert_double_eq_tol(pow(5, -88), s21_pow(5, -88), 1e-6);
    ck_assert_double_eq_tol(pow(1, -4), s21_pow(1, -4), 1e-6);
    ck_assert_double_eq_tol(pow(5, -'g'), s21_pow(5, -'g'), 1e-6);
    ck_assert_ldouble_infinite(pow(0, -2));
    ck_assert_ldouble_infinite(s21_pow(0, -2));
    ck_assert_double_eq_tol(pow(0, -0), s21_pow(0, -0), 1e-6);
    ck_assert_double_eq_tol(pow(1, -1), s21_pow(1, -1), 1e-6);
    ck_assert_double_eq_tol(pow(8479274, -7), s21_pow(8479274, -7), 1e-6);
    ck_assert_double_eq_tol(pow('f', -2), s21_pow('f', -2), 1e-6);
    ck_assert_double_eq_tol(pow(' ', -2), s21_pow(' ', -2), 1e-6);
    ck_assert_ldouble_infinite(pow(S21_INF, 2));
    ck_assert_ldouble_infinite(s21_pow(S21_INF, 2));
    ck_assert_ldouble_infinite(pow(7, 8479274));
    ck_assert_ldouble_infinite(s21_pow(7, 8479274));

    // подаем целые отрицательные числа, положительная степень
    ck_assert_double_eq_tol(pow(-5, 2), s21_pow(-5, 2), 1e-6);
    ck_assert_double_eq_tol(pow(-5, 0), s21_pow(-5, 0), 1e-6);
    ck_assert_double_eq_tol(pow(-5, 1), s21_pow(-5, 1), 1e-6);
    ck_assert_double_eq_tol(pow(-1, 5), s21_pow(-1, 5), 1e-6);
    ck_assert_double_eq_tol(pow(-0, 2), s21_pow(-0, 2), 1e-6);
    ck_assert_double_eq_tol(pow(-0, 0), s21_pow(-0, 0), 1e-6);
    ck_assert_double_eq_tol(pow(-1, 1), s21_pow(-1, 1), 1e-6);
    ck_assert_ldouble_infinite(pow(7, 8479274));
    ck_assert_ldouble_infinite(s21_pow(7, 8479274));
    ck_assert_double_eq_tol(pow(-'f', 2), s21_pow(-'f', 2), 1e-6);
    ck_assert_double_eq_tol(pow(-' ', 2), s21_pow(-' ', 2), 1e-6);

    // подаем числа с плавающей запятой, положительная целая степень
    ck_assert_double_eq_tol(pow(5.72, 2), s21_pow(5.72, 2), 1e-6);
    ck_assert_double_eq_tol(pow(5.04, 0), s21_pow(5.04, 0), 1e-6);
    ck_assert_double_eq_tol(pow(5.98, 1), s21_pow(5.98, 1), 1e-6);
    ck_assert_double_eq_tol(pow(1.0000001, 5), s21_pow(1.0000001, 5), 1e-6);
    ck_assert_double_eq_tol(pow(0.70, 2), s21_pow(0.70, 2), 1e-6);
    ck_assert_double_eq_tol(pow(0.3333333333333333, 0), s21_pow(0.3333333333333333, 0), 1e-6);
    ck_assert_double_eq_tol(pow(1.3, 1), s21_pow(1.3, 1), 1e-6);
    ck_assert_double_eq_tol(pow(8479274.6, 7), s21_pow(8479274.6, 7), 1e-6);

    // подаем числа с плавающей запятой, положительная дробная степень
    ck_assert_double_eq_tol(pow(5.67, 2.3), s21_pow(5.67, 2.3), 1e-6);
    ck_assert_double_eq_tol(pow(5.09, 0.1), s21_pow(5.09, 0.1), 1e-6);
    ck_assert_double_eq_tol(pow(5.87, 1.33), s21_pow(5.87, 1.33), 1e-6);
    ck_assert_double_eq_tol(pow(1.0000000000000000001, 5.33333),
                            s21_pow(1.0000000000000000001, 5.33333), 1e-6);
    ck_assert_double_eq_tol(pow(0.9999999999, 2), s21_pow(0.9999999999, 2), 1e-6);
    ck_assert_double_eq_tol(pow(0.9, 0), s21_pow(0.9, 0), 1e-6);
    ck_assert_double_eq_tol(pow(0, 0.42), s21_pow(0, 0.42), 1e-6);
    ck_assert_double_eq_tol(pow(1.42, 1.93), s21_pow(1.42, 1.93), 1e-6);
    ck_assert_ldouble_infinite(pow(7, 8479274));
    ck_assert_ldouble_infinite(s21_pow(7, 8479274));
    ck_assert_double_eq_tol(pow('f', 2), s21_pow('f', 2), 1e-6);
    ck_assert_double_eq_tol(pow(' ', 2), s21_pow(' ', 2), 1e-6);

    ck_assert_double_eq(pow(-1, 1), s21_pow(-1, 1));
    ck_assert_double_eq_tol(pow(INT_MIN, 1), s21_pow(INT_MIN, 1), 1e-06);
    ck_assert_double_eq_tol(pow(-INT_MAX, 1), s21_pow(-INT_MAX, 1), 1e-06);
    ck_assert_double_eq(pow(2, 2), s21_pow(2, 2));
    ck_assert_double_eq_tol(pow(2.2, 2.2), s21_pow(2.2, 2.2), 1e-06);
    ck_assert_double_eq_tol(pow(2, 0.5), s21_pow(2, 0.5), 1e-06);
    ck_assert_ldouble_eq_tol(pow(0.9, 20), s21_pow(0.9, 20), 1e-06);
    ck_assert_double_eq(pow(0.9, -20), s21_pow(0.9, -20));
    ck_assert_double_eq(pow(100, 100), s21_pow(100, 100));
    ck_assert_double_eq(pow(100, 0), s21_pow(100, 0));
    ck_assert_double_eq(pow(0, 100), s21_pow(0, 100));
    ck_assert_double_eq(pow(100, 1), s21_pow(100, 1));
    ck_assert_double_eq(pow(1, 100), s21_pow(1, 100));
    ck_assert_double_eq(pow(13, 501), s21_pow(13, 501));
    ck_assert_double_eq_tol(pow(87.78, 13), s21_pow(87.78, 13), 1e-06);
    ck_assert_double_eq_tol(pow(0.02, 0.4), s21_pow(0.02, 0.4), 1e-06);
    ck_assert_double_nan(s21_pow(-10, 9.1));
    ck_assert_int_eq(s21_pow(S21_INF, 1.1), pow(S21_INF, 1.1));
    ck_assert_double_eq(pow(S21_INF, S21_INF), s21_pow(S21_INF, S21_INF));
    ck_assert_double_nan(s21_pow(-10.1261, -0.72));
    ck_assert_double_nan(pow(-10.1261, -0.72));
    ck_assert_ldouble_eq_tol(s21_pow(-0, S21_INF), pow(-0, S21_INF), 1e-06);
    ck_assert_ldouble_eq_tol(s21_pow(-1, S21_INF), pow(-1, S21_INF), 1e-06);
    ck_assert_ldouble_infinite(s21_pow(-S21_INF, S21_INF));
    ck_assert_ldouble_eq_tol(s21_pow(0.0, 0.0), pow(0.0, 0.0), 1e-06);
    ck_assert_ldouble_eq_tol(s21_pow(-1, 4), pow(-1, 4), 1e-06);
    ck_assert_ldouble_eq_tol(s21_pow(2, 18), pow(2, 18), 1e-06);
    ck_assert_ldouble_eq_tol(s21_pow(2.1, 11), pow(2.1, 11), 1e-06);
    ck_assert_ldouble_infinite(s21_pow(+0, -S21_INF));
    ck_assert_ldouble_infinite(pow(+0, -S21_INF));
    ck_assert_ldouble_eq_tol(s21_pow(+0, 2.456), pow(+0, 2.456), 1e-06);
    ck_assert_double_nan(s21_pow(+0, S21_NAN));
    ck_assert_double_nan(pow(+0, S21_NAN));
    ck_assert_ldouble_eq_tol(s21_pow(+0, 56), pow(+0, 56), 1e-06);
    ck_assert_ldouble_eq_tol(s21_pow(-0, 56), pow(-0, 56), 1e-06);
    ck_assert_ldouble_eq_tol(s21_pow(-0, 56.345), pow(-0, 56.345), 1e-06);
    ck_assert_double_nan(s21_pow(S21_NAN, S21_NAN));
    ck_assert_double_nan(pow(S21_NAN, S21_NAN));
    ck_assert_ldouble_infinite(s21_pow(S21_INF, S21_INF));
    ck_assert_ldouble_infinite(pow(S21_INF, S21_INF));
    {
        double num = 456.789;
        double exp = 1.1;
        long double original_result = pow(num, exp);
        long double yyour_resultult = s21_pow(num, exp);
        int check = 0;
        ck_assert_float_eq(original_result, original_result);
        if ((fabsl(original_result - yyour_resultult) <= 1e-06)) check = 1;
        ck_assert_int_eq(1, check);
    }

    {
        double num = NAN;
        double exp = 1.1;
        long double original_result = pow(num, exp);
        long double yyour_resultult = s21_pow(num, exp);
        int check = 0;
        if (isnan(original_result) && isnan(yyour_resultult)) check = 1;
        ck_assert_int_eq(1, check);
    }

    {
        double num = NAN;
        double exp = NAN;
        long double original_result = pow(num, exp);
        long double yyour_resultult = s21_pow(num, exp);
        int check = 0;
        if (isnan(yyour_resultult) && isnan(original_result)) check = 1;
        ck_assert_int_eq(1, check);
    }

    {
        double num = 0.001;
        double exp = NAN;
        long double original_result = pow(num, exp), your_result = s21_pow(num, exp);
        int check = 0;
        if (isnan(your_result) && isnan(original_result)) check = 1;
        ck_assert_int_eq(1, check);
    }

    {
        double num = INFINITY;
        double exp = INFINITY;
        long double original_result = pow(num, exp), your_result = s21_pow(num, exp);
        int check = 0;
        if (isinf(your_result) && isinf(original_result)) check = 1;
        ck_assert_int_eq(1, check);
    }

    {
        long double base = -16.161435;
        long double exp = 9.;
        ck_assert_float_eq_tol(s21_pow(-16.161435, 9.), pow(base, exp), 1e-06);
    }

    {
        ck_assert_double_nan(s21_pow(-10.1261, -0.72));
        ck_assert_double_nan(pow(-10.1261, -0.72));
    }

    {
        long double base = +0;
        long double exp = -0.33;
        ck_assert_ldouble_infinite(s21_pow(base, exp));
        ck_assert_ldouble_infinite(pow(base, exp));
    }

    {
        long double base = -0;
        long double exp = -0.33;
        ck_assert_ldouble_infinite(s21_pow(base, exp));
        ck_assert_ldouble_infinite(pow(base, exp));
    }

    {
        long double base = +0;
        long double exp = 123;
        ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-06);
    }

    {
        long double base = -0;
        long double exp = 123;
        ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-06);
    }

    {
        long double base = -0;
        long double exp = S21_INF;
        ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-06);
    }

    {
        long double base = -1;
        long double exp = S21_NAN;
        ck_assert_double_nan(pow(base, exp));
        ck_assert_double_nan(s21_pow(base, exp));
    }

    {
        long double base = S21_NAN;
        long double exp = 0;
        ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-06);
    }

    {
        long double base = -123;
        long double exp = S21_NAN;
        ck_assert_double_nan(s21_pow(base, exp));
        ck_assert_double_nan(pow(base, exp));
    }

    {
        long double base = 0.5591951;
        long double exp = -S21_INF;
        ck_assert_ldouble_infinite(pow(base, exp));
        ck_assert_ldouble_infinite(s21_pow(base, exp));
    }

    {
        long double base = 1.5591951;
        long double exp = -S21_INF;
        ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-06);
    }

    {
        long double base = 0.5591951;
        long double exp = S21_INF;
        ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-06);
    }

    {
        long double base = 1.5591951;
        long double exp = S21_INF;
        ck_assert_ldouble_infinite(s21_pow(base, exp));
        ck_assert_ldouble_infinite(pow(base, exp));
    }

    {
        long double base = -S21_INF;
        long double exp = -193491;
        ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-06);
    }

    {
        long double base = -S21_INF;
        long double exp = -142;
        ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-06);
    }

    {
        long double base = -S21_INF;
        long double exp = 141;
        ck_assert_ldouble_infinite(s21_pow(base, exp));
        ck_assert_ldouble_infinite(pow(base, exp));
    }

    {
        long double base = -S21_INF;
        long double exp = 142;
        ck_assert_ldouble_infinite(s21_pow(base, exp));
        ck_assert_ldouble_infinite(pow(base, exp));
    }

    {
        long double base = S21_INF;
        long double exp = -1;
        ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), 1e-06);
    }

    {
        long double base = S21_INF;
        long double exp = 1;
        ck_assert_ldouble_infinite(s21_pow(base, exp));
        ck_assert_ldouble_infinite(pow(base, exp));
    }

    {
        ck_assert_ldouble_eq_tol(s21_pow(1.23456e-7, 2.21), pow(1.23456e-7, 2.21),
                                 1e-06);
    }

    {
        long double original_result = pow(2.1234567e-7, -2.45e4),
                your_result = s21_pow(2.1234567e-7, -2.45e4);
        int check = 0;
        if (isinf(your_result) && isinf(original_result)) check = 1;
        ck_assert_int_eq(1, check);
    }

    {
        ck_assert_ldouble_eq_tol(s21_pow(9.99999999e3, 9.95e-4),
                                 pow(9.99999999e3, 9.95e-4), 1e-06);
    }

    {
        double exp = 0;
        double res1 = 0;
        long double res2 = 0;

        for (exp = 0.0; exp > -1000; exp -= 0.1) {
            res1 = pow(S21_INF, exp);
            res2 = s21_pow(S21_INF, exp);
        }
        ck_assert_ldouble_eq_tol(res1, res2, 1e-06);
    }

    {
        double base = 0;
        double res1 = 0;
        long double res2 = 0;

        for (base = 0.0; base < 10; base += 0.1) {
            res1 = pow(base, S21_INF);
            res2 = s21_pow(base, S21_INF);
        }
        ck_assert_ldouble_infinite(res1);
        ck_assert_ldouble_infinite(res2);
    }

    {
        double base = 0;
        double res1 = 0;
        long double res2 = 0;

        for (base = 0.0; base > -10; base -= 0.1) {
            res1 = pow(base, S21_INF);
            res2 = s21_pow(base, S21_INF);
        }
        ck_assert_ldouble_infinite(res1);
        ck_assert_ldouble_infinite(res2);
    }

    {
        long double base = 0;
        long double res1 = 0;
        long double res2 = 0;

        for (base = 0.0; base < 10; base += 0.1) {
            res1 = pow(base, -S21_INF);
            res2 = s21_pow(base, -S21_INF);
        }
        ck_assert_ldouble_eq_tol(res1, res2, 1e-06);
    }

    {
        long double base = 0;
        long double res1 = 0;
        long double res2 = 0;

        for (base = 0.0; base > -10; base -= 0.1) {
            res1 = pow(base, -S21_INF);
            res2 = s21_pow(base, -S21_INF);
        }
        ck_assert_ldouble_eq_tol(res1, res2, 1e-06);
    }

    {
        double exp = 0;
        double res1 = 0;
        long double res2 = 0;

        for (exp = 0.0; exp > -10; exp -= 0.1) {
            if (fmod(exp, 2) != 0) {
                res1 = pow(-S21_INF, exp);
                res2 = s21_pow(-S21_INF, exp);
            }
        }
        ck_assert_ldouble_eq_tol(res1, res2, 1e-06);
    }

    {
        double exp = 0;
        double res1 = 0;
        long double res2 = 0;

        for (exp = 0.0; exp > -10; exp -= 0.1) {
            if (fmod(exp, 2) == 0) {
                res1 = pow(-S21_INF, exp);
                res2 = s21_pow(-S21_INF, exp);
            }
        }
        ck_assert_ldouble_eq_tol(res1, res2, 1e-06);
    }

    {
        double exp = 0;
        double res1 = 0;
        long double res2 = 0;

        for (exp = 0.0; exp < 10; exp += 0.1) {
            if (fmod(exp, 2) != 0) {
                res1 = pow(-S21_INF, exp);
                res2 = s21_pow(-S21_INF, exp);
            }
        }
        ck_assert_ldouble_infinite(res1);
        ck_assert_ldouble_infinite(res2);
    }

    {
        double exp = 0;
        double res1 = 0;
        long double res2 = 0;

        for (exp = 0.0; exp < 10; exp += 0.1) {
            if (fmod(exp, 2) == 0) {
                res1 = pow(-S21_INF, exp);
                res2 = s21_pow(-S21_INF, exp);
            }
        }
        ck_assert_ldouble_eq_tol(res2, res1, 1e-06);
    }

    {
        long double exp = 3;
        ck_assert_ldouble_eq_tol(s21_pow(-3, exp), pow(-3, exp), 1e-06);
    }

    {
        long double exp = -3;
        ck_assert_ldouble_eq_tol(s21_pow(-3, exp), pow(-3, exp), 1e-06);
    }

    {
        long double exp = -3;
        ck_assert_ldouble_eq_tol(s21_pow(3, exp), pow(3, exp), 1e-06);
    }

    {
        long double exp = 3;
        ck_assert_ldouble_eq_tol(s21_pow(3, exp), pow(3, exp), 1e-06);
    }

    {
        long double base = -0;
        long double exp = S21_INF;
        long double res = pow(base, exp);
        long double res1 = s21_pow(base, exp);
        ck_assert_ldouble_eq_tol(res, res1, 1e-06);
    }

    {
        long double exp = 0;
        long double base = -0;
        long double res = 0;
        long double res1 = 0;
        for (exp = 0.0; exp < 10; exp += 0.1) {
            if (fmod(exp, 2) != 0) {
                res = pow(base, exp);
                res1 = s21_pow(base, exp);
            }
        }
        ck_assert_ldouble_eq_tol(res, res1, 1e-06);
    }
}
END_TEST

START_TEST(sqrt_test) {
    ck_assert_double_eq_tol(sqrt(9), s21_sqrt(9), 1e-6);
    ck_assert_double_eq_tol(sqrt(8), s21_sqrt(8), 1e-6);
    ck_assert_double_eq_tol(sqrt(7), s21_sqrt(7), 1e-6);
    ck_assert_double_eq_tol(sqrt(6), s21_sqrt(6), 1e-6);
    ck_assert_double_eq_tol(sqrt(5), s21_sqrt(5), 1e-6);
    ck_assert_double_eq_tol(sqrt(4), s21_sqrt(4), 1e-6);
    ck_assert_double_eq_tol(sqrt(3), s21_sqrt(3), 1e-6);
    ck_assert_double_eq_tol(sqrt(2), s21_sqrt(2), 1e-6);
    ck_assert_double_eq_tol(sqrt(1), s21_sqrt(1), 1e-6);
    ck_assert_double_eq_tol(sqrt(0), s21_sqrt(0), 1e-6);
    ck_assert_double_eq_tol(sqrt(4), s21_sqrt(4), 1e-6);
    ck_assert_double_eq_tol(sqrt(612), s21_sqrt(612), 1e-6);
    ck_assert_double_eq_tol(sqrt(4.4), s21_sqrt(4.4), S21_EPS);
    ck_assert_double_eq_tol(sqrt(LONG_MAX), sqrt(LONG_MAX), S21_EPS);
    ck_assert_double_nan(s21_sqrt(-1));
    ck_assert_double_eq_tol(sqrt(0), s21_sqrt(0), S21_EPS);
    ck_assert_double_eq_tol(sqrt(1), s21_sqrt(1), S21_EPS);
    ck_assert_double_nan(s21_sqrt(INT_MIN));
    ck_assert_double_nan(s21_sqrt(-INT_MAX));
    ck_assert_double_eq_tol(s21_sqrt(2), sqrt(2), 1e-06);
    ck_assert_double_infinite(s21_sqrt(S21_INF));
    ck_assert_double_nan(s21_sqrt(-S21_INF));
    double num = -15.01;
    ck_assert_ldouble_nan(s21_sqrt(num));
    ck_assert_ldouble_infinite(s21_sqrt(INFINITY));
    ck_assert_ldouble_infinite(sqrt(INFINITY));
    ck_assert_ldouble_nan(s21_sqrt(NAN));
    ck_assert_ldouble_nan(sqrt(NAN));
    ck_assert_ldouble_eq_tol(s21_sqrt(1.0), sqrt(1.0), 1e-06);
    ck_assert_ldouble_eq_tol(s21_sqrt(1.1), sqrt(1.1), 1e-06);
    ck_assert_ldouble_eq_tol(s21_sqrt(0.0), sqrt(0.0), 1e-06);
    ck_assert_ldouble_eq_tol(s21_sqrt(-0.0), sqrt(-0.0), 1e-06);
    ck_assert_ldouble_eq_tol(s21_sqrt(10e+16), sqrt(10e+16), 1e-06);
    ck_assert_ldouble_eq_tol(s21_sqrt(1), sqrt(1), 1e-06);
    ck_assert_ldouble_eq_tol(s21_sqrt(100), sqrt(100), 1e-06);
    ck_assert_ldouble_eq_tol(s21_sqrt(98765432.123), sqrt(98765432.123), 1e-06);
    ck_assert_ldouble_eq_tol(s21_sqrt(981.123e6), sqrt(981.123e6), 1e-06);
    ck_assert_ldouble_eq_tol(s21_sqrt(981.123e-15), sqrt(981.123e-15), 1e-06);
}
END_TEST

START_TEST(exp_test) {
    ck_assert_double_eq_tol(exp(0), s21_exp(0), 1e-6);
    ck_assert_double_eq_tol(exp(1), s21_exp(1), 1e-6);
    ck_assert_double_eq_tol(exp(2), s21_exp(2), 1e-6);
    ck_assert_double_eq_tol(exp(3), s21_exp(3), 1e-6);
    ck_assert_double_eq_tol(exp(4), s21_exp(4), 1e-6);
    ck_assert_double_eq_tol(exp(5), s21_exp(5), 1e-6);
    ck_assert_double_eq_tol(exp(6), s21_exp(6), 1e-6);
    ck_assert_double_eq_tol(exp(7), s21_exp(7), 1e-6);
    ck_assert_double_eq_tol(exp(8), s21_exp(8), 1e-6);
    ck_assert_double_eq_tol(exp(9), s21_exp(9), 1e-6);
    ck_assert_double_eq_tol(exp(10), s21_exp(10), 1e-6);
    ck_assert_double_eq_tol(exp(20), s21_exp(20), 1e-6);
    ck_assert_double_eq_tol(exp(12), s21_exp(12), 1e-6);
    ck_assert_double_eq_tol(exp(13), s21_exp(13), 1e-6);
    ck_assert_double_eq_tol(exp(15), s21_exp(15), 1e-6);
    ck_assert_double_eq_tol(exp(17), s21_exp(17), 1e-6);
    ck_assert_double_eq_tol(exp(18), s21_exp(18), 1e-6);

    ck_assert_double_eq_tol(exp(-0), s21_exp(-0), 1e-6);
    ck_assert_double_eq_tol(exp(-1), s21_exp(-1), 1e-6);
    ck_assert_double_eq_tol(exp(-2), s21_exp(-2), 1e-6);
    ck_assert_double_eq_tol(exp(-3), s21_exp(-3), 1e-6);
    ck_assert_double_eq_tol(exp(-4), s21_exp(-4), 1e-6);
    ck_assert_double_eq_tol(exp(-5), s21_exp(-5), 1e-6);
    ck_assert_double_eq_tol(exp(-6), s21_exp(-6), 1e-6);
    ck_assert_double_eq_tol(exp(-7), s21_exp(-7), 1e-6);
    ck_assert_double_eq_tol(exp(-8), s21_exp(-8), 1e-6);
    ck_assert_double_eq_tol(exp(-9), s21_exp(-9), 1e-6);
    ck_assert_double_eq_tol(exp(-10), s21_exp(-10), 1e-6);
    ck_assert_double_eq_tol(exp(-20), s21_exp(-20), 1e-6);
    ck_assert_double_eq_tol(exp(-12), s21_exp(-12), 1e-6);
    ck_assert_double_eq_tol(exp(-13), s21_exp(-13), 1e-6);
    ck_assert_double_eq_tol(exp(-15), s21_exp(-15), 1e-6);
    ck_assert_double_eq_tol(exp(-17), s21_exp(-17), 1e-6);
    ck_assert_double_eq_tol(exp(-18), s21_exp(-18), 1e-6);

    ck_assert_ldouble_eq_tol(s21_exp(0.05), exp(0.05), 1e-06);
    ck_assert_ldouble_eq_tol(s21_exp(-0.5), exp(-0.5), 1e-06);
    ck_assert_int_eq(s21_exp(1.5), exp(1.5));
    ck_assert_int_eq(s21_exp(-1.5), exp(-1.5));
    ck_assert_int_eq(s21_exp(715), exp(715));
    ck_assert_int_eq(s21_exp(-715), exp(-715));


    ck_assert_ldouble_eq_tol(s21_exp(-100), exp(-100), 1e-06);
    ck_assert_ldouble_eq_tol(s21_exp(-10000000), exp(-10000000), 1e-06);

    ck_assert_ldouble_eq_tol(s21_exp(-' '), exp(-' '), 1e-06);
    ck_assert_ldouble_eq_tol(s21_exp(0 / 1), exp(0 / 1), 1e-06);
    ck_assert_float_eq(s21_exp(-750), exp(-750));
    ck_assert_ldouble_eq_tol(s21_exp(-INFINITY), exp(-INFINITY), 1e-06);
    ck_assert_ldouble_infinite(s21_exp(INFINITY));
    ck_assert_ldouble_infinite(exp(INFINITY));
    ck_assert_ldouble_nan(s21_exp(NAN));
    ck_assert_ldouble_nan(exp(NAN));

    {
        double num = NAN;
        long double orig_res = exp(num), our_res = s21_exp(num);
        int suc = 0;
        if (isnan(orig_res) && isnan(our_res)) suc = 1;
        ck_assert_int_eq(1, suc);
    }
    {
        double num = INFINITY;
        long double orig_res = exp(num), our_res = s21_exp(num);
        int suc = 0;
        if (isinf(orig_res) && isinf(our_res)) suc = 1;
        ck_assert_int_eq(1, suc);
    }
    {
        double num = -INFINITY;
        long double orig_res = exp(num), our_res = s21_exp(num);
        int suc = 0;
        if ((fabsl(orig_res - our_res) <= 1e-6)) suc = 1;
        ck_assert_int_eq(1, suc);
    }

    {
        double num = 1000000;
        long double orig_res = exp(num), our_res = s21_exp(num);
        int suc = 0;
        if (isinf(orig_res) && isinf(our_res)) suc = 1;
        ck_assert_int_eq(1, suc);
    }
}
END_TEST

START_TEST(zero) { ck_assert_double_eq(s21_log(0), -S21_INF); }
END_TEST

START_TEST(one) { ck_assert_double_eq(s21_log(1), log(1)); }
END_TEST

START_TEST(fifty) { ck_assert_ldouble_eq_tol(s21_log(50), log(50), 1e-06); }
END_TEST

START_TEST(negative_fifty) { ck_assert_ldouble_nan(s21_log(-50)); }
END_TEST

START_TEST(negative) { ck_assert_double_nan(s21_log(-1)); }
END_TEST

START_TEST(thirteen) { ck_assert_double_eq_tol(s21_log(13), log(13), 1e-06); }
END_TEST

START_TEST(not_a_num) { ck_assert_double_nan(s21_log(S21_NAN)); }
END_TEST

START_TEST(infinity) { ck_assert_double_eq(s21_log(S21_INF), log(S21_INF)); }
END_TEST

START_TEST(negative_infinity) { ck_assert_double_nan(s21_log(-S21_INF)); }
END_TEST

START_TEST(log_1) {
    double num = 456.789;
    long double orig_res = log(num);
    long double our_res = s21_log(num);
    int suc = 0;
    if ((fabsl(orig_res - our_res) <= 6)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_2) {
    double num = NAN;
    long double orig_res = log(num);
    long double our_res = s21_log(num);
    int suc = 0;
    if (isnan(our_res) && isnan(orig_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_3) {
    double num = 0.001;
    long double orig_res = log(num);
    long double our_res = s21_log(num);
    int suc = 0;
    if ((fabsl(orig_res - our_res) <= 6)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_4) {
    double num = 0.4;
    long double orig_res = log(num);
    long double our_res = s21_log(num);
    int suc = 0;
    if ((fabsl(orig_res - our_res) <= 1e-06)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_5) {
    double num = -INFINITY;
    long double orig_res = log(num);
    long double our_res = s21_log(num);
    int suc = 0;
    if (isnan(our_res) && isnan(orig_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_6) {
    double num = INFINITY;
    long double orig_res = log(num);
    long double our_res = s21_log(num);
    int suc = 0;
    if (isinf(our_res) && isinf(orig_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(log_7) {
    ck_assert_ldouble_infinite(s21_log(INFINITY));
    ck_assert_ldouble_infinite(log(INFINITY));

    ck_assert_ldouble_nan(s21_log(-INFINITY));
    ck_assert_ldouble_nan(log(-INFINITY));
}
END_TEST

START_TEST(log_8) {
    ck_assert_ldouble_nan(s21_log(NAN));
    ck_assert_ldouble_nan(log(NAN));
}
END_TEST

START_TEST(log_9) {
    ck_assert_ldouble_eq_tol(s21_log(1.0), log(1.0), 1e-06);
    ck_assert_ldouble_eq_tol(s21_log(1.1), log(1.1), 1e-06);
}
END_TEST

START_TEST(log_10) { ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), 1e-06); }
END_TEST

START_TEST(log_11) { ck_assert_ldouble_eq_tol(s21_log(1), log(1), 1e-06); }
END_TEST

START_TEST(log_12) { ck_assert_ldouble_eq_tol(s21_log(100), log(100), 1e-06); }
END_TEST

START_TEST(log_13) { ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), 1e-06); }
END_TEST

START_TEST(log_14) { ck_assert_ldouble_eq_tol(s21_log(0.5), log(0.5), 1e-06); }
END_TEST

START_TEST(log_15) {
    ck_assert_ldouble_eq_tol(s21_log(DBL_MAX), log(DBL_MAX), 1e-06);
}
END_TEST

START_TEST(log_16) {
    ck_assert_ldouble_eq_tol(s21_log(S21_PI / 3), log(S21_PI / 3), 1e-06);
}
END_TEST

START_TEST(log_17) {
    ck_assert_ldouble_eq_tol(s21_log(9.234578353457e-6), log(9.234578353457e-6),
                             1e-06);
}
END_TEST

START_TEST(log_18) {
    ck_assert_ldouble_eq_tol(s21_log(9.234578353457e6), log(9.234578353457e6),
                             1e-06);
}
END_TEST

START_TEST(log_19) {
    ck_assert_ldouble_eq_tol(s21_log(1234567.000000004), log(1234567.000000004),
                             1e-06);
}
END_TEST

START_TEST(log_20) {
    ck_assert_ldouble_eq_tol(s21_log(1.1e-16), log(1.1e-16), 1e-06);
}
END_TEST

START_TEST(log_24) {
    ck_assert_ldouble_eq_tol(s21_log(1.1e-45), log(1.1e-45), 1e-06);
}
END_TEST

START_TEST(log_25) {
    ck_assert_ldouble_eq_tol(s21_log(1.1e-18), log(1.1e-18), 1e-06);
}
END_TEST

START_TEST(log_26) {
    ck_assert_ldouble_eq_tol(s21_log(1.1e-19), log(1.1e-19), 1e-06);
}
END_TEST

START_TEST(log_27) {
    ck_assert_ldouble_eq_tol(s21_log(1.1e-23), log(1.1e-23), 1e-06);
}
END_TEST

START_TEST(log_21) {
    ck_assert_ldouble_eq_tol(s21_log(987654321123.123e-30),
                             log(987654321123.123e-30), 1e-06);
}
END_TEST

START_TEST(log_22) {
    ck_assert_ldouble_eq_tol(s21_log(98765.123e-11), log(98765.123e-11), 1e-06);
}
END_TEST

START_TEST(log_23) { ck_assert_ldouble_infinite(s21_log(0)); }
END_TEST

START_TEST(log_28) {
    ck_assert_ldouble_eq_tol(s21_log(1.1e-17), log(1.1e-17), 1e-06);
}
END_TEST

START_TEST(log_29) {
    ck_assert_ldouble_eq_tol(s21_log(1.1e-15), log(1.1e-15), 1e-06);
}
END_TEST

START_TEST(log_30) {
    ck_assert_ldouble_eq_tol(s21_log(1.1e-14), log(1.1e-14), 1e-06);
}
END_TEST

START_TEST(log_31) {
    ck_assert_ldouble_eq_tol(s21_log(1.1e-13), log(1.1e-13), 1e-06);
}
END_TEST

START_TEST(log_32) {
    ck_assert_ldouble_eq_tol(s21_log(1.1e-12), log(1.1e-12), 1e-06);
}
END_TEST

START_TEST(log_33) {
    ck_assert_ldouble_eq_tol(s21_log(1.1e-11), log(1.1e-11), 1e-06);
}
END_TEST

START_TEST(log_34) {
    ck_assert_ldouble_eq_tol(s21_log(1.1e-80), log(1.1e-80), 1e-06);
}
END_TEST

START_TEST(fmod_1) {
    ck_assert_double_eq(fmod(-1, 1), s21_fmod(-1, 1));
    ck_assert_double_eq(fmod(INT_MIN, 1), s21_fmod(INT_MIN, 1));
    ck_assert_double_eq(fmod(-INT_MAX, 1), s21_fmod(-INT_MAX, 1));
    ck_assert_double_eq(fmod(20000, 92), s21_fmod(20000, 92));
    ck_assert_double_eq(fmod(82.72, 42.28), s21_fmod(82.72, 42.28));
    ck_assert_double_eq_tol(fmod(2, 0.5), s21_fmod(2, 0.5), 1e-06);
    ck_assert_ldouble_eq(fmod(0.9, 20), s21_fmod(0.9, 20));
    ck_assert_double_eq(fmod(0.9, -20), s21_fmod(0.9, -20));
    ck_assert_double_eq(fmod(100, 100), s21_fmod(100, 100));
    ck_assert_double_nan(s21_fmod(100, 0));
    ck_assert_double_eq(fmod(0, 100), s21_fmod(0, 100));
    ck_assert_double_eq(fmod(100, 1), s21_fmod(100, 1));
    ck_assert_double_eq(fmod(1, 100), s21_fmod(1, 100));
    ck_assert_double_eq(fmod(13, 501), s21_fmod(13, 501));
    ck_assert_double_eq(fmod(87.78, 13), s21_fmod(87.78, 13));
    ck_assert_double_eq(fmod(0.02, 0.4), s21_fmod(0.02, 0.4));
    ck_assert_ldouble_eq(s21_fmod(2.34, 2.0), fmod(2.34, 2.0));
    ck_assert_ldouble_eq(s21_fmod(-2.34, 2.0), fmod(-2.34, 2.0));
    ck_assert_ldouble_eq(s21_fmod(2.34, -2.0), fmod(2.34, -2.0));
    ck_assert_ldouble_eq(s21_fmod(-2.34, -2.0), fmod(-2.34, -2.0));
    ck_assert_ldouble_eq(s21_fmod(21.21, 3), fmod(21.21, 3));
    ck_assert_ldouble_eq(s21_fmod(3, 21.21), fmod(3, 21.21));
    ck_assert_ldouble_eq(s21_fmod(-21.21, 3), fmod(-21.21, 3));
    ck_assert_ldouble_eq(s21_fmod(3, -21.21), fmod(3, -21.21));
    ck_assert_ldouble_eq(s21_fmod(100500, 9), fmod(100500, 9));
    ck_assert_ldouble_eq(s21_fmod(-100500, -9), fmod(-100500, -9));
    ck_assert_ldouble_eq(s21_fmod(-9, -100500), fmod(-9, -100500));
    ck_assert_ldouble_eq(s21_fmod(-9, -9), fmod(-9, -9));
    ck_assert_ldouble_eq(s21_fmod(10, 5), fmod(10, 5));
    ck_assert_ldouble_nan(s21_fmod(INFINITY, INFINITY));
    ck_assert_ldouble_nan(fmod(INFINITY, INFINITY));
    ck_assert_ldouble_nan(s21_fmod(NAN, NAN));
    ck_assert_ldouble_nan(fmod(NAN, NAN));
    ck_assert_ldouble_nan(s21_fmod(2.45, 0));
    ck_assert_ldouble_nan(s21_fmod(0, 0));
    ck_assert_ldouble_nan(s21_fmod(INFINITY, 0));
    ck_assert_ldouble_eq(s21_fmod(2.0, INFINITY), fmod(2.0, INFINITY));
    ck_assert_ldouble_eq(s21_fmod(2.0, INFINITY), fmod(2.0, INFINITY));
    ck_assert_ldouble_eq(s21_fmod(2.0, -INFINITY), fmod(2.0, -INFINITY));
    ck_assert_ldouble_nan(s21_fmod(S21_INF, S21_INF));
    ck_assert_ldouble_nan(fmod(S21_INF, S21_INF));
    ck_assert_ldouble_eq(s21_fmod(0, 23), fmod(0, 23));
}
END_TEST

START_TEST(s21_fmod_test_25) {
    double num = -INFINITY;
    long double orig_res = fmod(num, 2.0), our_res = s21_fmod(num, 2.0);
    int suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_fmod_test_22) {
    double num = INFINITY;
    long double orig_res = fmod(num, 2.0), our_res = s21_fmod(num, 2.0);
    int suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_fmod_test_20) {
    double num = NAN;
    long double orig_res = fmod(2.0, num), our_res = s21_fmod(2.0, num);
    int suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(s21_fmod_test_19) {
    double num = NAN;
    long double orig_res = fmod(num, 2.0), our_res = s21_fmod(num, 2.0);
    int suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(three_and_point) {
    double k = 3, i = 0;
    while (k < 4) {
        k += 0.01;
        ck_assert_double_eq(ceil(i), s21_ceil(i));
    }
}
END_TEST

START_TEST(negative_three_and_point) {
    double k = -3, i = 0;
    while (k > -4) {
        k -= 0.01;
        ck_assert_double_eq(ceil(i), s21_ceil(i));
    }
}
END_TEST

START_TEST(s21_ceil_f) {
    ck_assert_double_eq(ceil(0), s21_ceil(0));
    ck_assert_double_eq(ceil(-0), s21_ceil(-0));
    ck_assert_double_eq(ceil(DBL_MIN), s21_ceil(DBL_MIN));
    ck_assert_ldouble_eq(ceil(DBL_MAX), s21_ceil(DBL_MAX));
    ck_assert_double_eq(ceil(-DBL_MAX + 1), s21_ceil(-DBL_MAX + 1));
    ck_assert_double_eq(ceil(S21_INF), s21_ceil(S21_INF));
    ck_assert_double_eq(ceil(-S21_INF), s21_ceil(-S21_INF));
    ck_assert_ldouble_eq(s21_ceil(-15.01), ceil(-15.01));
    ck_assert_ldouble_eq(s21_ceil(15.01), ceil(15.01));
    ck_assert_ldouble_eq(s21_ceil(INFINITY), ceil(INFINITY));
    ck_assert_ldouble_eq(s21_ceil(-INFINITY), ceil(-INFINITY));
    ck_assert_ldouble_eq(s21_ceil(-0.12), ceil(-0.12));
    ck_assert_ldouble_eq(s21_ceil(21.21), ceil(21.21));
    ck_assert_ldouble_eq(s21_ceil(21.91), ceil(21.91));
    ck_assert_ldouble_eq(s21_ceil(0), ceil(0));
    ck_assert_ldouble_eq(s21_ceil(0.0), ceil(0.0));
    ck_assert_ldouble_eq(s21_ceil(-21.21), ceil(-21.21));
    ck_assert_ldouble_eq(s21_ceil(-21.91), ceil(-21.91));
}
END_TEST

START_TEST(s21_floor_f) {
    ck_assert_double_eq(floor(0), s21_floor(0));
    ck_assert_double_eq(floor(-1.0), s21_floor(-1.0));
    ck_assert_double_eq(floor(DBL_MIN), s21_floor(DBL_MIN));
    ck_assert_ldouble_eq(floor(DBL_MAX), s21_floor(DBL_MAX));
    ck_assert_double_eq(floor(-DBL_MAX), s21_floor(-DBL_MAX));
    ck_assert_double_eq(floor(-DBL_MAX + 1), s21_floor(-DBL_MAX + 1));
    ck_assert_double_eq(floor(S21_INF), s21_floor(S21_INF));
    ck_assert_double_eq(floor(-S21_INF), s21_floor(-S21_INF));
    ck_assert_ldouble_eq(s21_floor(0.0), floor(0.0));
    ck_assert_ldouble_eq(s21_floor(21.21), floor(21.21));
    ck_assert_ldouble_eq(s21_floor(21.91), floor(21.91));
    ck_assert_ldouble_eq(s21_floor(-21.21), floor(-21.21));
    ck_assert_ldouble_eq(s21_floor(-21.91), floor(-21.91));
    ck_assert_ldouble_eq(s21_floor(0), floor(0));
    ck_assert_ldouble_eq(s21_floor(-15.01), floor(-15.01));
    ck_assert_ldouble_eq(s21_floor(15.01), floor(15.01));
    ck_assert_ldouble_eq(s21_floor(INFINITY), floor(INFINITY));
    ck_assert_ldouble_eq(s21_floor(-INFINITY), floor(-INFINITY));
    ck_assert_ldouble_eq(s21_floor(-0), floor(-0));
    ck_assert_ldouble_eq(s21_floor(-21.91), floor(-21.91));
    ck_assert_ldouble_eq(s21_floor(-21.91), floor(-21.91));
}
END_TEST

START_TEST(floor_14) {
    double num = NAN;
    long double orig_res = floor(num), our_res = s21_floor(num);
    int suc = 0;
    if (isnan(orig_res) && isnan(our_res)) suc = 1;
    ck_assert_int_eq(1, suc);
}
END_TEST

START_TEST(three_and_point2) {
    double k = 3, i = 0;
    while (k < 4) {
        k += 0.01;
        ck_assert_double_eq(floor(i), s21_floor(i));
    }
}
END_TEST

START_TEST(negative_three_and_point2) {
    double k = -3, i = 0;
    while (k > -4) {
        k -= 0.01;
        ck_assert_double_eq(floor(i), s21_floor(i));
    }
}
END_TEST

int main(void) {
  Suite *suite = suite_create("Math_lib");
  TCase *getCase = tcase_create("Core");
  SRunner *runner = srunner_create(suite);
  int nf;

  puts("\e[32m");
  suite_add_tcase(suite, getCase);
  tcase_add_test(getCase, abs_test);
  tcase_add_test(getCase, fabs_test);
  tcase_add_test(getCase, sin_test);
  tcase_add_test(getCase, cos_test);
  tcase_add_test(getCase, tan_test);
  tcase_add_test(getCase, tan_2);
  tcase_add_test(getCase, tan_3);
  tcase_add_test(getCase, tan_4);
  tcase_add_test(getCase, tan_5);
  tcase_add_test(getCase, tan_6);
  tcase_add_test(getCase, tan_7);
  tcase_add_test(getCase, tan_8);
  tcase_add_test(getCase, tan_9);
  tcase_add_test(getCase, tan_10);
  tcase_add_test(getCase, tan_11);
  tcase_add_test(getCase, tan_12);
  tcase_add_test(getCase, tan_13);
  tcase_add_test(getCase, tan_14);
  tcase_add_test(getCase, tan_15);
  tcase_add_test(getCase, tan_16);
  tcase_add_test(getCase, tan_17);
  tcase_add_test(getCase, tan_18);
  tcase_add_test(getCase, tan_19);
  tcase_add_test(getCase, tan_20);
  tcase_add_test(getCase, tan_21);
  tcase_add_test(getCase, atan_test);
  tcase_add_test(getCase, asin_test);
  tcase_add_test(getCase, acos_test);
  tcase_add_test(getCase, cos_1);
  tcase_add_test(getCase, cos_2);
  tcase_add_test(getCase, cos_3);
  tcase_add_test(getCase, cos_4);
  tcase_add_test(getCase, cos_5);
  tcase_add_test(getCase, cos_6);
  tcase_add_test(getCase, cos_7);
  tcase_add_test(getCase, cos_8);
  tcase_add_test(getCase, cos_9);
  tcase_add_test(getCase, cos_10);
  tcase_add_test(getCase, cos_11);
  tcase_add_test(getCase, cos_12);
  tcase_add_test(getCase, cos_13);
  tcase_add_test(getCase, cos_14);
  tcase_add_test(getCase, cos_15);
  tcase_add_test(getCase, cos_16);
  tcase_add_test(getCase, cos_17);
  tcase_add_test(getCase, cos_18);
  tcase_add_test(getCase, cos_19);
  tcase_add_test(getCase, cos_20);
  tcase_add_test(getCase, cos_21);

  tcase_add_test(getCase, pow_test);
  tcase_add_test(getCase, sqrt_test);
  tcase_add_test(getCase, exp_test);

  tcase_add_test(getCase, zero);
  tcase_add_test(getCase, one);
  tcase_add_test(getCase, fifty);
  tcase_add_test(getCase, negative_fifty);
  tcase_add_test(getCase, negative);
  tcase_add_test(getCase, thirteen);
  tcase_add_test(getCase, not_a_num);
  tcase_add_test(getCase, infinity);
  tcase_add_test(getCase, negative_infinity);

  tcase_add_test(getCase, log_1);
  tcase_add_test(getCase, log_2);
  tcase_add_test(getCase, log_3);
  tcase_add_test(getCase, log_4);
  tcase_add_test(getCase, log_5);
  tcase_add_test(getCase, log_6);
  tcase_add_test(getCase, log_7);
  tcase_add_test(getCase, log_8);
  tcase_add_test(getCase, log_9);
  tcase_add_test(getCase, log_10);
  tcase_add_test(getCase, log_11);
  tcase_add_test(getCase, log_12);
  tcase_add_test(getCase, log_13);
  tcase_add_test(getCase, log_14);
  tcase_add_test(getCase, log_15);
  tcase_add_test(getCase, log_16);
  tcase_add_test(getCase, log_17);
  tcase_add_test(getCase, log_18);
  tcase_add_test(getCase, log_19);
  tcase_add_test(getCase, log_20);
  tcase_add_test(getCase, log_21);
  tcase_add_test(getCase, log_22);
  tcase_add_test(getCase, log_23);
  tcase_add_test(getCase, log_24);
  tcase_add_test(getCase, log_25);
  tcase_add_test(getCase, log_26);
  tcase_add_test(getCase, log_27);
  tcase_add_test(getCase, log_28);
  tcase_add_test(getCase, log_29);
  tcase_add_test(getCase, log_30);
  tcase_add_test(getCase, log_31);
  tcase_add_test(getCase, log_32);
  tcase_add_test(getCase, log_33);
  tcase_add_test(getCase, log_34);

  tcase_add_test(getCase, fmod_1);
  tcase_add_test(getCase, s21_fmod_test_19);
  tcase_add_test(getCase, s21_fmod_test_20);
  tcase_add_test(getCase, s21_fmod_test_22);
  tcase_add_test(getCase, s21_fmod_test_25);
  tcase_add_test(getCase, three_and_point);
  tcase_add_test(getCase, negative_three_and_point);

  tcase_add_test(getCase, s21_ceil_f);
  tcase_add_test(getCase, s21_floor_f);
  tcase_add_test(getCase, floor_14);
  tcase_add_test(getCase, three_and_point2);
  tcase_add_test(getCase, negative_three_and_point2);

  srunner_run_all(runner, CK_ENV);
  nf = srunner_ntests_failed(runner);
  srunner_free(runner);
  return nf == 0 ? 0 : 1;
}
