#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <math.h>

using namespace std;


int main(){

	/* Ficheiro para o qual s�o exportados os pontos gerados, em coordenadas cartesianas,
	 * para construir uma esfera de raio unit�rio
	 */
	
	ofstream outFile("random_numbers.dat");

	srand(123);

	// N�mero de n�meros aleat�rios a serem gerados
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

	/* Ficheiro para o qual s�o exportados os pontos gerados, correspondentes as coordenadas
	 * de longitude/azimute e coaltitude/altitude
	 */

	ofstream myFile("random_numbers_angles.dat");

	srand(123);

	cout << "Number of random pairs: " << N << endl;	

	double azimute;
	double altitude;
	double pi = 2*acos(0.0);

	for(int i=0; i<N; i++){
		
		/* Aplica��o do m�todo da transformada inversa para chegar �s express�es
		 * que permitem obter as distribui��es n�o-uniformes desejadas
		 */
		azimute = acos(1 - 2*(rand()/((double)RAND_MAX)));
		altitude = (rand()/((double)RAND_MAX + 1))*2*pi;


		myFile <<  azimute << " " << altitude << endl;

	} 
	


	myFile.close();

	

	return 0;

}