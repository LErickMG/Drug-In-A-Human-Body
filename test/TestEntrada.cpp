#include <bits/stdc++.h>
#include "../src/Entrada.cpp"

using namespace std;

class TestEntrada{

	public:

		static string prueba(){

			string direccionFalsa = "archivoNoExistente.txt";
			string direccionReal = "data/out.txt";
			string datosIncorrectos = "data/dataTest.txt";

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

			return exito;

		}

};