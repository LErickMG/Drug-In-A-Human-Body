#include <bits/stdc++.h>
#include "../src/DistribucionExponencial.cpp"

using namespace std;

class TestDistribucion{

	public:

		static string prueba(){

			string fallo = "PRUEBA DISTRIBUCION FALLIDA!";
			string exito = "PRUEBA DISTRIBUCION REALIZADA CON EXITO!";

			vector< pair<double,double> > vacio;
			vector< pair<double,double> > v(5);
			for(int i = 0; i < 5; i++)
				v[i].first = v[i].second = (double)(i+1);

			DistribucionExponencial prueba();

			//Prueba para verificar comportamiento con vectores vacios.
			if(prueba.media(vacio) != -1){
				return fallo;
			}

			//Prueba para verificar media correcta.
			if(prueba.media(v) != 3.0){
				return fallo;
			}

			//Prueba para verificar que los datos sean mayores a 0.
			if(!prueba.verificaDatos(v)){
				return fallo;
			}
			v.push_back(-0.5);
			if(prueba.verificaDatos(v)){
				return fallo;
			}
			v[5] = 6;

			//Prueba para verificar que lambda sea correcto
			if(prueba.lambda(prueba.media(v)) - (1.0/prueba.media(v)) > 0.01){
				return fallo;
			}
			
			return exito;

		}

};