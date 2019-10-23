#include <bits/stdc++.h>
#include <bits/stdc++.h>
#include "Entrada.cpp"
#include "DistribucionExponencial.cpp"

using namespace std;

int main(){

	//Procesar entrada
	Entrada datosEntrada;

	string direccionArchivo;
	do{
		cout << "Introduce la direccion del archivo con los datos de entrada: " << endl;
		cin >> direccionArchivo;
	}
	while(!datosEntrada.obtenerArchivo(direccionArchivo));
	
	if(!datosEntrada.procesarDatos()){
		return 0;
	}

	//Calcular distribucion.
	DistribucionExponencial distribucion(datosEntrada);
	distribucion.calculaMedia();
	distribucion.calculaLambda();
	cout << distribucion.getMedia() << endl;
	cout << distribucion.getLambda() << endl; 

	return 0;
}