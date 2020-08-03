#include <iostream>
#include <iomanip> // para la funcion setprecision y fixed, que es para solo imprimir 2 decimales
#include<conio.h>
using namespace std;
void TomaDatos(float[], int*, float[], char[][100]); // funcion donde se toman los datos, en el char se ingresa un segundo corchete ya que es 
//el que define el tamaño de caracteres
void totPorArticulo(float[], int*, float[], float[]); //funcion donde se calcula el costo por articulo ingresado segun cantidad que lleva y precio
void MostarDatos(float[], int*, float[], float[], char[][100]); //funcion donde se muestran todos los datos
void CostoTotal(float[], int*, float*); //funcion donde calcula el costo total de la compra

int main() 
{
    int num; //variable donde usuario ingresara cuantos articulos llevara
    int cant; //variable para almacenar cuantos articulos ingresara (sin decimales)
    cout << "\n*-*-*-*-*-*-*-* Tienda Vidal *-*-*-*-*-*-*-*\n";
    cout << "*-*-*-*-*-*-*-*- Bienvenido *-*-*-*-*-*-*-*\n\n";
    cout << "Digite la cantidad de articulos (si ingresa numero con decimal, solo se tomara el numero entero): ";
    cin >> num;
    cant = (int)num; //con este comando, la variable cant solo toma la parte entera
    char nombre[1000][100]; //arreglo para almacenar nombres de los articulos, se ingresa un segundo corchete ya que es el tamaño de caracteres 
    //del char
    float cantArt[1000]; //arreglo para saber cantidad de articulos que llevara del ingresado anteriormente
    float precio[1000];  //arreglo para almacenar cantidad de articulos que lleva y el precio del articulo
    //en todos los arreglos se ingresa que el tamaño de espacios es la cantidad que ingrese el usuario, aunque nos sobrara un espacio porque
    //se inicia desde cero el conteo de espacios, pero no se le resta ya que no afecta
    float totalArticulo[1000]; //arreglo donde se almacen el total a pagar por la cantidad de articulos que lleva
    float totalCompra; //variable donde se almacenara el costo total de la comra

    if (cant >=1) //decision para saber si el numero que ingreso el usuario es correcto  //(int) es para que solo tome la parte entera en caso el user ingresa decimales
    {
        TomaDatos(cantArt, &cant, precio, nombre); //se llama a la funcion TomaDatos
        totPorArticulo(cantArt, &cant, precio, totalArticulo); //se llama a la funcion totPorArticulo
        cout << endl << "Ticket de compra:\n" << endl; 
        MostarDatos(cantArt, &cant, precio, totalArticulo, nombre); //se llama a la funcion MostrarDatos
        CostoTotal(totalArticulo, &cant, &totalCompra); //se llama a la funcion CostoTotal

        //con el siguente if me aseguro que los valores a mostrar sean correctos, osea mayores a 0, ya que al momento de que el usuario ingresa
        //un valor invalido en precio o cantidad de articulos y los regresa al inicio, no se muestre el valor de esa dato invalido
        if ( totalCompra > 0 )
        {
            cout << setprecision(2) << fixed << "Total a pagar por toda la compra es: ------> $"<< totalCompra <<endl; //impresion del valor total de la compra 
            cout << "\n*-*-*-*-*-*-*-*-*-* Tienda Vidal *-*-*-*-*-*-*-*\n";
            cout << "*-*-*-*-*-*-* Gracias por su compra *-*-*-*-*-*-*-*\n";
            cout << "*-*-*-*-*-*-*-*-*-* Vuelva pronto *-*-*-*-*-*-*-*\n\n";
            cout << "*-*-*-*-*-* Presiona ENTER para salir -*-*-*-*-*-*";
            getch(); //funcion para que le programa se detenga hasta dar enter
            exit(0);  //funcion para finalizar programa
        }
    }
    else
    {
        cout << endl << "La cantidad debe ser un numero entero mayor a 0. Intente nuevamente.\n" << endl; //mensaje de error
        cout <<"----------------------------------------------------------------------\n" << endl;
        main(); //se llama la funcion main para que el usuario lo vuelva a intentar
    }


    cout <<"Fin" << endl;
	getch();
    return 0;
}
void TomaDatos(float cantArt[],int *cant, float precio[], char nombre[][100])
{
	for(int i=0; i<*cant; i++)
    {
		cin.ignore (100000, '\n' ); //con este comando cin.ignore pude lograr que me almacene mas de una palabra el char
        cout << "\nEscriba el nombre del articulo: \n";
		cin.get(nombre[i],100); //comando cin.get permite que se almacene mas de 1 palabra en el char
		cout << "\nIngrese el precio unitario del articulo: \n";
		cin >> precio[i]; //
        if (precio[i]>=0) //If para verificar que ingreso dato correcto
        {
            cout << "\nIngrese la cantidad que lleva de este articulo: \n";
            cin >> cantArt[i]; // 

            if (cantArt[i]>0) //If para verificar que ingreso dato correcto
            {
                cout << "\n--------------------------------------------------\n";
            }
            else
            {
                cout << endl << "La cantidad que lleva  debe ser un numero mayor o igual a 0. Intente nuevamente.\n" << endl;
                cout <<"-----------------------------------------------------------------------------------\n" << endl;
                for(i=0; i < *cant; i++) //para eliminar valores en los arreglos ya que se repetira el programa
                {
                    while (i < *cant)
                    {
                        precio[i] = precio[i+1];
                        cantArt[i] = cantArt[i+1];
                        i++;
                    }
                    
                }
                main(); //se llama la funcion main para que el usuario lo vuelva a intentar
            }
            
        }
        else
        {
            cout << endl << "El valor de 'precio' debe ser un numero mayor o igual a 0. Intente nuevamente.\n" << endl;
            cout <<"-----------------------------------------------------------------------------------\n" << endl;
            for(i=0; i < *cant; i++) //para eliminar valores en los arreglos ya que se repetira el programa
            {
                while (i < *cant)
                {
                    precio[i] = precio[i+1];
                    i++;
                }
            }
            main(); //se llama la funcion main para que el usuario lo vuelva a intentar
        }
	}    

}

void totPorArticulo(float cantArt[],int *cant, float precio[], float totalArticulo[])
{
	for(int i=0; i<*cant; i++)
    {
        //con el siguente if me aseguro que los valores a calcular sean correctos, osea mayores a 0, ya que al momento de que el usuario ingresa
        //un valor invalido en precio o cantidad de articulos y los regresa al inicio, no se muestre el valor de esa dato invalido        
        if (cantArt[i]>0 & precio[i]>0 & totalArticulo>0 )
        {
            totalArticulo[i] = cantArt[i] * precio[i]; //operacion para saber el costo total por articulo
        }
	}    
}

void MostarDatos(float cantArt[],int *cant, float precio[], float totalArticulo[], char nombre[][100])
{
    for(int i=0; i<*cant; i++)
    {
        //con el siguente if me aseguro que los valores a mostrar sean correctos, osea mayores a 0, ya que al momento de que el usuario ingresa
        //un valor invalido en precio o cantidad de articulos y los regresa al inicio, no se muestre el valor de esa dato invalido
        if (precio[i] >0 & cantArt[i]>0 & totalArticulo[i]  > 0 )
        {
            //setprecision(2) y fixed es para que muestro los numeros solo con 2 decimales
            cout<< "Nombre del articulo ingresado #"<< i+1<<" ----------> "<< nombre[i] <<endl; //
            cout<< setprecision(2) << fixed << "Precio unitario del articulo ingresado #"<< i+1<<" -> $"<< precio[i] <<endl; //
            cout<< "Cantidad del articulo ingresado #"<< i+1<<" --------> "<< cantArt[i] <<endl; //
            cout<< setprecision(2) << fixed << "Costo total del articulo ingresado #"<< i+1<<" -----> $"<< totalArticulo[i] <<endl << endl; //
        }
 	}
}

void CostoTotal(float totalArticulo[],int *cant, float *totalCompra) 
{
    for(int i=0; i<*cant; i++)
    {
        //con el siguente if me aseguro que los valores a sumar  sean correctos, osea mayores a 0, ya que al momento de que el usuario ingresa
        //un valor invalido en precio o cantidad de articulos y los regresa al inicio, no se muestre el valor de esa dato invalido
        if ( totalArticulo > 0 )
        {
            *totalCompra += totalArticulo[i]; //operacion donde se van sumando los valores
        }
    }
}