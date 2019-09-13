//00095119 Henry Alexander Cortez Amaya Seccion01 Lic Ronaldo Canizales
//NOTA: Estuve investigando como implementar arreglos de estructuras, si lo logre pero no lo logre implementar que me reciba esa funcion como un puntero
//Algunas comandos(system("pause") o el "cls" a veces no los agarra en otros ide, este programa lo hice en DevC++
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

//Solicitan datos al usuario respecto a los paises con sus respectivas casillas
void Datos(){
	  int i=0,j=0;
	  system("cls");
      continentes[0].nombre="Africa";
      continentes[1].nombre="America";
      continentes[2].nombre="Asia";
      continentes[3].nombre="Europa";
      continentes[4].nombre="Oceania";
 
 //Rellando la informacion de cada paies   
    for(i=0;i<5;i++){ //Controla los continentes
       	  cout<<"************Ingrensando datos+++++++++++++\n";
       for(j=0;j<5;j++){ //Ayuda a rellenar las casillas de pais,capital,poblacion respectivamente
       	  cout<<"Continente actual: "<<continentes[i].nombre;
       	  cout<<"\nIngrese el pais numero "<<j+1<<" : "; cin>>continentes[i].info_pais[j].nombreP;
       	  cout<<"\nIngrese la capital del pais de "<<continentes[i].info_pais[j].nombreP<<" : "; cin>>continentes[i].info_pais[j].capital;
       	  cout<<"\nIngrese la poblacion del pais de "<<continentes[i].info_pais[j].nombreP<<" : "; cin>>continentes[i].info_pais[j].poblacion;
       	  if(mayorDato.mayor<continentes[i].info_pais[j].poblacion){//if para conocer la mayor poblacion y su ubicacion exacta
       	    mayorDato.mayor=continentes[i].info_pais[j].poblacion;
       	    mayorDato.cont=i;
       	    mayorDato.pas=j;
		    }
system("cls"); //Limpia pantalla
	   }
system("cls");	
	}
}

//Muestra los datos al usuario, los datos no se guardan, se pueden modificar 
void MostrarDatos(){
	system("cls");
	for(int i=0;i<5;i++){
		cout<<"\n\n *******Mostrando los datos del continente de "<<continentes[i].nombre<<"*******\n--------------------------------";
		for(int j=0;j<5;j++){
			cout<<"\nPais----------:"<<continentes[i].info_pais[j].nombreP;
			cout<<"\nCapital-------:"<<continentes[i].info_pais[j].capital;
			cout<<"\nPoblacion-----:"<<continentes[i].info_pais[j].poblacion;           
		}
	    cout<<"\n--------------------------------";	
	}
	system("pause");
}

//Conocer la mayor poblacion, SUMA ANIDADA
int MaxPOB(struct Continentes campo[]){
	int Maxima_pob=0;
	for(int i=0;i<5;i++)
	   for(int j=0;j<5;j++)
	      Maxima_pob+=campo[i].info_pais[j].poblacion;
    
    return Maxima_pob;

}

string MayorPOB(){
	 return continentes[mayorDato.cont].info_pais[mayorDato.pas].capital;	//Ya se conocian los datos de su ubicacion, solo se envia
}

int main(){
   int op;
   
do{
	op=Opcion(0);
	switch(op){
	   case 1: Datos(); break;
	   case 2: MostrarDatos(); break;
	   case 3: cout<<"La Poblacion total es de: "<<MaxPOB(continentes)<<" personas\n";
	           system("pause"); break;
	   case 4: cout<<"La capital con el mayor numero de habitantes es:"<<MayorPOB()<<"\n"; 
	           system("pause"); break;
	}
}while(op!=5);

	return 0;
}
