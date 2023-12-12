#include "AuxFunctions/compound_types.h"


#define P_EQUALS_P_NAME(type)         p_p_##type##_equals
#define P_EQUALS_P_DECLARATION(type) void P_EQUALS_P_NAME(type)(val_p* to, val_p* from)
#define P_EQUALS_P_BODY(type)        {*(to->type) = *(from->type);}
#define P_EQUALS_P_FUNCTION(type)    P_EQUALS_P_DECLARATION(type)P_EQUALS_P_BODY(type)
FUNCTIONS(P_EQUALS_P)
void (*p_equals_p_fcns[])(val_p*, val_p*) = {
    FARRAY(P_EQUALS_P)
};
void p_equals_p(type_tip type, val_p* to, val_p* from) {
    if (type)
        p_equals_p_fcns[(uint8_t)(type - 1)](to, from);
}

#define V_EQUALS_V_NAME(type)         v_v_##type##_equals
#define V_EQUALS_V_DECLARATION(type) void V_EQUALS_V_NAME(type)(val_t* to, val_t* from)
#define V_EQUALS_V_BODY(type)        {to->type = from->type;}
#define V_EQUALS_V_FUNCTION(type)    V_EQUALS_V_DECLARATION(type)V_EQUALS_V_BODY(type)
FUNCTIONS(V_EQUALS_V)
void (*v_equals_v_fcns[])(val_t*, val_t*) = {
    FARRAY(V_EQUALS_V)
};
void v_equals_v(type_tip type, val_t* to, val_t* from) {
    if (type)
        v_equals_v_fcns[(uint8_t)(type - 1)](to, from);
}

#define P_EQUALS_V_NAME(type)        p_v_##type##_equals
#define P_EQUALS_V_DECLARATION(type) void P_EQUALS_V_NAME(type)(     val_p* to, val_t* from)
#define P_EQUALS_V_BODY(type)        {*(to->type) = from->type;}
#define P_EQUALS_V_FUNCTION(type)    P_EQUALS_V_DECLARATION(type)P_EQUALS_V_BODY(type)
FUNCTIONS(P_EQUALS_V)
void (*p_equals_v_fcns[])(val_p*, val_t*) = {
    FARRAY(P_EQUALS_V)
};
void p_equals_v(type_tip type, val_p* to, val_t* from) {
    if (type)
        p_equals_v_fcns[(uint8_t)(type - 1)](to, from);
}

#define V_EQUALS_P_NAME(type)        v_p_##type##_equals
#define V_EQUALS_P_DECLARATION(type) void V_EQUALS_P_NAME(type)(val_t* to, val_p* from)
#define V_EQUALS_P_BODY(type)        {to->type = *(from->type);}
#define V_EQUALS_P_FUNCTION(type)    V_EQUALS_P_DECLARATION(type)V_EQUALS_P_BODY(type)
FUNCTIONS(V_EQUALS_P)
void (*v_equals_p_fcns[])(val_t*, val_p*) = {
    FARRAY(V_EQUALS_P)
};
void v_equals_p(type_tip type, val_t* to, val_p* from) {
    if (type)
        v_equals_p_fcns[(uint8_t)(type - 1)](to, from);
}
