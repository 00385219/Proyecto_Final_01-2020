#include <iostream>
using namespace std;
#include <string>
#include<conio.h>

int main ()
{
    int cant; //variable para saber cuantos articulos ingresara
    cout << "Digite la cantidad de articulos: ";
    cin >> cant;
    char nombre[cant][100]; //arreglo para almacenar nombres de los articulos, se usa string ya que char me daba errores
    int cantArt[cant];
    float precio[cant];  //arreglo para almacenar cantidad de articulos que lleva y el precio del articulo
    char IngNombre;
    
    for(int i=0; i<cant; i++)
    {
		cin.ignore (100000, '\n' );
        cout << "\nEscriba el nombre del articulo: \n";
		cin.get(nombre[i],100);

        cout << "\nIngrese el precio unitario del articulo: \n";
		cin >> precio[i]; //
		cout << "\nIngrese la cantidad que lleva de este articulo: \n";
		cin >> cantArt[i]; //   
	}    
	for(int i=0; i<cant; i++)
    {
		cout<<i<<" -> "<< nombre[i] <<endl; //
        cout<<i<<" -> "<< precio[i] <<endl; //
        cout<<i<<" -> "<< cantArt[i] <<endl; //
	}
    getch();
    return 0;
}