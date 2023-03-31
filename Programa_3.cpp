#include <iostream>
#include <fstream>

using namespace std;

struct Estudiante {
    int id;
    string nombres;
    string apellidos;
    float nota1;
    float nota2;
    float nota3;
    float nota4;
    float promedio;
    string resultado;
};

int main() {
    int n;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> n;
    
    Estudiante *estudiantes = new Estudiante[n];
    
    for (int i = 0; i < n; i++) {
        cout << "\nEstudiante #" << i+1 << endl;
        cout << "ID: ";
        cin >> estudiantes[i].id;
        cout << "Nombres: ";
        cin.ignore();
        getline(cin, estudiantes[i].nombres);
        cout << "Apellidos: ";
        getline(cin, estudiantes[i].apellidos);
        cout << "Nota 1: ";
        cin >> estudiantes[i].nota1;
        cout << "Nota 2: ";
        cin >> estudiantes[i].nota2;
        cout << "Nota 3: ";
        cin >> estudiantes[i].nota3;
        cout << "Nota 4: ";
        cin >> estudiantes[i].nota4;
        
        // Calcular promedio y determinar si aprobó o reprobó
        estudiantes[i].promedio = (estudiantes[i].nota1 + estudiantes[i].nota2 + estudiantes[i].nota3 + estudiantes[i].nota4) / 4;
        if (estudiantes[i].promedio >= 60) {
            estudiantes[i].resultado = "Aprobado";
        } else {
            estudiantes[i].resultado = "Reprobado";
        }
    }
    
    // Escribir datos en archivo binario
    ofstream archivo("notas.dat", ios::binary);
    if (archivo) {
        archivo.write(reinterpret_cast<char*>(estudiantes), n * sizeof(Estudiante));
        archivo.close();
        cout << "\nDatos almacenados en el archivo 'notas.dat'." << endl;
    } else {
        cout << "\nError al crear archivo 'notas.dat'." << endl;
    }
    
    // Leer datos desde archivo binario
    ifstream archivo_lectura("notas.dat", ios::binary);
    Estudiante estudiante_lectura;
    if (archivo_lectura) {
        cout << "\nDatos almacenados en el archivo 'notas.dat':" << endl;
        while (archivo_lectura.read(reinterpret_cast<char*>(&estudiante_lectura), sizeof(Estudiante))) {
            cout << "\nID: " << estudiante_lectura.id << endl;
            cout << "Nombres: " << estudiante_lectura.nombres << endl;
            cout << "Apellidos: " << estudiante_lectura.apellidos << endl;
            cout << "Nota 1: " << estudiante_lectura.nota1 << endl;
            cout << "Nota 2: " << estudiante_lectura.nota2 << endl;
            cout << "Nota 3: " << estudiante_lectura.nota3 << endl;
            cout << "Nota 4: " << estudiante_lectura.nota4 << endl;
            cout << "Promedio: " << estudiante_lectura.promedio << endl;
            cout << "Resultado: " << estudiante_lectura.resultado << endl;
        }
        archivo_lectura.close();
    } else {
        cout << "\nError al leer archivo 'notas.dat'." << endl;
    }
    
    // Liberar memoria
    delete[] estudiantes;
    
    return 0;
}