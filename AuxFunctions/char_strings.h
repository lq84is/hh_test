#ifndef CHAR_STRINGS_H
#define CHAR_STRINGS_H

#include "AuxFunctions/PrintDebug.h"

#define EN (0)
#define RU (1)

extern translations_t OnOff_str;
typedef enum{
	off = 0,
	on
}OnOff_e;



//extern langs_e default_language;
extern translations_t formatHex;

extern const char* SEPARATOR;

#endif
