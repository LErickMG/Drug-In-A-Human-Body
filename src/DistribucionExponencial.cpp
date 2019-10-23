#include <bits/stdc++.h>

using namespace std;

class DistribucionExponencial{

	private:
		
		double lambda;
		double media;

		vector< pair<double,double> > distribucion;
		vector< pair<double,double> > datosReales;

	public:

		
		DistribucionExponencial(){
			
			lambda = -1;
			media = -1;
		}

		DistribucionExponencial(Entrada & datos){

			lambda = -1;
			media = -1;
			vector<double> tiempos = datos.getTiempos();
			vector<double> concentraciones = datos.getConcentraciones();
			for(int i = 0; i < tiempos.size(); i++){
				datosReales.push_back( make_pair(tiempos[i], concentraciones[i]));
			}
		}

		double mediaVector(vector<double> & vec){

			//Bandera -1 para indicar error
			if(vec.size() == 0){
				return -1;
			}

			double mediaTemporal = 0;
			for(int i = 0; i < vec.size(); i++){
				mediaTemporal += vec[i];	
			}
			mediaTemporal /= (double)(vec.size());

			return mediaTemporal;
		}

		double lambdaDeMedia(double mediaTemporal){

			return (1.0/mediaTemporal);
		}

		bool verificaDatos(vector< pair<double,double> > & datos){

			for(int i = 0; i < datos.size(); i++){
				if(datos[i].first <= 0 || datos[i].second <= 0){
					cout << "Algunos datos no son mayores a 0." << endl;
					return false;
				}
			}
			return true;
		}

		bool verificador(){
			return verificaDatos(datosReales);
		}

		double getMedia(){
			return media;
		}
		double getLambda(){
			return lambda;
		}

		void calculaLambda(){

			lambda = 1.0/media;
		}

		void calculaMedia(){

			vector<double> datos;
			for(int i = 0; i < datosReales.size() ; i++){
				datos.push_back(datosReales[i].second);
			}
			media = mediaVector(datos);
		}

		void generarDistribucion(){
			
			double tiempoMaximo = datosReales.back().first;
			double segmento = tiempoMaximo/100000.0;

			double tiempo = 0.01;
			while(tiempo < tiempoMaximo){

				double cantidad = lambda*exp((-lambda)*tiempo);
				distribucion.push_back( make_pair(tiempo, cantidad));
				tiempo += segmento;
			}
			cout << "Generamos correctamente la distribucion aproximada a los datos." << endl;
		}		

		vector< pair<double,double> > getDatosReales(){
			return datosReales;
		}

		vector< pair<double,double> > getDistribucion(){
			return distribucion;
		}
};
