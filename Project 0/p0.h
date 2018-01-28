///////////////////////////////////////////////////////////////
////////// I UNDERSTAND THAT COPYING PROGRAMS FROM OTHERS WILL BE DEALT
////////// WITH DISCIPLINARY RULES OF CCNY.
////////// NAME:        Michael Sohanlall	
////////// LOGIN:       ee259d08
////////// PROJECT NUMBER: p0
///////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>

using namespace std;

// declare the input file 
  ifstream input_file("in.0",ios::in);
// declare the output file 
  ofstream output_file("out.0",ios::out);

class READWRITE{
   public:      // public interfaces for this class

        READWRITE(void);       // constructor
                                // returns nothing (void)

        void READ(void);       // interface to read from in.0;
                                // requires no parameters,
                                // returns no values

        void PRINT(void);       // interface to write into out.0
                                 // requires no parameters,
                                 // returns no values
 
        void REVERSE_PRINT(void);      // interface to write into out.0
                                 // the information in reverse order;
                                 // requires no parameters,
                                 // returns no values
 
   private: // private variables to be used by this class interfaces
            // only (not from main)
 
        int n;  // no of grades
        int A[1000]; // array to hold the grades
};
 
READWRITE::READWRITE (void)
{
	int i;
	n = 0;  // initialize num of grades to 0;
	for(i=0;i<1000;i++){
		A[i]=0;
	}   // initialize the elements of A array to 0;
}

void READWRITE::READ(void)
{
	
	// write your code here:
	//	to read the data from in.0 file;
	// 	to save them into private data members of n and A[1000];
	// 	to write "n GRADES ARE READ>" into out.0 file;
	//
	// Hint: the format to read integer n from in.0 file is:
	//	input_file >> n;
	//
	// Hint: the format to write into out.0 file is:
	//	output_file << n << " GRADES ARE READ." << endl;

	input_file >> n;

	for(int i=0; i<n;i++) {
		input_file >> A[i];
	}

	output_file << n << " GRADES ARE READ." << endl;
}

void READWRITE::PRINT(void)
{ 
	for(int i=0;i<n;i++){
	output_file << A[i] << endl;
}	
	// write your code here:
	//	to print the grades into out.0 file;
}

void READWRITE::REVERSE_PRINT(void)
{
	 for(int i=n-1;i>=0;i--){
		output_file << A[i] << endl;
	}
	// write your code here:
	//	to print the grades into out.0 file;
}
