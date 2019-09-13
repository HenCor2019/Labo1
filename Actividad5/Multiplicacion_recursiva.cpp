//00095119 

#include<iostream>

using namespace std;

//Prototipo de la funcion
int mult(int a, int b);

int main()
{
//Se piden los valores al usuario
	int valor1=0,valor2=0;	
	cout<<"Dame el primer valor: "; cin>> valor1;
	cout<<"Dame el segundo valor: "; cin>> valor2;
	
//Muestra el resultado
	cout<<"El resultado es: "<<mult(valor1, valor2);
	
 return 0;	
}

//Funcion
int mult(int a, int b){
   	
	if(b==1)
		return a;
	 else 
	    return a+mult(a,b-1);  		

	}
