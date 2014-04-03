#include <iostream>
#include <tclap/CmdLine.h>
#include <stdio.h>  // libreria basica para entrada y salida  
#include <stdlib.h> // libreria para el uso de rand()  
#include <time.h>   // libreria para el uso de time() 
#include <math.h>
#include <itpp/base/random.h>

using namespace std;
using namespace itpp;


TCLAP::CmdLine cmd("Command description message", ' ', "0.1");
TCLAP::ValueArg<double> M("M","Parametro_M", "Numero de divisiones M",false,50.0,"double",cmd);
TCLAP::ValueArg<double> L("L","Parametro_L", "Ancho de la caja L",false,5.0,"double",cmd);
TCLAP::ValueArg<double> D("D","Parametro_D", "Coeficiente de difusion D",false,1.0,"double",cmd);
TCLAP::ValueArg<double> K("K","Parametro_K", "Reactividad del borde K",false,2.0,"double",cmd);


int main(int argc, char* argv[])
{

cmd.parse( argc, argv );
cout.precision(12);


//Declarando las variables

double h=L.getValue()/M.getValue();

int m=M.getValue();

double x [m];

int N [m];

double a,b;

int sum = 0;

double d = D.getValue();

double k = K.getValue();

double p1 = 1.0 - 2.0*d*dt/(pow(h,2));

double p2 = d*dt/(pow(h,2));

double P1 = 1.0 - k/d;

int j = 1;

	
//Inicializando en 0 N

for(int i=0;i<50;i++)
{
	N[i]=0;
}
	
N[10]=75000;

N[20]=25000;


for(int i=0; i < m; i++)
{
	
	x[i]=(2*i + 1)*h/2;
	
	cout<< x[i]<< endl;
}

for(int t = 0; t < m; t++)
{
	for(int i = 0; i < m; i++)
	{
		int aux = N[i];
		while()
	}
}

}
