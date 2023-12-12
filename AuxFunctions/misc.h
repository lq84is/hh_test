#ifndef MISC_H
#define MISC_H
#include <stdint.h>

int countBits(uint32_t number);
int32_t aabs(int32_t x);
int32_t range(int32_t min, int32_t max, int32_t val);
float f_range(float min, float max, float val);
float not_f_range(float min, float max, float val);
unsigned char is_float_negative(float *var);
float conversion(float value_a, float min_unit_a, float min2max_unit_a,\
                          float min_unit_b, float min2max_unit_b);
#define ABS_INT(x)           (((x) ^ ((x) >> 31)) - ((x) >> 31))
#define SIGN_ZERO_INT(x)     (((x) >> 31)|(!!(x))) 
#define MAX(a,b)             ((a) > (b) ? (a) : (b))
#define MIN(a,b)             ((a) < (b) ? (a) : (b))

#endif
