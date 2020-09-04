#include "metodo.h"


metodo::metodo(string* array){
    this->array = array;
}

metodo::~metodo(){

}

void metodo::imprimirArray() 
{ 
    int tamano = this->array->size();
    int i; 
    for (i=0; i <= tamano; i++) 
        cout<<"Valor: "<<getAscii(this->array[i])<<" = "<<this->array[i]<<endl; 
} 

int metodo::getAscii(string cadena){
   int n = cadena.length();
   int resultado = 0;
   char char_array[n+1];
   strcpy(char_array,cadena.c_str());
   for (int i=0;i<n;i++){
       //cout<<char_array[i]<<endl;
       resultado = resultado+int(char_array[i]);
   }
   return resultado;    
}


int metodo::getPivote (string array[], int pequeno, int grande) 
{ 
    int pivote = getAscii(array[grande]);    
    int i = (pequeno - 1);  
  
    for (int j = pequeno; j <= grande - 1; j++) 
    { 
        if (getAscii(array[j]) <= pivote) 
        { 
            i++;    
            swap(array[i], array[j]);  //Intercambio de valores
        } 
    } 
    swap(array[i + 1], array[grande]); 
    return (i + 1); 
} 

void metodo::quicksort(string array[],int pequeno, int grande)
{ 
    if (pequeno < grande) 
    { 
        int pivote = getPivote(array, pequeno, grande); 
        quicksort(array, pequeno, pivote - 1); 
        quicksort(array, pivote + 1, grande); 
    } 
} 

void metodo::quicksort(){
    if (this->array->size() >= 2){
        quicksort(this->array,0,this->array->size());
    }else
    {
        cout<<"Error, el array tiene menos de 2 elementos"<<endl;
    }
}