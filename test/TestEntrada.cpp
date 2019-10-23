#include <bits/stdc++.h>
#include "../src/Entrada.cpp"

using namespace std;

class TestEntrada{

	public:

		static string prueba(){

			string direccionFalsa = "archivoNoExistente.txt";
			string direccionReal = "data/out.txt";
			string datosIncorrectos = "data/dataTest.txt";
			string verificarDatos = "data/correcto.txt";

			Entrada entrada;

			string fallo = "PRUEBA ENTRADA FALLIDA!";
			string exito = "PRUEBA ENTRADA REALIZADA CON EXITO!";

			//Prueba para un archivo que no existe.
			if(entrada.obtenerArchivo(direccionFalsa)){
				return fallo;
			}
			if(entrada.procesarDatos()){
				return fallo;
			}

			//Prueba para un archivo existente.
			if(!entrada.obtenerArchivo(direccionReal)){
				return fallo;
			}
			if(!entrada.procesarDatos()){
				return fallo;
			}			

			Entrada datos;
			//Prueba para un archivo con cantidad de datos erronea.
			if(!datos.obtenerArchivo(datosIncorrectos)){
				return fallo;
			}
			if(datos.procesarDatos()){
				return fallo;
			}	

			Entrada datosVerificados;
			//Prueba para verificar que los datos cargados son correctos
			if(!datosVerificados.obtenerArchivo(verificarDatos)){
				return fallo;
			}
			if(!datosVerificados.procesarDatos()){
				return fallo;
			}
			int verificadorX[] = {1, 2, 3, 4, 5};
			int verificadorY[] = {6, 7, 8, 9, 10};
			vector<double> X = datosVerificados.getTiempos();
			vector<double> Y = datosVerificados.getConcentraciones();
			for(int i = 0; i < 5; i++){
				if(verificadorX[i] != X[i] || verificadorY[i] != Y[i])
					return fallo;
			}

			return exito;

		}

};