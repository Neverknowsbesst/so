#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unistd.h>
#include "procesar_texto.h" 
#include "procesar_numeros.h"
#include <ctype.h>

int main(int argc, char *argv[]) {
    int opt;
    std::string username;
    std::string password;
    std::string texto;
    std::vector<int> vector;
    double numero = 0;

    //getopt
    while((opt = getopt(argc, argv, "u:p:t:v:n:")) != -1) {
        switch (opt) {
            case 'u':
                username = optarg;
                break;
            case 'p':
                password = optarg;
                break;
            case 't':
                texto = optarg;
                break;
            case 'v': {
                // dividir el vector
                std::string vector_str = optarg;
                std::stringstream ss(vector_str);
                std::string token;
                while (std::getline(ss, token, ';')) {
                    vector.push_back(std::stoi(token));
                }
                break;
            }
            case 'n':
                numero = std::stod(optarg);
                break;
        }
    }
    if(!solo_letras(username) || username.length()<3){
        std::cerr << "Error: el nombre de usuario debe contener solo letras y tener al menos 3 caracteres.\n";
        return EXIT_FAILURE;
    }
    
    if(!solo_letras_numeros(password) || password.length()<6){
        std::cerr << "Error: la clave debe contener solo letras y numeros, ademas tener al menos 6 caracteres.\n";
        return EXIT_FAILURE;
    }


    // menu
    int opcion;
    do {
        std::cout << "\nMenu:\n";
        std::cout << "1) Verificar palindromo\n";
        std::cout << "2) Contar vocales\n";
        std::cout << "3) Contar letras\n";
        std::cout << "4) Promedio y sumatoria del vector\n";
        std::cout << "5) Calcular f(x) = 5x^2 + 1/x\n";
        std::cout << "6) Salir\n";
        std::cout << "\nSelecciona una opcion: \n";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                if (!texto.empty()) {
                    if (palindromo(texto)) {
                        std::cout << "'" << texto << "' es un palindromo.\n";
                    } else {
                        std::cout << "'" << texto << "' no es un palindromo.\n";
                    }
                }
                break;
            case 2:
                if (!texto.empty()) {
                    std::cout << "La frase tiene " << contar_vocales(texto) << " vocales.\n";
                }
                break;
            case 3:
                if (!texto.empty()) {
                    std::cout << "La frase tiene " << contar_letras(texto) << " letras.\n";
                }
                break;
            case 4:
                if (!vector.empty()) {
                    promedio_sumatoria(vector);
                }
                break;
            case 5:
                std::cout << "f(" << numero << ") = " << funcion_f(numero) << "\n";
                break;
            case 6:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opcion no valida.\n";
        }
    } while (opcion != 6);

    return 0;
}
