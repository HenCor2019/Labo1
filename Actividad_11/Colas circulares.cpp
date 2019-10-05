#include <iostream>
#include <windows.h>
/*La cola esta compuesta por 5 elementos, ya que consulte y se me dijo que unicamente implementara las colas 
sin importar si el usuario decidia el tamanio o no.
Si no compila, seguramente es por la libreria windows.h, ya que solo se encuentra en DevC++, o al menos solo aqui me ha dejado usarla
Los comandos que implemente con esta libreria son los "system("cls")" y el "system("pause")"
*/
using namespace std;

int Opciones(){
 int op;
 system("cls");
cout<<"---------------Bienvenido---------------\n¿Que deseas hacer?\n1.Ingresar nuevo elemento\n2.Eliminar un elemento\n3.Mostrar\n4.Salir\n";  
cin>>op;
return op;
}
//Insertando un elemento
void Insert(int *Col,int tam,int *Fin,int *In,int *DatIn){
	 int posicion=0,NewEl;
	if(*DatIn!=tam){
	   posicion=(*In + *DatIn)%tam; //Me ayuda a saber donde insertare el nuevo elemento
       cout<<"Ingresa un elemento a tu cola: ";cin>>NewEl;
       *(Col+posicion)=NewEl;
	   *DatIn+=1; //Necesario para saber el maximo que puedo meter y la posicion siguiente
	   cout<<"Su elemento ha sido aniadido con exito(bien hecho)";
       system("pause");//comando windows.h
    }else {
       cout<<"Tu cola creo que esta llena";
       system("pause");//comando windows.h
    }
}

//Me elimina un elemento, es una cola, me elimina el primero que entro siempre
void Pop(int *Col,int tam,int *Fin,int *In,int *DatIn){
	
	if(*DatIn!=0){
	  *(Col + *In)=0;
	  *In=(*In+1)%tam; //Necesaria para conocer donde se encuentra mi posicion inicial
      *DatIn-=1;
      cout<<"Ya esta eliminado tu elemento";
      system("pause");//comando windows.h
	}else{
      cout<<"Yo creeria que tu cola esta vacia";
      system("pause");//comando windows.h
   }
}
void Mostrar(int *cola,int tam){
	 for(int i=0;i<tam;i++)
        cout<<"["<<*(cola+i)<<"]";
     system("pause");//comando windows.h
}
int main(){
    int Final=4,Inicial=0,DatosIngr=0;
    int Cola[5]={0,0,0,0,0};//Esta cola es de 5 elementos, el ejercicio no especificaba, si se desea hacer para "n" elementos, habria que pedirlos antes
    int OP=Opciones();
while(OP!=4){
	switch(OP){
    	case 1: Insert(Cola,5,&Final,&Inicial,&DatosIngr);
    	       break;
	    case 2: Pop(Cola,5,&Final,&Inicial,&DatosIngr);
	           break;
	    case 3: Mostrar(Cola,5);
	    	   break;
	}
 OP=Opciones();
}
    return 0;
}
  
