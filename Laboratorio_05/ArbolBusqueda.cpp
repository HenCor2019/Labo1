#include <iostream>
using namespace std;


struct Tnodo{
    int dato;
    struct Tnodo *sig;
}; typedef struct Tnodo Lista;
Tnodo *pInicio;

void InsLista(int n){
    Lista *Nuevo=new Lista;
    Nuevo->dato=n;
    Nuevo->sig=NULL;
    
    if(pInicio==NULL){
        pInicio=Nuevo;
    }
    else{
        Lista *p=pInicio;
        Lista *q=NULL;
        
        while(p!=NULL){
            q=p;
            p=p->sig;
        }
        q->sig=Nuevo;
    }
}

void MostrarLista(){
    Lista *p=pInicio;
    
    if(p==NULL){
        cout<<"La fila esta vacia"<<endl;
        return;
    }
    
    cout<<"\nFila creada: ";
    while(p!=NULL){
        cout<<"["<<p->dato<<"]";
        p=p->sig;
    }
    cout<<endl<<endl;
}


//------ Creacion de nodo y de arbol ------
struct nodo{
    int info;
    struct nodo *izq;
    struct nodo *der;
};
typedef struct nodo Nodo;
typedef struct nodo *Arbol;

Arbol crearArbol(int x){
    Arbol p = new Nodo;
    p->info = x;
    p->izq = NULL;
    p->der = NULL;
    return p;
}

//------ Agregar nodos a un arbol ------
void asignarIzq(Arbol a, int unDato){
    if(a == NULL)
        cout << "Error: arbol vacio" << endl;
    else if(a->izq != NULL)
        cout << "Error: subarbol IZQ ya existe" << endl;
    else
        a->izq = crearArbol(unDato);
}

void asignarDer(Arbol a, int unDato){
    if(a == NULL)
        cout << "Error: arbol vacio" << endl;
    else if(a->der != NULL)
        cout << "Error: subarbol DER ya existe" << endl;
    else
        a->der = crearArbol(unDato);
}

void agregarNodo(Arbol a){
    //solicitar informacion (numero a agregar)
    int numero = 0;
    cout << "Numero a agregar: ";
    cin >> numero;
    
    Arbol p = a;
    
    //desplazarse hasta el lugar adecuado
    while(true){
        if(numero == p->info){
            cout << "Error: " << numero << " ya existe" << endl;
            return;
        }
        else if(numero < p->info){//ir a la izquierda
            if(p->izq == NULL)
                break;
            else
                p = p->izq;
        }
        else{//ir a la derecha
            if(p->der == NULL)
                break;
            else
                p = p->der;
        }
    }
    
    //agregar el nuevo nodo
    if(numero < p->info)
        asignarIzq(p, numero);
    else
        asignarDer(p, numero);
}

//------ Recorrer un arbol (in, pre y post orden) ------
void preorden(Arbol a){
    if(a != NULL){
        cout << " " << a->info;
        preorden(a->izq);
        preorden(a->der);
    }
}
void inorden(Arbol a){
    if(a != NULL){
        inorden(a->izq);
        cout << " " << a->info;
        inorden(a->der);
    }
}
void postorden(Arbol a){
    if(a != NULL){
        postorden(a->izq);
        postorden(a->der);
        cout << " " << a->info;
    }
}

void recorrerArbol(Arbol a){
    cout << "Recorrido PRE orden:"; preorden(a); cout << endl;
    cout << "Recorrido IN orden:"; inorden(a); cout << endl;
    cout << "Recorrido POST orden:"; postorden(a); cout << endl;
}

//Lee los valores de la lista y calcula el promedio
float Prom(){
    Lista *p=pInicio;
    float prom=0;
    int cant=0,suma=0;
    
    cout<<"\nPromedio: ";
    while(p!=NULL){
        cant++;
        suma+=p->dato;
        p=p->sig;
    }
    
    prom=suma/cant;
    return prom;
}

//Retorna si encuentra o no el elemento pedido
bool comparar(Arbol a, int num){

    if(num==NULL){
        return false;
    }
    
    if(num == a->info){
        InsLista(num); 
        return true;
    }
    
    else if(num<a->info)
        return comparar(a->izq,num);
   
    else if(num>a->info)
        return comparar(a->der,num);
    
    return true;
}

void Promedio(Arbol a){
    int valor=0;
    
    if(a==NULL){
        cout<<"Arbol vacio"<<endl;
        return;
    }
    
    cout<<"Ingrese los valores a buscar en el arbol"<<endl;
    cout<<"Presione (-1) para finalizar"<<endl;
    
    while(true){
        cout<<"--> ";
        cin>>valor;
        
        if(valor!=-1){
            bool comparando=comparar(a,valor);
        
        if(comparando==true)
            cout<<"Tu valor existe\nAgregado con existo\n";
        else
            cout<<"Ese valor no existe\n";
        }
        else
            break;
    }
    MostrarLista();
    cout<<"El promedio es de: "<<Prom();
    cout<<endl;
}

int main(){
    pInicio=NULL;
    int variable = 0;
    cout<<"Inicializando arbol...\nValor contenido en la raiz: ";
    cin >> variable;
    
    Arbol arbol = crearArbol(variable);
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "Menu: \n\t1) Agregar\n\t2) Recorrer"
        << "\n\t3) Promedio\n\t4) Salir\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: agregarNodo(arbol);
                break;
            case 2: recorrerArbol(arbol);
                break;
            case 3: Promedio(arbol);
                break;
            case 4: continuar = false;
                break;
            default: cout << "Opcion erronea!" << endl;
                break;
        }
    }while(continuar);
    
    return 0;
}
