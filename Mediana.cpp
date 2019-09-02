#include<iostream>

using namespace std;

//Se crean las funciones
  void OrdenarDatos(int MEDI[],int);
  float Mediana(int MEDI[],int);
  
int main(){
  
  int TAM=0;
  cout<<"¿Cuantos valores quieren verificar?"<<endl; cin>>TAM;
  int MEDI[TAM]; 
//Llama a la funcion, para trabajar con los datos ya ordenados
  OrdenarDatos(MEDI,TAM);
//Se imprime la media
  cout<<endl<<"La mediana de los datos es: "<<Mediana(MEDI,TAM);	
 
 
	return 0;
}
//Pide los datos al usuario
void OrdenarDatos(int MEDI[],int tam){
	int op,i,j,k=0;
	for(k=0;k<tam;k++){
		cout<<"Dame el valor "<<k+1<<": ";
		cin>>MEDI[k];
	}

//SE usa el metodo burbuja para ordenar los datos	
   for(i=0;i<tam;i++)
       for(j=0;j<tam;j++)
       	 if(MEDI[j]>MEDI[j+1]){
       		op= MEDI[j];
       		MEDI[j]=MEDI[j+1];
       		MEDI[j+1]=op;
		   }		   	
	   
}
//Se hace la funcion para calcular la mediana
float Mediana(int MEDI[],int tam){
	float med,medp;
	int aux=0,aux2=0,aux3=0;
//se usa un if para saber si la cantidad de datos son pares, ya que se calcula diferente si es par o no	
	if(tam%2==0){
		aux2=(tam/2);
		aux3=(tam/2)+1;
		aux=(MEDI[aux2-1]+MEDI[aux3-1]);
		medp=aux*0.5;
		cout<<aux<<" "<<medp;
		//se aproxima al valor anterior
		//se retorna la mediana encontrada de los 2 valores
		
	 return medp;
	} else{
	  aux=(tam+1)/2	;
	  med=MEDI[aux];
	  
      return med;	
	}
	
}
