#include <bits/stdc++.h>
#include <bits/stdc++.h>
#include "Entrada.cpp"

using namespace std;

int main(){

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

	return 0;
}