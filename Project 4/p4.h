///////////////////////////////////////////////////////////////
//////////// I UNDERSTAND THAT COPYING PROGRAMS FROM OTHERS WILL BE DEALT
//////////// WITH DISCIPLINARY RULES OF CCNY.
//////////// NAME:        Michael Sohanlall
//////////// LOGIN:       ee259e08
//////////// PROJECT NUMBER: p4
/////////////////////////////////////////////////////////////////////////

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
    int i;
    ifstream input_file(file_name, ios::in); //declare the input file
    n=0;
    input_file>>n;


   if (n<0 || n > 100)
    {
      output_file<<">>> INPUT ERROR"<<endl;
       exit(1);
    }
    else
    {
        for (i=0;i<n;i++)
      {
	input_file>>ISBN[i]>>TITLE[i]>>AUTHOR[i]>>PUBLISHER[i]>>YEAR[i]>>PRICE[i];
      }
    }

}


void BOOK_OVER::GIVE_SIZE(void)
{


  if (n< 0 || n > 100)
    {
      output_file<<">>> INPUT ERROR"<<endl;
       exit(1);
    }
   else
    {
      output_file<<">>> THE NUMBER OF BOOKS IN DATABASE IS " << n << "."<< endl;
    }


}



int BOOK_OVER::operator == (BOOK_OVER &x) // x is the address of the instance being passed. An instance of a class can access the private variables of the class by using the . operator
{ 					// . is a member access operator. see: member access operators
					//the names can be the same because they are different instances
  int i,cmp=0;

  for (i=0;i<n;i++)
    {
      if ( ISBN[i]!=x.ISBN[i])
      {
	cmp=1;
      }
      else { }
    }


  if (n==x.n && cmp==0)
  {
    output_file<<">>> THERE ARE " << n << " BOOKS IN EACH DATABASE."<<endl;
    output_file<<">>> THE BOOKS IN TWO DATABASES ARE THE SAME."<<endl;
    return 1;
  }
    else
    {
      output_file<<">>> THERE ARE "<< n << " AND " <<  x.n << " BOOKS IN EACH DATABASE." << endl;
      output_file<<">>> THE BOOKS IN TWO DATABASES ARE DIFFERENT."<<endl;
	return 0;
    }
}



void BOOK_OVER::operator -= (char *author)
{
  int i,j,atleast_one=0,found_pos=0,count=0; // first determine if author has a book in private data elements.


output_file<<">>> REMOVING BOOKS BY " <<author<< ":"<<endl;

for (i=0;i < n;i++)
 {
    if (strcmp(AUTHOR[i],author)== 0)
    {
      atleast_one=1;
    }
}

if (atleast_one==1)
 {
   for (i=0;i< n;i++)
      {
	if (strcmp(AUTHOR[i],author) ==0)
	{
	  found_pos=i;
	  count++; // we have to display array elements before removing them. Since removing shifts the index by 1, the next array element would be shown if we display them after.
	output_file<<setiosflags(ios::fixed)<<">>> REMOVED:"<< "   " <<ISBN[found_pos]<<"   " <<TITLE[found_pos]<<"   "<<YEAR[found_pos]<<"   " <<PUBLISHER[found_pos]<<endl;
  for (j=found_pos;j< n;j++)
      {
	ISBN[j]=ISBN[j+1];
	strcpy(TITLE[j],TITLE[j+1]);
	strcpy(AUTHOR[j],AUTHOR[j+1]);
	strcpy(PUBLISHER[j],PUBLISHER[j+1]);
	YEAR[j]=YEAR[j+1];
	PRICE[j]=PRICE[j+1];
      }

     n=n-1;
      }

    }

    output_file<<">>> REMOVED " << count<<" BOOKS BY " << author << "."<<endl;

}

else  if (atleast_one==0)
{
  output_file<<">>> REMOVED NO BOOKS BY " << author << "."<<endl;
}

}


void BOOK_OVER::operator += (BOOK_OVER &x)
{
  int i,j,ntemp;
  ntemp=n;
  n=n+x.n; //copy array elements from x into this one. starts copying from last position+1(n) of this array the values of x.ISBN starting at position 0.
		// i.e. x.n=2, n=3 => ntotal=5. start copying from n=3 up to n=4. array index from instance x ntotal-n-x.n   5-3-2 5-
		// solution is: simultaneous for loops.
		// WHat if both objects have no books inside?
if (n>0 && n<=100)
 {
     output_file<<">>> THERE ARE " << n<<" BOOKS IN THE DATABASE:"<<endl;

  for (i=ntemp,j=0;i< n,j < x.n;i++,j++)
  {

    ISBN[i]=x.ISBN[j]; //ISBN[n]=x.ISBN[0]
    YEAR[i]=x.YEAR[j];
    PRICE[i]=x.PRICE[j];
    strcpy(PUBLISHER[i],x.PUBLISHER[j]);
    strcpy(AUTHOR[i],x.AUTHOR[j]);
    strcpy(TITLE[i],x.TITLE[j]);

  }
 for (i=0;i<n;i++)
  {
    output_file<<setiosflags(ios::fixed)<<">>>"<< "   " <<ISBN[i]<<"   " <<YEAR[i]<< "  " << TITLE[i]<<"   "<<AUTHOR[i]<<"   " <<PUBLISHER[i]<<endl;
  }
 }
    else
    {
      output_file<<">>> INPUT ERROR"<<endl;
      exit(1);
    }
}