/////////////////////////////////////////////////////////////
//////// I UNDERSTAND THAT COPYING PROGRAMS FROM OTHERS WILL BE DEALT
//////// WITH DISCIPLINARY RULES OF CCNY.
//////// NAME:        Michael Sohanlall
//////// LOGIN:       ee259e08
//////// PROJECT NUMBER: p1
///////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

// declare the input file 
  ifstream input_file("in.1",ios::in);
// declare the output file 
  ofstream output_file("out.1",ios::out);

class BOOK_SEARCH{

   public:      // public interfaces for this class

        BOOK_SEARCH(int);       // example: b.BOOK_SEARCH(x);
                                // constructor where integer x is the
                                // num of books in the database;

        void FIND_ISBN(int);    // example: b.FIND_ISBN(i);
                                // interface to find the book with
                                // given ISBN of i;
                                // returns no values;

        void LIST_YEAR(int);    // example: b.LIST_YEAR(y);
                                // interface to list the books
                                // published in year y, or after;
                                // returns no values;

        void LIST_BOOKS(int,float);    // example: b.LIST_BOOKS(y, p);
                                // interface to list the books that are
                                // published in year y or after with the
                                // price less than or equal to p;
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
                                // max 10 chars
                                // (there are no spaces in each publ. name)
        int YEAR[100];   // max 100 publication years
        float PRICE[100]; // max 100 book prices
   };

BOOK_SEARCH::BOOK_SEARCH (int x)
{
	n=x;
	int i;
	for(i=0; i<n; i++)
	{
		input_file>>ISBN[i]>>TITLE[i]>>AUTHOR[i]>>PUBLISHER[i]>>YEAR[i]>>PRICE[i];
	}
}

void BOOK_SEARCH::FIND_ISBN (int x)
{
	int i;
	int found;
	int position;
	if (x<0 )
	{
		output_file << "INPUT ERROR. IGNORED THE INTERFACE CALL." << endl; 
	}
	else 
	{
	found=0;
	for (i=0; i<n && found==0; i++)
	{
			if(ISBN[i]==x) 
		{
			found=1;
			position=i;
		}
	}
		if(found==1)
		{
			output_file << "FOUND THE BOOK WITH ISBN "<< x << ":"<<endl;
			output_file << "TITLE: " << TITLE[position] << endl;
			output_file << "AUTHOR: " << AUTHOR[position] << endl;
			output_file << "PUBLISHER: " << PUBLISHER[position] << endl;
			output_file << "YEAR: " << YEAR[position] << endl;
			output_file << "PRICE: " << PRICE[position] << " USD"<< endl;
		}
		else 
		{
			output_file << "NO BOOK WITH ISBN "<< x <<" HAS BEEN FOUND."<< endl;
		}
	}
}
void BOOK_SEARCH::LIST_YEAR (int x)
{
	int i;
	int found=0;
	int position[100];
	for (i=0; i<n; i++)
	{
		if(YEAR[i]>=x)
		{
			position[found]=i;
			found++;  
		}
	}
	if ( x<0 )
	{
		output_file << "INPUT ERROR. IGNORED THE INTERFACE CALL." << endl;   
	}
	else if (found>=1)
	{
		output_file<<"THE BOOKS PUBLISHED IN YEAR "<< x <<" OR LATER:"<<endl;
		for (i=0; i<found; i++)
		{

			output_file << "TITLE: " << TITLE[position[i]]<< endl; 
			output_file << "YEAR: " << YEAR[position[i]]<< endl;  
			
		}
	}
	else 
	{
		output_file << "NO BOOKS PUBLISHED IN YEAR " << x << " OR LATER HAS BEEN FOUND." <<endl;
	}
}

void BOOK_SEARCH::LIST_BOOKS (int x, float y)
{
	int i;
	int position[100];
	int found=0;
	for(i=0; i<n; i++)
	{
		if(YEAR[i]>=x && PRICE[i]<=y)
		{
			position[found]=i;
			found++;	
		}
	}
	if (y<0 && x< 0)
	{
		output_file << "INPUT ERROR. IGNORED THE INTERFACE CALL." << endl; 
	}
	else if (found>=1)
	{
		for(i=0; i<found; i++)
		{
		output_file << "THE BOOKS PUBLISHED IN YEAR " << x << " OR LATER PRICED " << fixed << setprecision(2)<< y <<" USD OR CHEAPER:" << endl;
		output_file << "TITLE: " << TITLE[position[i]]<< endl; 
		output_file << "YEAR: " << YEAR[position[i]]<< endl;  
		output_file << "PRICE: " << PRICE[position[i]]<< " USD" << endl;  
		}
	}
	else
	{
		output_file << "NO BOOKS HAS BEEN FOUND WITH YEAR >= "<<  x << " AND PRICE <= "<< y << " USD."<<endl;
	}
}
