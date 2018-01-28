///////////////////////////////////////////////////////////////
//////////// I UNDERSTAND THAT COPYING PROGRAMS FROM OTHERS WILL BE DEALT
//////////// WITH DISCIPLINARY RULES OF CCNY.
//////////// NAME:        Michael Sohanlall
//////////// LOGIN:       ee259e08
//////////// PROJECT NUMBER: px
/////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <iomanip>

using namespace std;

// declare the input file
  ifstream input_file("in.3",ios::in);
// declare the output file
  ofstream output_file("out.3",ios::out);
 
 

  class BOOK_PROCESS{

   public:      // public interfaces for this class

        BOOK_PROCESS(int);       // example: b.BOOK_PROCESS(x);
				// constructor where integer x is the
				// num of books in the database;

        void PROCESS_PUBLISHER(char *);  // example: b.PROCESS_PUBLISHER(p);
				// interface to sort the books from
				// publisher p by their ISBN number
				// in descending order;
                                // returns no values;

        void PROCESS_AUTHOR(char *);  // example: b.PROCESS_AUTHOR(a);
				// interface to alphabetically sort the 
				// books from author a by their title; 
				// assume that an author will not have
				// more than one book with the same title;
                                // returns no values;

        void PROCESS_PRICE(int);   // example: b.PROCESS_PRICE(y);
				// interface to sort the books published
				// in year y or later by their ISBN numbers
				// in ascending order;
                                // returns no values;

  	void PROCESS_PRINT();   // example: b.PROCESS_PRINT();

	void PROCESS_SORT(int); // example: b.PROCESS_SORT(y);

   private: // private variables accessible by the interfaces only
	    // (not from main)

        int n;  // no of books
	int ISBN[100]; // max 100 ISBN numbers
        char TITLE[100][80]; // max 100 books, each title with max 80 chars
			     // (there are no spaces in each title)
	char AUTHOR[100][20];	// max 100 books, each author name with 
				// max 20 chars 
			        // (there are no spaces in each author name)
	char PUBLISHER[100][15]; // max 100 books, each publisher name with
				// max 15 chars
			        // (there are no spaces in each publ. name)
	int YEAR[100]; // max 100 publishing years
	float PRICE[100]; // max 100 book prices, max $1000.
   };

 BOOK_PROCESS::BOOK_PROCESS(int x)     
 {
	// your code for BOOK_PROCESS goes here 
	n=x;
	int i;
	for (i=0; i<x; i++)
	{
		input_file>>ISBN[i]>>TITLE[i]>>AUTHOR[i]>>PUBLISHER[i]>>YEAR[i]>>PRICE[i];
	}
 }

 void BOOK_PROCESS::PROCESS_PUBLISHER(char * this_pub) 
 {
	// your code for PROCESS_PUBLISHER
	int i, j,k, min, min_position, temp, duplicate=0, neg_isbn, found=0;
	char min_title[100], temp_title[100];
	char min_author[100], temp_author[100];
	char min_publisher[100], temp_publisher[100];
	float min_price, temp_price;
	
	if( (n < 0) || (n > 99))		///looks for negative amount of books
	{
		output_file << "INPUT ERROR. IGNORED THE INTERFACE CALL." << endl; /////default file
	}
	
	
	else if (duplicate=0)		////checks for duplicate publisher
	{
		for(i=0; (i<n && duplicate==0); i++)
		{
			for(j=i+1; (j<n && duplicate==0); j++)
			{
				if (ISBN[i]=ISBN[j] )  //if duplicate isbn or title found return 1
				duplicate=1;
			}
		}
		if(duplicate==1)
		{
			output_file<< "INPUT ERROR. IGNORED THE INTERFACE CALL." << endl;
		}
	} 		////end statement that checks for duplicate publisher
	
	
	else		// sort statement
	{
		for(k=0; k<n; k++) 		///checks for negatives
		{
			if ((ISBN[i] || TITLE[i] || AUTHOR[i] || PUBLISHER[i] || YEAR[i] || PRICE[i])<0)
			{
				neg_isbn=1;
				output_file<< "INPUT ERROR. IGNORED THE INTERFACE CALL." << endl;
			}
			else {}	
		} 		//end check for negative isbn etc
		
		if (neg_isbn==0)  ///if negative isbn not found then swap
		{
			for(i=0; i<n; i++)
			{
				min=ISBN[i];
				min_position=i;
				for(j=i; j<n; j++)
				{
					if(ISBN[j]<min)
					{
						min=ISBN[j];
						min_position=j;
						
					}
					else {}
				}
					
				// swap int ISBN
				temp= ISBN[i];
				ISBN[i]=ISBN[min_position];
				ISBN[min_position]=temp;
				
				// swap strcpy TITLE 
				strcpy(temp_title, TITLE[i]);
				strcpy(TITLE[i], TITLE[min_position]);
				strcpy(TITLE[min_position], temp_title);
				
				// swap strcpy AUTHOR
				strcpy(temp_author, AUTHOR[i]);
				strcpy(AUTHOR[i], AUTHOR[min_position]);
				strcpy(AUTHOR[min_position], temp_author);
				 
				//swap strcpy PUBLISHER
				strcpy(temp_publisher, PUBLISHER[i]);
				strcpy(PUBLISHER[i], PUBLISHER[min_position]);
				strcpy(PUBLISHER[min_position], temp_publisher);
				
				// swap int YEAR
				temp=YEAR[i];
				YEAR[i]=YEAR[min_position];
				YEAR[min_position]=temp;
				
				// swap float PRICE 
				temp_price=PRICE[i];
				PRICE[i]= PRICE[min_position];
				PRICE[min_position]=temp_price;
			}
			
			output_file << "THE LIST OF BOOKS FROM PUBLISHER" << this_pub <<"(ASCENDING BY ISBN): "<<endl;
			for(i=0; i<n ; i++)
			{
				if(strcmp(this_pub, PUBLISHER[i])==0)
				{
					found=1;
					output_file <<ISBN[i]<<"	"<<YEAR[i]<<"        "<<TITLE[i]<<"        "<<AUTHOR[i]<<"        "<<endl;
				}
				else{}	
			}
			if (found==0)
			{
				output_file << "THE LIST OF BOOKS FROM PUBLISHER" << this_pub <<"(ASCENDING BY ISBN): "<<endl;
				output_file << "THERE ARE NO BOOKS LISTED. " << endl;
			}
		}
	}
}

 void BOOK_PROCESS::PROCESS_AUTHOR(char * this_author)
 {
 	
 	int i, j,k, min, min_position, temp, duplicate=0, neg_isbn, found=0;
	char min_title[100], temp_title[100];
	char min_author[100], temp_author[100];
	char min_publisher[100], temp_publisher[100];
	float min_price, temp_price;
	
	if( (n < 0) || (n > 99))		///looks for negative amount of books
	{
		output_file << "INPUT ERROR. IGNORED THE INTERFACE CALL." << endl; /////default file
	}
	
	
	else if (duplicate=0)		////checks for duplicate publisher
	{
		for(i=0; (i<n && duplicate==0); i++)
		{
			for(j=i+1; (j<n && duplicate==0); j++)
			{
				if (ISBN[i]=ISBN[j])  //if duplicate isbn or title found return 1
				duplicate=1;
			}
		}
		if(duplicate==1)
		{
			output_file<< "INPUT ERROR. IGNORED THE INTERFACE CALL." << endl;
		}
	} 		////end statement that checks for duplicate publisher
	
	else		// sort statement
	{
		for(k=0; k<n; k++) 		///checks for negatives
		{
			if ((ISBN[i] || TITLE[i] || AUTHOR[i] || PUBLISHER[i] || YEAR[i] || PRICE[i])<0)
			{
				neg_isbn=1;
				output_file<< "INPUT ERROR. IGNORED THE INTERFACE CALL." << endl;
			}
			else {}	
		} 		//end check for negative isbn ...etc
		
		if (neg_isbn==0)  ///if negative isbn ..etc not found then swap
		{
			for(i=0; i<n && found==0; i++)
			{
				if(strcpy(min_title, TITLE[i]));
            	min_position=i;
            	for(j=i; j<n; j++)
            	{
            		if ((strcmp(min_title,  TITLE[j])>0))
	                {
                        strcpy(min_title, TITLE[j]);
                        min_position=j;
	                }
					else{}			
				}
				
		     	// swap int ISBN
				temp= ISBN[i];
				ISBN[i]=ISBN[min_position];
				ISBN[min_position]=temp;
				
				// swap strcpy TITLE 
				strcpy(temp_title, TITLE[i]);
				strcpy(TITLE[i], TITLE[min_position]);
				strcpy(TITLE[min_position], temp_title);
				
				// swap strcpy AUTHOR
				strcpy(temp_author, AUTHOR[i]);
				strcpy(AUTHOR[i], AUTHOR[min_position]);
				strcpy(AUTHOR[min_position], temp_author);
				 
				//swap strcpy PUBLISHER
				strcpy(temp_publisher, PUBLISHER[i]);
				strcpy(PUBLISHER[i], PUBLISHER[min_position]);
				strcpy(PUBLISHER[min_position], temp_publisher);
				
				// swap int YEAR
				temp=YEAR[i];
				YEAR[i]=YEAR[min_position];
				YEAR[min_position]=temp;
				
				// swap float PRICE 
				temp_price=PRICE[i];
				PRICE[i]= PRICE[min_position];
				PRICE[min_position]=temp_price;
			}
			
			output_file << "THE LIST OF BOOKS FROM AUTHOR "<< this_author << " (SORTED ALPHABETICALLY): " <<endl;
			for(i=0; i<n ; i++)
			{
				if(strcmp(this_author, AUTHOR[i])==0)
				{
					found=1;
					output_file <<ISBN[i]<<"	"<<YEAR[i]<<"        "<<TITLE[i]<<"        "<<PUBLISHER[i]<<"        "<<endl;
				}
				else{}	
			}
			if (found==0)
			{
				output_file<< "THE LIST OF BOOKS FROM AUTHOR "<< this_author << " (SORTED ALPHABETICALLY): " <<endl;
				output_file<< "THERE ARE NO BOOKS LISTED. " << endl;
			}
		}
	}
	
 }
 
 
 void BOOK_PROCESS::PROCESS_PRICE(int x)
 {
	// your code for PROCESS_PRICE
	int i, j,k, min, min_position, temp, duplicate=0, neg_isbn, found=0;
	char min_title[100], temp_title[100];
	char min_author[100], temp_author[100];
	char min_publisher[100], temp_publisher[100];
	float min_price, temp_price;
	
	if( (n < 0) || (n > 99))		///looks for negative amount of books
	{
		output_file << "INPUT ERROR. IGNORED THE INTERFACE CALL." << endl; /////default file
	}
	
	
	else if (duplicate=0)		////checks for duplicate publisher
	{
		for(i=0; (i<n && duplicate==0); i++)
		{
			for(j=i+1; (j<n && duplicate==0); j++)
			{
				if (ISBN[i]=ISBN[j] )  //if duplicate isbn or title found return 1
				duplicate=1;
			}
		}
		if(duplicate==1)
		{
			output_file<< "INPUT ERROR. IGNORED THE INTERFACE CALL." << endl;
		}
	} 		////end statement that checks for duplicate publisher
	
	
	else		// sort statement
	{
		for(k=0; k<n; k++) 		///checks for negatives
		{
			if ((ISBN[i] || TITLE[i] || AUTHOR[i] || PUBLISHER[i] || YEAR[i] || PRICE[i])<0)
			{
				neg_isbn=1;
				output_file<< "INPUT ERROR. IGNORED THE INTERFACE CALL." << endl;
			}
			else {}	
		} 		//end check for negative isbn etc
		
		if (neg_isbn==0)  ///if negative isbn not found then swap
		{
			for(i=0; i<n; i++)
			{
				min=ISBN[i];
				min_position=i;
				for(j=i; j<n; j++)
				{
					if(ISBN[j]<min)
					{
						min=ISBN[j];
						min_position=j;
						
					}
					else {}
				}
					
				// swap int ISBN
				temp= ISBN[i];
				ISBN[i]=ISBN[min_position];
				ISBN[min_position]=temp;
				
				// swap strcpy TITLE 
				strcpy(temp_title, TITLE[i]);
				strcpy(TITLE[i], TITLE[min_position]);
				strcpy(TITLE[min_position], temp_title);
				
				// swap strcpy AUTHOR
				strcpy(temp_author, AUTHOR[i]);
				strcpy(AUTHOR[i], AUTHOR[min_position]);
				strcpy(AUTHOR[min_position], temp_author);
				 
				//swap strcpy PUBLISHER
				strcpy(temp_publisher, PUBLISHER[i]);
				strcpy(PUBLISHER[i], PUBLISHER[min_position]);
				strcpy(PUBLISHER[min_position], temp_publisher);
				
				// swap int YEAR
				temp=YEAR[i];
				YEAR[i]=YEAR[min_position];
				YEAR[min_position]=temp;
				
				// swap float PRICE 
				temp_price=PRICE[i];
				PRICE[i]= PRICE[min_position];
				PRICE[min_position]=temp_price;
			}
			
			output_file << "THE LIST OF BOOKS PUBLISHED YEAR "<< x <<" OR LATER (ASCENDING BY ISBN): "<<endl;
			for(i=0; i<n ; i++)
			{
				if(YEAR[i] > x)
				{
					found=1;
					output_file <<ISBN[i]<<"	"<<YEAR[i]<<"        "<<AUTHOR[i]<<"        "<<TITLE[i]<<"        "<<PUBLISHER[i]<<endl;
				}
				else{}	
			}
			if (found==0)
			{
				output_file << "THE LIST OF BOOKS PUBLISHED YEAR "<< x <<" OR LATER (ASCENDING BY ISBN): "<<endl;
				output_file << "THERE ARE NO BOOKS LISTED. " << endl;
			}
		}
	}
}

void BOOK_PROCESS::PROCESS_PRINT()
{

}
                                
void BOOK_PROCESS::PROCESS_SORT(int x)
 {
	// your code for PROCESS_PRICE
	int i, j, k, min, min_position, temp, duplicate=0, neg_isbn, found=0;
	char min_title[100], temp_title[100];
	char min_author[100], temp_author[100];
	char min_publisher[100], temp_publisher[100];
	float min_price, temp_price;
	
	if( (n < 0) || (n > 99))		///looks for negative amount of books
	{
		output_file << "INPUT ERROR. IGNORED THE INTERFACE CALL." << endl; /////default file
	}
	
	
	else if (duplicate=0)		////checks for duplicate publisher
	{
		for(i=0; (i<n && duplicate==0); i++)
		{
			for(j=i+1; (j<n && duplicate==0); j++)
			{
				if (ISBN[i]=ISBN[j] )  //if duplicate isbn or title found return 1
				duplicate=1;
			}
		}
		if(duplicate==1)
		{
			output_file<< "INPUT ERROR. IGNORED THE INTERFACE CALL." << endl;
		}
	} 		////end statement that checks for duplicate publisher
	
	
	else		// sort statement
	{
		for(k=0; k<n; k++) 		///checks for negatives
		{
			if ((ISBN[i] || TITLE[i] || AUTHOR[i] || PUBLISHER[i] || YEAR[i] || PRICE[i])<0)
			{
				neg_isbn=1;
				output_file<< "INPUT ERROR. IGNORED THE INTERFACE CALL." << endl;
			}
			else {}	
		} 		//end check for negative isbn etc
		
		if (neg_isbn==0 && x==1)  ///if negative isbn not found and x=1 sort in ascending order
		{
			for(i=0; i<n; i++)
			{
				min=ISBN[i];
				min_position=i;
				for(j=i; j<n; j++)
				{
					if(ISBN[j]<min)
					{
						min=ISBN[j];
						min_position=j;
						
					}
					else {}
				}
					
				// swap int ISBN
				temp= ISBN[i];
				ISBN[i]=ISBN[min_position];
				ISBN[min_position]=temp;
				
				// swap strcpy TITLE 
				strcpy(temp_title, TITLE[i]);
				strcpy(TITLE[i], TITLE[min_position]);
				strcpy(TITLE[min_position], temp_title);
				
				// swap strcpy AUTHOR
				strcpy(temp_author, AUTHOR[i]);
				strcpy(AUTHOR[i], AUTHOR[min_position]);
				strcpy(AUTHOR[min_position], temp_author);
				 
				//swap strcpy PUBLISHER
				strcpy(temp_publisher, PUBLISHER[i]);
				strcpy(PUBLISHER[i], PUBLISHER[min_position]);
				strcpy(PUBLISHER[min_position], temp_publisher);
				
				// swap int YEAR
				temp=YEAR[i];
				YEAR[i]=YEAR[min_position];
				YEAR[min_position]=temp;
				
				// swap float PRICE 
				temp_price=PRICE[i];
				PRICE[i]= PRICE[min_position];
				PRICE[min_position]=temp_price;
			}
			output_file << "OUTPUT FROM PROCESS_SORT:"<<endl;
			output_file << "BOOKS SORTED IN ASCENDING ORDER. "<<endl;

		}
		else if(neg_isbn==0 && x == -1) //sort in decending order
		{
			for(i=0; i<n; i++)
			{
				min=ISBN[i];
				min_position=i;
				for(j=i; j<n; j++)
				{
					if(ISBN[j]>min)
					{
						min=ISBN[j];
						min_position=j;
						
					}
					else {}
				}
					
				// swap int ISBN
				temp= ISBN[i];
				ISBN[i]=ISBN[min_position];
				ISBN[min_position]=temp;
				
				// swap strcpy TITLE 
				strcpy(temp_title, TITLE[i]);
				strcpy(TITLE[i], TITLE[min_position]);
				strcpy(TITLE[min_position], temp_title);
				
				// swap strcpy AUTHOR
				strcpy(temp_author, AUTHOR[i]);
				strcpy(AUTHOR[i], AUTHOR[min_position]);
				strcpy(AUTHOR[min_position], temp_author);
				 
				//swap strcpy PUBLISHER
				strcpy(temp_publisher, PUBLISHER[i]);
				strcpy(PUBLISHER[i], PUBLISHER[min_position]);
				strcpy(PUBLISHER[min_position], temp_publisher);
				
				// swap int YEAR
				temp=YEAR[i];
				YEAR[i]=YEAR[min_position];
				YEAR[min_position]=temp;
				
				// swap float PRICE 
				temp_price=PRICE[i];
				PRICE[i]= PRICE[min_position];
				PRICE[min_position]=temp_price;
			}
			output_file << "OUTPUT FROM PROCESS_SORT:"<<endl;
			output_file << "BOOKS SORTED IN DECENDING ORDER. "<<endl;
		}
		else
		{
			output_file<< "INPUT ERROR. IGNORED THE INTERFACE CALL." << endl;
		}
	}
}
