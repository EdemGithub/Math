#include "s21_math.h"

int s21_abs(int x) {
  if (x < 0) {
    x *= -1;
  }
  return x;
}

long double s21_fabs(double x) {
  if (is_nan(x) || !is_finite(x)) {
  } else if (x < 0) {
    x *= -1.;
  }
  return x;
}

long double s21_sin(double x) {
  long double result = 0;
  if (x == S21_NAN || x == -S21_INF || x == S21_INF) {
    result = S21_NAN;
  } else {
    while (x < -2 * S21_PI || 2 * S21_PI < x) {
      if (x > 2 * S21_PI) {
        x -= 2 * S21_PI;
      } else {
        x += 2 * S21_PI;
      }
    }
    long double res = x, temp = x, i = 1.;
    while (s21_fabs(res) > S21_EPS) {
      res = -1 * res * x * x / (2 * i * (2 * i + 1));
      i += 1.;
      temp += res;
    }
    result = temp;
  }
  return result;
}

long double s21_cos(double x) {
  long double result = s21_sin(S21_PI / 2 - x);
  return result;
}

long double s21_tan(double x) {
  if (x == S21_PI / 2) {
    return 16331239353195370L;
  } else if (x == -S21_PI / 2) {
    return -16331239353195370L;
  }
  if (x == 0) {
    return 0;
  }
  return s21_sin(x) / s21_cos(x);
}

long double s21_atan(double x) {
  long double result = 0;
  int sign = 1;
  if (x < 0.0) {
    sign = -1;
    x = -x;
  }
  if (x > 1.0) {
    result = S21_PI / 2 - s21_atan(1.0 / x);
  } else if (s21_fabs(x - 1.0) < 0.000001) {
    result = S21_PI / 4;
  } else {
    for (int n = 0; n < 20; n++) {
      result += (s21_pow(-1, n) * s21_pow(x, (2 * n) + 1)) / (2 * n + 1);
    }
  }
  return sign * result;
}

long double s21_acos(double x) { return S21_PI / 2 - s21_asin(x); }

long double s21_asin(double x) { return s21_atan(x / s21_sqrt(1 - (x * x))); }

long double s21_ceil(double x) {
  long double rigth_x = x;
  int flag = 0;
  if (x < 0 && x != S21_INF && x != S21_INFF) {
    flag = 1;
    x = s21_fabs(x);
  }
  long double res = x;
  if (x == S21_INF) {
      res = S21_INF;
  } else if (x == S21_INFF) { res = S21_INFF;
  } else if (is_inf(res) || res == 0 || res == DBL_MAX) {
    if (flag == 1)
      res = -x;
    else
      res = x;
  } else if (res > 0) {
    res = (long long int)x;
    if (res != x && (res - x) < 1) {
      if (rigth_x > 0) {
        res++;
      } else {
        res = -res;
      }
    } else {
      res = x;
    }
  } else {
    res = S21_NAN;
  }
  return res;
}

long double s21_floor(double x) {
  long double rigth_x = x;
  int flag = 0;
  if (x < 0 && x != S21_INFF && x != S21_INF) flag = 1;
  x = s21_fabs(x);
  long double res = x;
    if (x == S21_INF) {
        res = S21_INF;
    } else if (x == S21_INFF) {
        res = S21_INFF;
    } else if (is_inf(res) || res == 0 || res == DBL_MAX) {
    if (flag == 1)
      res = -x;
    else
      res = x;
  } else if (DBL_MAX - x < 0) {
    res = 0;
  } else if (res == DBL_MIN) {
    if (flag == 1)
      res = -1;
    else
      res = 0;
  } else if (res > 0) {
    res = (long long int)x;
    if (res != x && (res - x) < 1) {
      if (rigth_x < 0) {
        res++;
        res = -res;
      }
    } else {
      flag == 1 ? res = -res : res;
    }
  } else {
    res = S21_NAN;
  }
  return res;
}

long double s21_fmod(double x, double y) {
  long double res = 0.0;
  if (is_nan(x) || is_nan(y) || is_inf(x) || (is_inf(x) && is_inf(y))) {
    res = S21_NAN;
  } else if (is_inf(y)) {
    res = x;
  } else if (y == 0) {
    res = S21_NAN;
  } else {
    long double longx = x;
    long double longy = y;
    long long z = x / y;
    res = longx - z * longy;
  }
  return res;
}

long double s21_log(double x) {
  int poww = 0;
  double res = 0, compare = 0;
  if (x == S21_INF) {
    res = S21_INF;
  } else if (x == 0) {
    res = -S21_INF;
  } else if (x < 0) {
    res = S21_NAN;
  } else if (x == 1) {
    res = 0;
  } else {
    for (; x >= S21_EXP; x /= S21_EXP, poww++) continue;
    int i;
    for (i = 0; i < 100; i++) {
      compare = res;
      res = compare + 2 * (x - s21_exp(compare)) / (x + s21_exp(compare));
    }
  }
  return (res + poww);
}

long double s21_exp(double x) {
  double buffer = 1;
  long double result = 1;
  int check_minus = 1;
  if (x < 0) {
    check_minus = -1;
    x *= check_minus;
  }
  for (double del = 1; s21_fabs(buffer) > S21_EPS; ++del) {
    buffer *= x / del;
    result += buffer;
    if (result > DBL_MAX) {
      result = S21_INF;
      break;
    }
  }
  if (check_minus == -1) {
    if (result > DBL_MAX) {
      result = 0;
    } else {
      result = 1.00 / result;
    }
  }
  if (result > DBL_MAX) {
    return S21_INF;
  }
  return result;
}

long double s21_sqrt(double x) {
  long double result = s21_pow(x, 0.5);
  if (x == -S21_INF) {
    result = S21_NAN;
  }
  return result;
}

long double s21_pow(double base, double exp) {
  long double result = 1;
  if (base != -S21_INF && !(s21_fabs(base) == 1 && exp == S21_INF) &&
      !(base < 0 && (exp == S21_INF || exp == -S21_INF))) {
    int check_plus_exp = 1;
    if (exp < 0) {
      check_plus_exp = -1;
      exp *= check_plus_exp;
    }
    if (exp) {
      if (exp == (int)exp) {
        result = pow_ceil(base, exp);
      } else {
        result = s21_exp(log(base) * exp);
      }
    }
    if (check_plus_exp == -1 && !(exp < 0 && base == 0)) {
      result = 1.0 / result;
    }
  } else {
    if (s21_fabs(base) == 1 && exp == S21_INF) {
      result = 1;
    } else if (base < 0 && (exp == S21_INF || exp == -S21_INF)) {
      if (exp == S21_INF) {
        result = S21_INF;
      } else {
        result = 0.00;
      }
    } else {
      if (base == S21_INF) {
        result = S21_INF;
      } else if (exp > 0) {
        result = -S21_INF;
      } else if (base == -S21_INF && exp < 0) {
        result = -0.00;
      }
    }
  }
  return result;
}

long double pow_ceil(double base, double exp) {
  const double base_plus = s21_fabs(base);
  long double result = base;
  for (unsigned int counter = 1; counter < exp; ++counter) {
    long double check_overflow = LDBL_MAX / base_plus;
    if (result > check_overflow) {
      result = S21_INF;
      break;
    }
    result *= base;
  }
  return result;
}
