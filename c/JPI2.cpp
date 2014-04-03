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

double h = L.getValue()/M.getValue();

int m = M.getValue();

double x [m];

int N [m];

double a,b;

double dt = 0.0001;

double d = D.getValue();

double k = K.getValue();

double p1 = 1.0 - 2.0*d*dt/(pow(h,2));

double p2 = d*dt/(pow(h,2));

double P1 = 1.0 - k/d;

int j;

	
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

for(int t = 0; t < 10000; t++)
{
	for(int i = 0; i < m; i++)
	{
		if(N[i] > 0)
		{
			int aux = N[i];
			j = 1;
			while(j < aux + 1)
			{
				a = randu();
				if(i == 0 && a >= P1)
				{
					N[i] = N[i] - 1;
				}
				if(i > 0 && a >= p1)
				{
					b = randu();
					if(b <= 0.5 && i < m-1)
					{
						N[i] = N[i] - 1;
						N[i+1] = N[i+1] + 1;
					}
					if(b > 0.5)
					{
						N[i] = N[i] - 1;
						N[i-1] = N[i-1] + 1;
					}
				}
				j++;
			}
		}
	}
}

//int sum = 0;

//for(int n = 0; n < m; n++)
//{
	//sum = sum + N[n];
//}

	//cout << sum << endl;
	

for(int l = 0; l < m; l++)
{
	cout << N[l] << endl;
}




}
