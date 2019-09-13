//Ejercicio 13, deducir que hace una funcion recursiva, 
//R/ Es una suma progresiva(suma los anteriores hasta el actual)
#include<iostream>

using namespace std;

int func(int n);

int iter(int num);
int main(){
    int algo;
    cout<<"Dame un valor:";cin>>algo;
    cout<<"La funcion retorna: "<<func(algo)<<"\ny mi funcion iterativa retorna:"<<iter(algo);
    
 return 0;    
}
//Funcion dada
int func(int n){
    if(n==0)
      return 0;
    else
      return n+func(n-1);
    
}
//Funcion mia de forma iterativa
int iter(int num){
    int valor=0;
    
 if(num==0)
   return 0;
 else
    for(int i=0;i<=num;i++)
      valor+=i;

return valor;
}


