/*
 * AC_test.c
 *
 * Created: 2/27/2026 11:01:19 PM
 * Author : hamza
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

/* HAL */
#include "AC_interface.h"

int main(void)
{
	AC_voidInit();

	while(1)
	{
		AC_voidUpdate(); 
	}
}