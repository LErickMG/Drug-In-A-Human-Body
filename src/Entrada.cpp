#include <bits/stdc++.h>

using namespace std;

class Entrada{

	private:
		
		fstream archivo;
		char direccionArchivo[100];
		vector<double> tiempos;
		vector<double> concentraciones;

	public:

		bool obtenerArchivo(string _direccionArchivo){

			strcpy(direccionArchivo, _direccionArchivo.c_str());
			
			archivo.open(direccionArchivo);
			if(archivo.fail()) {
			    cout << "El archivo no se puede abrir, introduzca un archivo y direccion validos. " << endl; 
				return false;
			}
			else{
				cout << "El archivo fue cargado con exito" << endl;	
				return true;
			}
		}

		bool procesarDatos(){

			double dato;
			bool columnaTiempo = true;

			if(archivo.fail()){
				cout << "No se ha cargado ningun archivo." << endl;
				return false;
			}

			while(archivo >> dato){

				if(columnaTiempo){
					tiempos.push_back(dato);
					columnaTiempo = false;
				}
				else{
					concentraciones.push_back(dato);
					columnaTiempo = true;
				}
			}
			if(tiempos.size() != concentraciones.size()){
				cout << "La cantidad de datos y concentraciones difieren, verificar el archivo." << endl;
				return false;
			}
			else {
				cout << "La cantidad de datos y concentraciones son correctas." << endl;
				return true;
			}
			archivo.close();
		}

		vector<double> getTiempos(){
			return tiempos;
		}

		vector<double> getConcentraciones(){
			return concentraciones;
		}

};