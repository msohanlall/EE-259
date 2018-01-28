//////////////////////////////////////////////////////////////
///////// I UNDERSTAND THAT COPYING PROGRAMS FROM OTHERS WILL BE DEALT
///////// WITH DISCIPLINARY RULES OF CCNY.
///////// NAME:        Michael Sohanlall
///////// LOGIN:       ee259e08
///////// PROJECT NUMBER: p2
/////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <iomanip>

using namespace std;

// declare the input file
  ifstream input_file("in.2",ios::in);
// declare the output file
  ofstream output_file("out.2",ios::out);
 
 
  class BOOK_SORT{

   public:      // public interfaces for this class

        BOOK_SORT(int);       // example: b.BOOK_SORT(x);
				// constructor where integer x is the
				// num of books in the database;

        void SORT_ISBN(void);    // example: b.SORT_ISBN();
				// interface to sort the books by their 
				// ISBN number from the smallest to the
				// largest (i.e., ascending order);
				// assume that each ISBN is unique;
                                // returns no values;

        void SORT_TITLE(void);    // example: b.SORT_TITLE();
				// interface to alphabetically sort the 
				// books by their title; 
				// assume that each title is unique;
                                // returns no values;

        void SORT_PRICE(void);    // example: b.SORT_PRICE();
				// interface to sort the books by their price
				// in descending order;
				// assume that each price is unique;
                                // returns no values;

   private: // private variables accessible by the interfaces only
	    // (not from main)

        int n;  // no of books
	int ISBN[100]; // max 100 ISBN numbers
        char TITLE[100][80]; // max 100 books, each title with max 80 chars
			     // (there are no spaces in each title)
	char AUTHOR[100][20];	// max 100 books, each author name with 
				// max 20 chars 
			        // (there are no spaces in each author name)
	char PUBLISHER[100][20]; // max 100 books, each publisher name with
				// max 10 chars
			        // (there are no spaces in each publ. name)
	int YEAR[100]; // max 100 publishing years
	float PRICE[100]; // max 100 book prices
   };



BOOK_SORT::BOOK_SORT(int x)
{
      // your code for BOOK_SORT goes here 
      n=x;
      for(int i=0 ; i<n ; i++)
      {
	input_file >> ISBN[i] >> TITLE[i] >> AUTHOR[i] >> PUBLISHER[i] >> YEAR[i] >> PRICE[i];
      } 
}


void BOOK_SORT::SORT_ISBN(void)
{
	int h, i, j, k, min, min_pos, temp, temp_YEAR;
	int neg_isbn=0;
	int found_min=0;
	char temp_TITLE[100];
	char temp_AUTHOR[100];
	char temp_PUBLISHER[100];
	
	for(h=0; h<n; h++){
		if(ISBN[i]<0){
			neg_isbn=1;
		}
		else{}
	}

if(neg_isbn==0)
{
	for(i=0 ; i<n ; i++)
	{
	      min = ISBN[i];
	      min_pos = i;
	      for(j=i ; j<n ; j++)
	      {
		  if (ISBN[j] < min)
		  {
		      min = ISBN[j];
		      min_pos = j;
					found_min=1;
		  }
		  else 
		  {
		  }
	      
	}
	   if(found_min==1){   
	      //switch ISBNs
	      temp = ISBN[i];
	      ISBN[i] = ISBN[min_pos];
	      ISBN[min_pos] = temp;
	      
	      //switch YEARs
	      temp_YEAR = YEAR[i];
	      YEAR[i] = YEAR[min_pos];
	      YEAR[min_pos] = temp_YEAR;
	      
	      //switch TITLEs
	      strcpy(temp_TITLE , TITLE[i]);
	      strcpy(TITLE[i] , TITLE[min_pos]);
	      strcpy(TITLE[min_pos] , temp_TITLE);
	      
	      //switch AUTHORs
	      strcpy(temp_AUTHOR , AUTHOR[i]);
	      strcpy(AUTHOR[i] , AUTHOR[min_pos]);
	      strcpy(AUTHOR[min_pos] , temp_AUTHOR);
	      
	      //switch PUBLISHERs
	      strcpy(temp_PUBLISHER , PUBLISHER[i]);
	      strcpy(PUBLISHER[i] , PUBLISHER[min_pos]);
	      strcpy(PUBLISHER[min_pos] , temp_PUBLISHER);
		}
	}
	
	output_file << "THE LIST OF BOOKS BY ISBN (ASCENDING ORDER):" << endl;
	for(k=0 ; k<n ; k++)
	{
	      output_file << ISBN[k] << " " << YEAR[k] << " " << TITLE[k] << " " << AUTHOR[k] << " " << PUBLISHER[k] << endl;
	}
}
else {
	output_file << "INPUT ERROR. IGNORED THE INTERFACE CALL." << endl;
}

	// your code for SORT_ISBN goes here
			       
}


void BOOK_SORT::SORT_TITLE(void)
{
	int i, j, k, min_pos,temp_YEAR;
	int found_min=0;
	float temp_PRICE;
	char min_TITLE[80];
	char temp_AUTHOR[100];
	char temp_PUBLISHER[100];
	char temp_TITLE[80];
	
	for(i = 0; i<n ; i++)
	{
		strcpy(min_TITLE , TITLE[i]);
		min_pos = i;
		
		for(j=i; j<n ; j++)
		{
			if ((strcmp(min_TITLE, TITLE[j])>0))
			{
			  strcpy(min_TITLE , TITLE[j]);
			  min_pos = j;
				found_min=1;
			}
			else 
			{
			}
		}
		
	if(found_min==1){
		//switch TITLEs
		strcpy(temp_TITLE , TITLE[i]);
		strcpy(TITLE[i] , TITLE[min_pos]);
		strcpy(TITLE[min_pos] , temp_TITLE);
	      
		//switch AUTHORs
		strcpy(temp_AUTHOR , AUTHOR[i]);
		strcpy(AUTHOR[i] , AUTHOR[min_pos]);
		strcpy(AUTHOR[min_pos] , temp_AUTHOR);
		
		//switch YEARs
		temp_YEAR = YEAR[i];
		YEAR[i] = YEAR[min_pos];
		YEAR[min_pos] = temp_YEAR;
		    
		//switch PUBLISHERs
		strcpy(temp_PUBLISHER , PUBLISHER[i]);
		strcpy(PUBLISHER[i] , PUBLISHER[min_pos]);
		strcpy(PUBLISHER[min_pos] , temp_PUBLISHER);	  
		
		//switch PRICEs
		temp_PRICE = PRICE[i];
		PRICE[i] = PRICE[min_pos];
		PRICE[min_pos] = temp_PRICE;
	 }
	}
	
	output_file << "THE LIST OF BOOKS BY THEIR TITLES (ALPHABETICAL ORDER):" << endl;
	for(k=0 ; k<n ; k++)
	{
	      output_file << TITLE[k] << " " << AUTHOR[k] << " " << YEAR[k] << " " << PUBLISHER[k] << " " << PRICE[k] << " USD " << endl;
	}	
	// your code for SORT_TITLE goes here
	
}
				   
void BOOK_SORT::SORT_PRICE(void)
{
	int i, h, j, k, max, max_pos, temp, temp_YEAR;
	int found_min=0;
	char temp_TITLE[100];
	char temp_AUTHOR[100];
	float temp_PRICE;

	for(i=0 ; i<n ; i++)
	{
	      max = PRICE[i];
	      max_pos = i;
	      for(j=i ; j<n ; j++)
	      {
		  if (PRICE[j] > max)
		  {
		      max = PRICE[j];
		      max_pos = j;
					found_min=1;
		  }
	      }
	    
	if(found_min==1){
		//switch PRICEs
  	temp_PRICE = PRICE[i];
  	PRICE[i] = PRICE[max_pos];
  	PRICE[max_pos] = temp_PRICE;
  
  	//switch TITLEs
  	strcpy(temp_TITLE , TITLE[i]);
  	strcpy(TITLE[i] , TITLE[max_pos]);
  	strcpy(TITLE[max_pos] , temp_TITLE);
  
  	//switch AUTHORs
  	strcpy(temp_AUTHOR , AUTHOR[i]);
  	strcpy(AUTHOR[i] , AUTHOR[max_pos]);
  	strcpy(AUTHOR[max_pos] , temp_AUTHOR);
 
  	//switch YEARs
  	temp_YEAR = YEAR[i];
  	YEAR[i] = YEAR[max_pos];
  	YEAR[max_pos] = temp_YEAR;
	 }
	      
	}
	
	output_file << "THE LIST OF BOOKS BY THEIR PRICES (DESCENDING ORDER):" << endl;
	
	for(k=0 ; k<n ; k++)
	{
	      output_file << PRICE[k] << " USD " << TITLE[k] << AUTHOR[k] << YEAR[k] << endl;
	}	

		
	 // your code for SORT_PRICE goes here
}	
