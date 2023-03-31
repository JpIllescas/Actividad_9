#include <iostream>
#include <string>

using namespace std;

const int MAX_ESTUDIANTES = 100; // número máximo de estudiantes

int main() {
    int n; // cantidad de estudiantes
    string id[MAX_ESTUDIANTES];
    string nombres[MAX_ESTUDIANTES];
    string apellidos[MAX_ESTUDIANTES];
    double nota1[MAX_ESTUDIANTES];
    double nota2[MAX_ESTUDIANTES];
    double nota3[MAX_ESTUDIANTES];
    double nota4[MAX_ESTUDIANTES];
    double promedio[MAX_ESTUDIANTES];
    bool aprobado[MAX_ESTUDIANTES];

    // Solicitar la cantidad de estudiantes
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;

    // Solicitar la información de cada estudiante
    for (int i = 0; i < n; i++) {
        cout << "Ingrese la información del estudiante " << i+1 << ":" << endl;
        cout << "ID: ";
        cin >> id[i];
        cout << "Nombres: ";
        cin >> nombres[i];
        cout << "Apellidos: ";
        cin >> apellidos[i];
        cout << "Nota 1: ";
        cin >> nota1[i];
        cout << "Nota 2: ";
        cin >> nota2[i];
        cout << "Nota 3: ";
        cin >> nota3[i];
        cout << "Nota 4: ";
        cin >> nota4[i];

        // Calcular el promedio del estudiante
        promedio[i] = (nota1[i] + nota2[i] + nota3[i] + nota4[i]) / 4.0;

        // Determinar si el estudiante aprobó o no
        if (promedio[i] >= 60.0) {
            aprobado[i] = true;
        } else {
            aprobado[i] = false;
        }
    }

    // Mostrar la información de cada estudiante
    cout << endl;
    cout << "Información de los estudiantes:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Estudiante " << i+1 << ":" << endl;
        cout << "ID: " << id[i] << endl;
        cout << "Nombres: " << nombres[i] << endl;
        cout << "Apellidos: " << apellidos[i] << endl;
        cout << "Nota 1: " << nota1[i] << endl;
        cout << "Nota 2: " << nota2[i] << endl;
        cout << "Nota 3: " << nota3[i] << endl;
        cout << "Nota 4: " << nota4[i] << endl;
        cout << "Promedio: " << promedio[i] << endl;
        if (aprobado[i]) {
            cout << "Estado: Aprobado" << endl;
        } else {
            cout << "Estado: Reprobado" << endl;
        }
        cout << endl;
    }

    return 0;
}