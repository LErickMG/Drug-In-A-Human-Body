#include <bits/stdc++.h>
#include "../src/DistribucionExponencial.cpp"

using namespace std;

class TestDistribucion{

	public:

		static string prueba(){

			string fallo = "PRUEBA DISTRIBUCION FALLIDA!";
			string exito = "PRUEBA DISTRIBUCION REALIZADA CON EXITO!";

			vector<double> vacio;
			vector<double> v(5);
			for(int i = 0; i < 5; i++)
				v[i] = (double)(i+1);

			DistribucionExponencial prueba;

			//Prueba para verificar comportamiento con vectores vacios.
			if(prueba.mediaVector(vacio) != -1){
				return fallo;
			}

			//Prueba para verificar media correcta.
			if(prueba.mediaVector(v) != 3.0){
				return fallo;
			}
			
			
			vector< pair<double, double> > verifica;
			for(int i = 0; i < v.size(); i++){
				verifica.push_back( make_pair(v[i], v[i]) );
			}

			//Prueba para verificar que los datos sean mayores a 0.
			if(!prueba.verificaDatos(verifica)){

				return fallo;
			}
			verifica.push_back( make_pair(-1,-1));

			if(prueba.verificaDatos(verifica)){
				return fallo;
			}

			v.push_back(6);
			//Prueba para verificar que lambda sea correcto
			if(abs(prueba.lambdaDeMedia(prueba.mediaVector(v)) - (1.0/3.5) ) > 0.01){
				return fallo;
			}
			
			return exito;

		}

};