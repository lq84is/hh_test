#include "misc.h"

#include <stdint.h>

int countBits(uint32_t number) {
    number = number - ((number >> 1) & 0x55555555);
    number = (number & 0x33333333) + ((number >> 2) & 0x33333333);
    number = (number + (number >> 4)) & 0x0F0F0F0F;
    number = number + (number >> 8);
    number = number + (number >> 16);
    return number & 0x3F;
}

int32_t aabs(int32_t x)
{
  return  (x ^ (x >> 31)) - (x >> 31);
}

int32_t range(int32_t min, int32_t max, int32_t val){
  if(val < min){	
		return min;}
	else{
		if(val > max){
			return max;}
		else{	
			return val;}
	}  
}

float f_range(float min, float max, float val){
  if(val < min){	
		return min;}
	else{
		if(val > max){
			return max;}
		else{	
			return val;}
	}  
}

float not_f_range(float min, float max, float val){
  if(val < min){	
		return val - min;}
	else{
		if(val > max){
			return val - max;}
		else{	
			return 0;}
	}  
}

unsigned char is_float_negative(float *var)
{
  if(*(uint32_t*)var & 0x80000000)
    return 1;
  else
    return 0;
}
float conversion(float value_a, float min_unit_a, float min2max_unit_a,\
                          float min_unit_b, float min2max_unit_b)
{
  return (((value_a - min_unit_a) * min2max_unit_b) / min2max_unit_a) + min_unit_b;
}
