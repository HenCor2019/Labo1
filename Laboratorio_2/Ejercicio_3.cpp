//Ejercicio 3, raiz cuadrada

#include<iostream>

using namespace std;

float raiz(int num, float r);

int main(){
   int num=0,r=1,auxr=100;
   cout<<"Digite un entero: "; cin>>num;
   if(raiz(num,num+1)==-1)
     cout<<"Esa raiz no existe";
   else
     cout<<"La raiz de tu numero es: "<<raiz(num,num+1);
    
     
 return 0;
}

float raiz(int num, float r){
    float auxR,prob;
    auxR=((num/r)+r)*0.5;
    prob=auxR-r;
     if(prob<0)
       prob=prob*-1;
       
    if(num<0)
      return -1;
    if(prob<0.0001)
      return r;
    else if(auxR<0)
      return auxR;
    else
      return raiz(num,auxR);
    
    
}


