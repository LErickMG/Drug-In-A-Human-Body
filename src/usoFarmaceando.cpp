#include <bits/stdc++.h>
#include "Entrada.cpp"
#include "DistribucionExponencial.cpp"
#include "Graficador.cpp"

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
	if(!distribucion.verificador()){
		return 0;
	}
	distribucion.calculaMedia();
	distribucion.calculaLambda();
	distribucion.generarDistribucion();
	cout << distribucion.getLambda() << endl;
	 
	//Graficamos nuestros datos resultantes
	Graficador graficadorDatos(distribucion);
	graficadorDatos.grafica();

	return 0;
}