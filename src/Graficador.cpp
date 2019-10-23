#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
#include "../deps/matplotlibcpp.h"

namespace plt = matplotlibcpp;
using namespace std;

class Graficador{

	private:
			
		vector<double> datosRealesEjeX;
		vector<double> datosRealesEjeY;
		
		vector<double> distribucionEjeX;
		vector<double> distribucionEjeY;

	public:

		Graficador(DistribucionExponencial & distribucion){

			vector< pair<double,double> > datosReales = distribucion.getDatosReales();
			vector< pair<double,double> > datosDistribucion = distribucion.getDistribucion();

			for(int i = 0; i < datosReales.size(); i++){
				datosRealesEjeX.push_back(datosReales[i].first);
				datosRealesEjeY.push_back(datosReales[i].second);
			}
			for(int i = 0; i < datosDistribucion.size(); i++){
				distribucionEjeX.push_back(datosDistribucion[i].first);
				distribucionEjeY.push_back(datosDistribucion[i].second);
			}

		}

		void grafica(){

			// Definir el tamaño de la pantalla = 1200x780 pixels
		    plt::figure_size(1200, 780);


		    // Plot a line whose name will show up as "log(x)" in the legend.
		    plt::named_plot("Datos reales", datosRealesEjeX , datosRealesEjeY, "ro");
		    plt::named_plot("Distribucion Exponencial", distribucionEjeX, distribucionEjeY);

		    // Titulo de la grafica.
		    plt::title("Sustancia");

		    // Enable legend.
		    plt::legend();

		    // save figure
		    const char* filename = "grafica/basic.png";
		    std::cout << "Guardamos lo resultante con el nombre " << filename << std::endl;;
		    plt::save(filename);

		}
		
};