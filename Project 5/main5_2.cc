//Example of program : main2.cc
#include <iostream>
#include "p5.h"
int main ()
{
	MATRIX X(2,2,"in.51"), Y(2,2, "in.52"), Z(2,2);

	Z = X*Y;
	Z.PRINT();
	
	Z = X+Y;
//	X+Y;
	Z.PRINT();
	
	return 0;
}
