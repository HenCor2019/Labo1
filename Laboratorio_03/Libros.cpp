#include <iostream>
using namespace std;

//Vos me dijiste que el titulo lo dejara sin [35] ya que no pudimos saber como ingresar datos asi, asi que solo mete una Letra Gracias :)
struct libro{
  char titulo;
  int numPaginas;
  struct libro *siguiente;
};
typedef struct libro *MiLibro;

void inialize(MiLibro *B){
   *B=NULL;
}
bool empty(MiLibro *B){
  return *B==NULL;
}
void push(MiLibro *B, char nombre,int can){
    struct libro *unNodo;
    unNodo = (struct libro *)malloc(sizeof(struct libro));
    unNodo->titulo = nombre;
    unNodo->numPaginas = can;
    unNodo->siguiente = *B;
   
    *B = unNodo;
}


void Agregar(MiLibro *B){
    char tit;
    int cantPa;
       cout<<"Escribe un titulo: ";cin>>tit;
       cout<<"Ingresa el numero de paginas que posee el libro: ";cin>>cantPa;
       push(B,tit,cantPa);
}

char Busqueda(){
    char buscarL;
    cout<<"De cual libro deseas ver el numero de paginas? ";cin>>buscarL;
    return buscarL;
}

int Conocer(MiLibro *B,char book){
   
    if(book==((*B)->titulo))
      return (*B)->numPaginas;
    else
      return 0;
}

int main()
{
  MiLibro books;
  inialize(&books);
  Agregar(&books);
  char buscar=Busqueda();
  if(Conocer(&books,buscar)!=0)
    cout<<"Tu libro tiene: "<<Conocer(&books,buscar)<<" paginas";
  else
    cout<<"No se encontro ese libro\n";
   
    return 0;
}

