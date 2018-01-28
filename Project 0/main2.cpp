#include <iostream>
#include "p0.h"
// example program: main2.cc
int main ()
{
	READWRITE c;  // instantiate an object c which is of class READWRITE

	c.READ();     // read the grades from in.0
	c.REVERSE_PRINT();	// print the grades into out.0
				// in reverse order
	return 0;
}
