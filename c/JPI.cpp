#include <iostream>
#include <tclap/CmdLine.h>
#include <stdio.h>  // libreria basica para entrada y salida  
#include <stdlib.h> // libreria para el uso de rand()  
#include <time.h>   // libreria para el uso de time() 

using namespace std;
TCLAP::CmdLine cmd("Command description message", ' ', "0.1");
TCLAP::ValueArg<double> M("M","Parametro_M", "Parametro M",false,50.0,"double",cmd);
TCLAP::ValueArg<double> L("L","Parametro_L", "Parametro L",false,5.0,"double",cmd);

int main(int argc, char* argv[])
{

cmd.parse( argc, argv );
cout.precision(12);


//Declarando las variables
double h=L.getValue()/M.getValue();

double t=0.0;

double dt=0.0001;

double x [50];

double N [50];

double a,b;

srand((unsigned)time(NULL));
	
//Inicializando en 0 N
for(int i=0;i<50;i++)
	N[i]=0;
	
N[10]=75000;

N[20]=25000;

for(int i=0; i < M.getValue(); i++)
{
	
	x[i]=(2*i + 1)*h/2;
	
	cout << x[i] << endl;
	
}

while(t < 1 + dt)
{
    for(int j=0;j < 100000;j++)
    {
	for(int i = 0;i < 50;i++)
	{
	    if(N[i] > 0)
	    {
		a = rand()%1;
		if(a >= 0.8 && i == 0)
		{
		    N[i] = N[i] - 1;
		}
		if(a >= 0.98)
		{
		    b = rand()%1;
		    if(b <= 0.5 && i < 49)
		    {
				N[i] = N[i]-1;
				N[i+1] = N[i+1] +1;
			}
			if(b > 0.5 &&  i > 0)
			{
				N[i] = N[i]-1;
				N[i-1] = N[i-1] +1;
			}
		
		}
	    }
	}
    }
    t= t + dt;
}


}
