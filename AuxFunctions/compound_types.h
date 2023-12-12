#ifndef COMPOUND_TYPES_H
#define COMPOUND_TYPES_H
#include <stdint.h>

#define SIZEOF_PACK32TYPE(type)  ((sizeof(type) & (~0x3)) + (!!((sizeof(type)&0x3)) << 2))

#define FUNCTIONS(operation) operation##_FUNCTION(ch) ;\
                             operation##_FUNCTION(i8) ;\
                             operation##_FUNCTION(u8) ;\
                             operation##_FUNCTION(i16);\
                             operation##_FUNCTION(u16);\
                             operation##_FUNCTION(i32);\
                             operation##_FUNCTION(u32);\
                             operation##_FUNCTION(f)  ;

#define FARRAY(operation)     operation##_NAME(ch) ,\
                              operation##_NAME(i8) ,\
                              operation##_NAME(u8) ,\
                              operation##_NAME(i16),\
                              operation##_NAME(u16),\
                              operation##_NAME(i32),\
                              operation##_NAME(u32),\
                              operation##_NAME(f)  ,




typedef enum{
    void_e = 0,
    char_e,
    int8_t_e,
    uint8_t_e,
    int16_t_e,
    uint16_t_e,
    int32_t_e,
    uint32_t_e,
    float_e,
    str_e,
}type_tip;

typedef union{
    char      ch ;
    int8_t    i8 ;
    uint8_t   u8 ;
    int16_t   i16;
    uint16_t  u16;
    int32_t   i32;
    uint32_t  u32;
    float     f  ;
    char* str;
}val_t;

typedef union{
    void* v;
    char* ch;
    int8_t* i8;
    uint8_t* u8;
    int16_t* i16;
    uint16_t* u16;
    int32_t* i32;
    uint32_t* u32;
    float*  f;
    char* str;
}val_p;

typedef struct{
    val_p pointer;
    val_t value;
    type_tip type;
}val_connected_t ;

void p_equals_p(type_tip type, val_p* to, val_p* from);
void v_equals_v(type_tip type, val_t* to, val_t* from);
void p_equals_v(type_tip type, val_p* to, val_t* from);
void v_equals_p(type_tip type, val_t* to, val_p* from);

#endif
