#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;


int main(){

	/* Ficheiro para o qual são exportados os pontos gerados, em coordenadas cartesianas,
	 * para construir uma esfera de raio unitário
	 */
	
	ofstream outFile("random_numbers.dat");

	srand(123);

	// Número de números aleatórios a serem gerados
	int N = 1500;

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
			randomZ = pow(-1,i)*sqrt(1 - pow(randomX, 2) - pow(randomY, 2));
			// Armazena cada elemento do array no ficheiro
			outFile <<  randomX << " "<< randomY << " " << randomZ<< endl;

		}

	}

	outFile.close();

	/* Ficheiro para o qual são exportados os pontos gerados, correspondentes as coordenadas
	 * de longitude/azimute e coaltitude/altitude
	 */

	ofstream myFile("random_numbers_angles.dat");

	srand(123);

	cout << "Number of random pairs: " << N << endl;	

	double azimute;
	double altitude;
	double pi = 2*acos(0.0);

	for(int i=0; i<N; i++){
		
		/* Aplicação do método da transformada inversa para chegar às expressões
		 * que permitem obter as distribuições não-uniformes desejadas
		 */
		azimute = acos(1 - 2*(rand()/((double)RAND_MAX)));
		altitude = (rand()/((double)RAND_MAX + 1))*2*pi;


		myFile <<  azimute << " " << altitude << endl;

	} 
	


	myFile.close();

	

	return 0;

}