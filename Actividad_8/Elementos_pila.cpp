//Obteniendo el valor del fondo de la pila
#include<iostream>

using namespace std;

struct Pila{
	int elementos[30];
	int top;
};
typedef struct Pila Stack;


void initialize(Stack *pila){
	pila->top=-1;
}

bool empty(Stack *pila){
	return pila->top<0; 
}
void push(Stack *pila,int dato){
	if(pila->top<29)
	   (pila->top)++;
	   pila->elementos[pila->top]=dato;
}

void pop(Stack *pila, int *actual){
	if(pila>=0){
	 *actual=pila->elementos[pila->top];
     (pila->top)--;
 }
}

int Fondo(Stack *pila){
	int Actual;
  while(!empty(pila)){
  	  pop(pila,&Actual);	
  }	
  return Actual;
}
int main(){
		
	Stack pila;
initialize(&pila);
 
int P1,P2,P3;
cout<<"Dame un elemento para tu pila: "; cin>>P1;
push(&pila,P1);
cout<<"\nDame un elemento para tu pila: "; cin>>P2;
push(&pila,P2);
cout<<"\nDame un elemento para tu pila: "; cin>>P3;
push(&pila,P3);

//Mostrando el valor del fondo de la pila

cout<<"El valor que se encuentra al fondo de esta pila es: "<<Fondo(&pila);
if(empty(&pila))
   cout<<"\nEsta pila esta mas vacia que la vida del que programo esto";
   
	return 0;
}
//Obteniendo el fondo de una pila dejandola intacta
#include<iostream>

using namespace std;

struct Pila{
	int elementos[30];
	int top;
};
typedef struct Pila stack;


void initialize(stack *pila){
	pila->top=-1;
}


bool empty(stack *pila){
	return pila->top<0; 
}

void push(stack *pila, int dato){
   if(pila->top<29)	
	 pila->top++;
	 pila->elementos[pila->top]=dato;
}

void pop(stack *pila, int *actual){
	if(pila>=0){
	 *actual=pila->elementos[pila->top];
     (pila->top)--;
 }
}

int FondoIntac(stack *pila){

   stack pilaB;
   initialize(&pilaB);	

   int a
   uxiliar=0;
     
   while(!empty(pila)){
   	    pop(pila,&auxiliar);
   	    push(&pilaB,auxiliar);
   }
   int fondo=auxiliar;

   while(!empty(&pilaB)){
   	    pop(&pilaB,&auxiliar);
   	    push(pila,auxiliar);
   }   
 return fondo;	
}

void imstack(stack *pila){
 int i=3;	
	while(pila->top!=-1){
		cout<<"\nDato numero "<<i<<" ; "<<pila->elementos[pila->top];
		pila->top--;
		i--;
	}
	
}

int main(){

	stack pila;
initialize(&pila);
 
int P1,P2,P3;
cout<<"Dame un elemento para tu pila: "; cin>>P1;
push(&pila,P1);
cout<<"\nDame un elemento para tu pila: "; cin>>P2;
push(&pila,P2);
cout<<"\nDame un elemento para tu pila: "; cin>>P3;
push(&pila,P3);

//Obteniendo el del fondo sin tocarla
cout<<"El valor que se encuentra hasta el fondo es: "<<FondoIntac(&pila);
//Imprimiendo los datos de la pila original
imstack(&pila);	
	return 0;
}

