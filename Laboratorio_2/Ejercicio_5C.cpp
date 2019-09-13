
//Torres de hanoi, ejercicio 5C
#include <iostream>

using namespace std;

void TorHanoi(int discos,int Origen,int Auxiliar, int Destino){
    if(discos==1)
      cout<<"Toma el disco de la torre "<<Origen<<" y pasalo a la torre "<<Destino<<endl;
    else{
      TorHanoi(discos-1,Origen,Destino,Auxiliar);
      cout<<"Toma el disco de la torre "<<Origen<<" y pasalo a la torre "<<Destino<<endl;
      TorHanoi(discos-1,Auxiliar,Origen,Destino);
    }
    
}

int main()
{
  int discos=0,Origen=1,Auxiliar=2,Destino=3;
  cout<<"Dame el numero de discos: ";cin>>discos;
  cout<<"Para resolver la torre con "<<discos<<" segui estos pasos\n";
  TorHanoi(discos,Origen,Auxiliar,Destino);
 
    return 0;
}
