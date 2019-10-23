#include <bits/stdc++.h>
#include "Entrada.cpp"

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

		DistribucionExponencial(Entrada datos){

			lambda = -1;
			media = -1;
		}



};