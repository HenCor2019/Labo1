#include <iostream>
#include <string>
using namespace std;

struct TPersona{
    int carnet,edad,telefono;
    string nombre,apellido,correo;
};
typedef struct TPersona Persona;

Persona solicitarDatos(){
    Persona p;  
    //---Solicitando datos
    cout<<endl;
    cout << "Nombre: "; cin >> p.nombre;
    cin.ignore();//Limpiando el buffer
    cout << "Apellido: "; getline(cin, p.apellido);
    cout << "Correo: "; getline(cin, p.correo);
    cout << "Carnet: "; cin >> p.carnet;
    cout << "Edad: "; cin >> p.edad;
    cout << "Telefono: "; cin >> p.telefono;
	    
    return p;
}
struct TNodo{
    Persona dato;
    struct TNodo *sig;
};
typedef struct TNodo Nodo;
Nodo *pInicio;

void insertarInicio(Persona p) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = pInicio;
    
    pInicio = nuevo;
}

void insertarFinal(Persona p) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = NULL;
    
    if (pInicio == NULL) {
        pInicio = nuevo;
    } else {
        Nodo *p = pInicio;
        Nodo *q = NULL;
        while (p != NULL) {
            q = p;
            p = p->sig;
        }
        q->sig = nuevo;
    }
}
void agregarPersona(){
    Persona p = solicitarDatos();
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\t1) Al principio\n\t2) Al final\n";
        cin >> opcion;
        switch(opcion){
            case 1: insertarInicio(p);  continuar = false;
            break;
            case 2: insertarFinal(p);   continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);
}
void mostrarPersona(Persona p){
    cout<<endl;
	cout << "Nombre: " << p.nombre << endl;
    cout << "Apellido: " << p.apellido << endl;
    cout << "Correo: " << p.correo << endl;
    cout << "Carnet: " << p.carnet << endl;
    cout << "Edad: " << p.edad << endl;
    cout << "Telefono: " << p.telefono << endl;

}


void mostrarLista() {
    Nodo *s = pInicio;

    while (s != NULL) {
        mostrarPersona(s->dato);
        s = s->sig;
    }
}


void eliminarPersona(){
    string  unnombre;
    cout << "Nombre de la persona: ";
    cin >> unnombre;
    
    Nodo *p = pInicio, *q = NULL;
    
    while(p != NULL && (p->dato).nombre != unnombre){
        q = p;
        p = p->sig;
    }
    if(p == NULL){
        cout << "La persona a borrar NO existe" << endl;
        return;
    }
    if(q == NULL)
        pInicio = p->sig;
    else
        q->sig = p->sig;
    delete(p);
    cout << "Persona eliminada!" << endl;
}

void modificarPersona(){
	string  unnombre;
    cout << "Nombre de la persona: ";
    cin >> unnombre;
    
    Nodo *p = pInicio, *q = NULL;
    
    while(p != NULL){
        if((p->dato).nombre == unnombre){
		cout<<"Nuevos datos\n";
    cout << "Nombre: "; cin >> (p->dato).nombre;
    cin.ignore();//Limpiando el buffer
    cout << "Apellido: "; getline(cin, (p->dato).apellido);
    cout << "Correo: "; getline(cin, (p->dato).correo);
    cout << "Carnet: "; cin >> (p->dato).carnet;
    cout << "Edad: "; cin >> (p->dato).edad;
    cout << "Telefono: "; cin >> (p->dato).telefono;
        return;
		}
		 p=p->sig;
	}
    if(p == NULL){
        cout << "Persona no encontrada" << endl;
        return;
    }
}

int main(){
    cout << "Inicializando..." << endl;
    pInicio = NULL;
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "Menu: \n\t1) Agregar persona\n\t2) Ver personas"
            << "\n\t3) Eliminar una persona\n\t4) Modificar una persona"
            << "\n\t5) Salir\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: cout << "Agregando..." << endl;
                agregarPersona();
            break;
            case 2: cout << "Listando..." << endl;
                mostrarLista();
            break;
            case 3: cout << "Eliminando..." << endl;
                 eliminarPersona();
            break;
            case 4: cout<<"Actualizando...\n";
                 modificarPersona();
            break;
            case 5: continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);

    return 0;
}
