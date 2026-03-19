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

int main(){

    string nombres[20]; 
    double notas[20];    
    int cantidadEstudiantes = 0;
    int opcion;

    do{
        //Llamo mmi funcion para mostrar menu y seleccionar una opcion
        mostrarMenu();
        cin >> opcion;

        if (opcion <1 || opcion > 7){

            cout << "Opcion invalida. Intente nuevamente"<< endl;
        }

       
        switch (opcion){

        case 1:
            
            registrarEstudiantesyNotas(nombres, notas, cantidadEstudiantes);   

            break;

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

//Funcion que permite recibir nombres de los estudiantes y registrarlos
void registrarEstudiantesyNotas(string nombres[], double notas[], int &cantidad) {
    do {
        cout << "Ingrese la cantidad de estudiantes (1-20): ";
        cin >> cantidad;
    } while (cantidad < 1 || cantidad > 20); 

    for (int i = 0; i < cantidad; i++) {
        cout << "Estudiante " << i + 1 << ":" << endl;
        cout << "Nombre: ";
        cin >> nombres[i];
          
        do {
            cout << "Nota (0-20): ";
            cin >> notas[i];
            if (notas[i] < 0 || notas[i] > 20) { 
                cout << "Nota invalida. Debe estar entre 0 y 20." << endl;
            }
        } while (notas[i] < 0 || notas[i] > 20);
    }
}