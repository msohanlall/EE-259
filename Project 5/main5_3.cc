//Example of program : main3.cc
#include <iostream>
#include "p5.h"
int main ()
{
	MATRIX X(2,2, "in.51"), Y(2,2, "in.52");

	X.PRINT();
	
	X *= Y;
	
	Y.PRINT();
	X.PRINT();
	
	return 0;
}
