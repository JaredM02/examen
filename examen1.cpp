/* 
Examen 1 en C++
Nombre del estudiante: Martin Correa
Curso: Bootcamp Programación Cero a POO 
Clase: 10 - Examen 1 (C++) 
Fecha: 18/03/2026 
Tema: 
Sistema de registro y análisis de notas de estudiantes 
Entrada: 
    - Cantidad de estudiantes 
    - Nombres de estudiantes 
    - Nota de cada estudiante 
Proceso: 
    - Validar datos ingresados 
    - Almacenar información en arreglos 
    - Calcular promedio general 
    - Buscar una nota mayor y una nota menor 
    - Mostrar reporte de aprobados y reprobados 
    - Permitir consultar un estudiante por nombre 
Salida: 
    - Listado de estudiantes y notas 
    - Promedio general 
    - Nota mayor y nota menor 
    - Cantidad de aprobados y reprobados 
    - Resultado de búsqueda por nombre 
*/

#include <iostream>
#include <string>
using namespace std;

//Firma de funciones 
void mostrarMenu();
void registrarEstudiantesyNotas(string nombres[], double notas [], int &cantidad);
void mostrarListado(string nombres[], double notas[], int cantidad);
void calcularPromedio(double notas[], int cantidad);
int main(){

    string nombres[20]; 
    double notas[20];    
    int cantidadEstudiantes = 0;
    int opcion;

    do{
        //Llamo mmi funcion para mostrar menu y seleccionar una opcion
        mostrarMenu();
        cin >> opcion;

        //Repito si la opcion no esta en el rango, vuelvo a mostrar menu

        if (opcion <1 || opcion > 7){

            cout << "Opcion invalida. Intente nuevamente"<< endl;
        }

       
        switch (opcion){

        case 1:
            
            registrarEstudiantesyNotas(nombres, notas, cantidadEstudiantes);   

            break;


        case 2:

            mostrarListado(nombres, notas, cantidadEstudiantes);
        
            break;


        case 3:

            calcularPromedio(notas, cantidadEstudiantes);

            break;


        case 4:



        }
        
        
        
        


    }while (opcion != 7);
    return 0;

}

//Muestra en pantalla el menu
void mostrarMenu() {
    cout << "=========== MENU ===========" << endl;
    cout << "1. Registrar estudiantes y notas" << endl;
    cout << "2. Mostrar listado completo" << endl;
    cout << "3. Mostrar promedio general" << endl;
    cout << "4. Mostrar nota mayor y nota menor" << endl;
    cout << "5. Mostrar aprobados y reprobados" << endl;
    cout << "6. Buscar estudiante por nombre" << endl;
    cout << "7. Salir" << endl;
    cout << "Seleccione una opcion: "; 
}

//Funcion que permite recibir nombres de los estudiantes, notas y registrarlos
void registrarEstudiantesyNotas(string nombres[], double notas[], int &cantidad) {

    //Validacion de la cantidad de estudiantes a registrar, mientras la cantidad seleccionada sea menor a 1 o mayor a 20
    do {
        cout << "Ingrese la cantidad de estudiantes (1-20): ";
        cin >> cantidad;
    } while (cantidad < 1 || cantidad > 20); 

    //Bucle for para ingresar los nombres y guardarlas en el arreglo

    for (int i = 0; i < cantidad; i++) {
        cout << "Estudiante " << i + 1 << ":" << endl;
        cout << "Nombre: ";
        cin >> nombres[i];
         
        //Bucle do-while para validar asegurando que estemos dentro del rango y un if para mostrar un error de nota fuera de rango y 
        //permita al usuario volver a ingresar la nota.
        do {
            cout << "Nota (0-20): ";
            cin >> notas[i];
            if (notas[i] < 0 || notas[i] > 20) { 
                cout << "Nota invalida. Debe estar entre 0 y 20." << endl;
            }
        } while (notas[i] < 0 || notas[i] > 20);
    }
}

//Funcion para mostrar el listado de estudiantes con sus notas, previamente guardados en la primera opcion 
void mostrarListado(string nombres[], double notas[], int cantidad) {
    //Nos aseguramos que existan estudiantes y no dejar espacios vacios
    if (cantidad == 0) {
        cout << "No hay estudiantes registrados." << endl; 
        return;
    }
    cout << "---Listado de Estudiantes ---" << endl;

    //Bucle necesario para mostrar los estudiantes y sus notas de manera ordenada, por lo tal , tambien ocupamos el i+1
    for (int i = 0; i < cantidad; i++) {
        cout << i + 1 << ". " << nombres[i] << " - " << notas[i] << endl;
    }
}

//Funcion para calcular el promedio general
void calcularPromedio(double notas[], int cantidad) {
    //Nos aseguramos que existan estudiantes y no dejar espacios vacios
    if (cantidad == 0) {
        cout << "No hay estudiantes registrados." << endl; 
        return;
    }
    double suma = 0;
    
    //Se hace un acumulador para al final esa suma se vaya acumulando y se quede guardada con las notas ingresadas y dividirlas para la cantidad correcta. 
    for (int i = 0; i < cantidad; i++) {
        suma = suma + notas[i];
    }
    cout << "Promedio general: " << suma / cantidad << endl; 
}
