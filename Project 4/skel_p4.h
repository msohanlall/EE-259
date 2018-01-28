#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>

using namespace std;


// declare the output file
  ofstream output_file("out.4",ios::out);




 class BOOK_OVER{

   public:      // public interfaces for this class

        BOOK_OVER(char *);       // example: b.BOOK_OVER("file.A");
                                // constructor where the book data is
                                // given in file called file.A;

        void GIVE_SIZE(void); // example: b.GIVE_SIZE();
                                // interface to print the number of
                                // book in b's database;
                                // returns no values;

        int operator == (BOOK_OVER &);  // example: if (b1 == b2)
                                // overloaded operator ==
                                // returns 1 if b1 and b2 have exactly
                                // the same ISBN numbers in the same order;
                                // returns 0 otherwise;

        void operator -= (char *); // example: b1 -= "SHIKSPEAR";
                                // take the book(s) whose author is 
                                // "SHIKSPEAR" out of b1 database;
                                // returns no values;

        void operator += (BOOK_OVER &); //example: b1 += b2;
                                // append the books in b2 into b1;
                                // there may be duplications;
                                // returns no values;

   private: // private variables accessible by the interfaces only
            // (not from main)

        int n;  // no of books
        int ISBN[100]; // max 100 ISBN numbers
        char TITLE[100][80]; // max 100 books, each title with max 80 chars
                             // (there are no spaces in each title)
        char AUTHOR[100][20];   // max 100 books, each author name with 
                                // max 20 chars 
                                // (there are no spaces in each author name)
        char PUBLISHER[100][15]; // max 100 books, each publisher name with
                                // max 15 chars
                                // (there are no spaces in each publ. name)
        int YEAR[100]; // max 100 publishing years
        float PRICE[100]; // max 100 book prices, max $1000.
   };



BOOK_OVER:: BOOK_OVER(char *file_name)
{
	// declare the input file
       // ifstream input_file(file_name, ios::in);


}
	
	 
void BOOK_OVER::GIVE_SIZE(void)
{

}
			       


int BOOK_OVER::operator == (BOOK_OVER &x)
{
	return 0;

}



void BOOK_OVER::operator -= (char *author)
{

}


void BOOK_OVER::operator += (BOOK_OVER &x)
{

}
