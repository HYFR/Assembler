#include <assert.h>
#include <stdio.h>

#include "function.h"

int main()
{
	assert(translate("NOP") == 0);
	assert(translate("LDD") == 1);
	assert(translate("LDI") == 2);
	assert(translate("STO") == 3);
	return 0;
}