//00095119 Henry Alexander Cortez Amaya
//No se porque tarda en iniciar, espera
#include<iostream>
#include<stdlib.h>
#include<windows.h>
#include<string>

using namespace std;

//Estructura usada para guardar los paises con sus respectivas casillas
struct PAIS{
	string nombreP="",capital="";
	int poblacion=0,edad=0;
	
}info_pais[5];

//Colocando un pseudonimo principal;
typedef struct PAIS paises;

//Estructura principal
struct Continentes{
	string nombre="";
	paises info_pais[5];
//Auxliares para conocer la capital mas grande	
   int mayor=0,cont=0,pas=0;
	
}continentes[5],mayorDato;

//colocando un pseudonimo principal
typedef struct Continentes CONT;

//Funcion para ver las diferentes opciones de lo que puede hacer el usuario.
int Opcion(int x){
     system("cls");
//Barra de opciones
	 cout<<"\n¿Que quieres hacer?\n1.Ingresar Paises\n2.Ver Continentes\n3.Conocer la Poblacion Total\n4.Ver la capital con mayor poblacion\n5.Salir\n";
     cin>>x;
     
     return x;	
}


int main(){
   int op;
//Continentes predeclarados, lo que el usuario modifica son los paises y sus respectivas casillas
   continentes[0].nombre="Africa";
   continentes[1].nombre="America";
   continentes[2].nombre="Asia";
   continentes[3].nombre="Europa";
   continentes[4].nombre="Oceania";
   
do{
	op=Opcion(0);
	switch(op){
	   case 1: //Datos();
	           break;
	   case 2: //MostrarDatos();
	           break;
	   case 3: //cout<<"La Poblacion total es de: "<<MaxPOB(continentes)<<" personas\n";
	           //system("pause");
			    break;
	   case 4: //cout<<"La capital con el mayor numero de habitantes es:"<<MayorPOB()<<"\n"; 
	           //system("pause"); 
			   break;
	}
}while(op!=5);

	return 0;
}
