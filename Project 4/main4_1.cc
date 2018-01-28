#include <iostream>
#include "p4.h"
// example program: main1.cc
int main ()
{
	BOOK_OVER b1("in.41"),b2("in.42");  // instantiate object b1 and b2;
					// the books are in in.41 and in.42;
	if (b1 == b2)
	{
		b1.GIVE_SIZE();
		b2.GIVE_SIZE();
	}
	else {}
	return 0;
}
