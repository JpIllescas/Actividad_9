#include <iostream>
#include <string>

using namespace std;

const int MAX_ESTUDIANTES = 100; // número máximo de estudiantes

struct Estudiante {
    string id;
    string nombres;
    string apellidos;
    double nota1;
    double nota2;
    double nota3;
    double nota4;
    double promedio;
    bool aprobado;
};

int main() {
    int n; // cantidad de estudiantes
    Estudiante estudiantes[MAX_ESTUDIANTES];

    // Solicitar la cantidad de estudiantes
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;

    // Solicitar la información de cada estudiante
    for (int i = 0; i < n; i++) {
        Estudiante* estudiante = &estudiantes[i]; // obtener el puntero al estudiante actual
        cout << "Ingrese la información del estudiante " << i+1 << ":" << endl;
        cout << "ID: ";
        cin >> estudiante->id;
        cout << "Nombres: ";
        cin >> estudiante->nombres;
        cout << "Apellidos: ";
        cin >> estudiante->apellidos;
        cout << "Nota 1: ";
        cin >> estudiante->nota1;
        cout << "Nota 2: ";
        cin >> estudiante->nota2;
        cout << "Nota 3: ";
        cin >> estudiante->nota3;
        cout << "Nota 4: ";
        cin >> estudiante->nota4;

        // Calcular el promedio del estudiante
        estudiante->promedio = (estudiante->nota1 + estudiante->nota2 + estudiante->nota3 + estudiante->nota4) / 4.0;

        // Determinar si el estudiante aprobó o no
        if (estudiante->promedio >= 60.0) {
            estudiante->aprobado = true;
        } else {
            estudiante->aprobado = false;
        }
    }

    // Mostrar la información de cada estudiante
    cout << endl;
    cout << "Información de los estudiantes:" << endl;
    for (int i = 0; i < n; i++) {
        Estudiante* estudiante = &estudiantes[i]; // obtener el puntero al estudiante actual
        cout << "Estudiante " << i+1 << ":" << endl;
        cout << "ID: " << estudiante->id << endl;
        cout << "Nombres: " << estudiante->nombres << endl;
        cout << "Apellidos: " << estudiante->apellidos << endl;
        cout << "Nota 1: " << estudiante->nota1 << endl;
        cout << "Nota 2: " << estudiante->nota2 << endl;
        cout << "Nota 3: " << estudiante->nota3 << endl;
        cout << "Nota 4: " << estudiante->nota4 << endl;
        cout << "Promedio: " << estudiante->promedio << endl;
        if (estudiante->aprobado) {
            cout << "Estado: Aprobado" << endl;
        } else {
            cout << "Estado: Reprobado" << endl;
        }
        cout << endl;
    }

    return 0;
}