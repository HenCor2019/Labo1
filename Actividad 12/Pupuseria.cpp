#include <iostream>
//#include <string>

using namespace std;

struct Ordenes{
	int Queso=0,FQ=0,Revueltas=0;
	bool Arroz;
}; typedef struct Ordenes MiPupuseria;

struct TNodo{
    MiPupuseria dato;
    struct TNodo *sig;
};
typedef struct TNodo Nodo;
Nodo *pInicio;


void insertarFinal(MiPupuseria P) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = P;
    nuevo->sig = NULL;
    
    if (pInicio == NULL) {
        pInicio = nuevo;
    } else {
        Nodo *P = pInicio;
        Nodo *q = NULL;
        while (P != NULL) {
            q = P;
            P = P->sig;
        }
        q->sig = nuevo;
    }
}

MiPupuseria SolicitarOrden(){
	MiPupuseria pupusas;
	bool Terminar=false;
		
	do{
	int op=0;
	cout<<"¿Que pupusas desea ordenar?"<<endl;
	cout<<"\t1) Queso\n\t2) Frijol con Queso\n\t3) Revueltas\n\t4) Listo!!";
	cout<<"\nSu opcion: ";
	cin>>op; cout<<endl;
	
	switch(op){
		case 1: cout<<"\n¿Cuantas te anoto?: "; cin>>pupusas.Queso;		
				break;
		case 2: cout<<"\n¿Cuantas te anoto?: "; cin>>pupusas.FQ;
				break;
		case 3: cout<<"\n¿Cuantas te anoto?: "; cin>>pupusas.Revueltas;
				break;
		case 4: Terminar=true;
				break;		
		default: cout<<"\nNo hay de ese tipo de pupusas"<<endl;
				break;
	}	
}while(!Terminar);

char Arroz;
cout<<"Desea que las pupusas sean de arroz(S/N)?: "; cin>>Arroz;
if(Arroz=='s'||Arroz=='S'){
	pupusas.Arroz=true;
}
else pupusas.Arroz=false;

insertarFinal(pupusas);
return pupusas;
}

void Mostrar(MiPupuseria p){
	cout<<"\t"<<p.Queso<<"- Queso"<<"\n\t"<<p.FQ<<"- Frijol con Queso"<<"\n\t"<<p.Revueltas<<"- Revueltas";
	cout<<"\nMasa: ";
	if(p.Arroz==true)
		cout<<"Arroz\n";
	else 
	    cout<<"Maiz\n\n";
}

void Vacia(){
	Nodo *s=pInicio;
	
	if(s==NULL)
	  cout<<"Aun no tenemos pedidos"<<endl<<endl;
	else
	  while(s!=NULL){
		Mostrar(s->dato);
		s=s->sig;
	  }
}

int main(){
	pInicio=NULL;
	bool Terminar=false;
	
	do{
		int op=0;
		cout<<"Que desea hacer?"<<endl;
		cout<<"\t1) Ordenar\n\t2) Mostrar Ordenes\n\t3) Salir"<<endl;
		cout<<"\nSu opcion: ";cin>>op; cout<<endl;
		
		switch(op){
			case 1: SolicitarOrden();
					break;
			case 2: Vacia();
					break;
			case 3: Terminar=true;
					break;
			default: cout<<"Disculpa, acaba de pasar un carro, no te escuche, repitelo por favor\n";
					break;			
		}
	}while(!Terminar);
	return 0;
}


