//Example of program : main1.cc
#include <iostream>
#include "p5.h"
int main ()
{
	MATRIX X(2,2, "in.51"), Y(2,2, "in.52"), Z(2,2, "in.52");

	if (X < 2)
	{}
	else
	{
		Y.PRINT(); // shouldn't print;
	}

	Z = X + Y;

	if (Z < 5)
	{
		Y.PRINT(); // print;
	}
	else
	{}

	Z.PRINT(); // print;
	
	return 0;
}
