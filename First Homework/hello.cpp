//

// Summary of the libraries included here

// iostream - write to the screen

// fstream  - read/write to files

// stdlib.h - random number generator

// time.h   - functions related to the system clock

//

// To compile this program:

// g++ exercise01.cc -o exercise01

//

// And to run it:

// ./exercise01



#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;


int main(){

	

	cout << "This is how you write to screen in C++" << endl;

	ofstream outFile("random_numbers.dat");


	// First of all we must initialise the random generator with a seed

	// In this example, we're using the system clock

	// srand(time(0));

	// but we can also have a fixed seed, as shown here

	// This ensures that we always get the same sequence of random numbers

	srand(123);



	// Number of random numbers to generate

	int N = 10000;



	cout << "Number of random numbers: " << N << endl;


	//An array is not necessary, but it keeps things cleans
	double randomArr[N];
	//Pick a lambda to change the "balance" of the distribution
	double lambda = 2.1;	

	// Now let's do a cycle and write randoms to the screen and/or file

	double random;



	for(int i=0; i<N; i++){

		random = rand()/((double)RAND_MAX + 1);

		// comment the line below if using a large N, otherwise you'll

		// end up with thousands (millions) of lines in the terminal

		//We are doing the exponential distribution

		randomArr[i] = -1.0*(1.0/lambda)*log(1.0-random);

		//Store each array element in the file
		outFile << randomArr[i] << endl;

	}

	outFile.close();

	

	return 0;

}