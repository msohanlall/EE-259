//Example of program : main4.cc
#include <iostream>
#include "p5.h"
int main ()
{
	MATRIX X(2,2, "in.51"), Y(2,2, "in.52"), Z(2,2);

	Z.PRINT();
	
	Z = X/ Y;
	Z.PRINT();
	
	Z = 3/Y;
	Z.PRINT();

	Z = 3 * Y;
	Z.PRINT();
	
	return 0;
}
