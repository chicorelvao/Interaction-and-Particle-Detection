#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;


int main(){


	ofstream outFile("random_numbers.dat");

	srand(123);

	// Number of random numbers to generate

	int N = 1000;

	cout << "Number of random pairs: " << N << endl;	

	double randomX;
	double randomY;
	double randomZ;
	double norm;



	for(int i=0; i<N; i++){

		randomX = (rand()/((double)RAND_MAX + 1))*2 - 1;
		randomY = (rand()/((double)RAND_MAX + 1))*2 - 1;

		norm = pow(randomX, 2) + pow(randomY, 2);

		if(norm < 1){
			randomZ = sqrt(1 - pow(randomX, 2) - pow(randomY, 2));
			//Store each array element in the file
			outFile <<  randomX << " "<< randomY << " " << randomZ<< endl;

		}

	}

	outFile.close();


	ofstream myFile("random_numbers_angles.dat");

	srand(123);

	// Number of random numbers to generate

	cout << "Number of random pairs: " << N << endl;	

	double azimute;
	double altitude;
	double pi = 2*acos(0.0);

	for(int i=0; i<N; i++){

		azimute = acos(2*(rand()/((double)RAND_MAX)) - 1);
		altitude = (rand()/((double)RAND_MAX + 1))*2*pi;


		myFile <<  azimute << " " << altitude << endl;

	} 
	


	myFile.close();

	

	return 0;

}