#include <string>
#include <cctype>
#include <cstring>

// verificar si es palindromo
bool palindromo(const std::string& str) {
    int len = str.length();
    for (int i = 0; i < len / 2; ++i) {
        if (tolower(str[i]) != tolower(str[len - i - 1])) {
            return false;
        }
    }
    return true;
}

//contar vocales
int contar_vocales(const std::string& str) {
    int count = 0;
    for (char c : str) {
        if (strchr("aeiouAEIOU", c)) {
            ++count;
        }
    }
    return count;
}

//para contar letras
int contar_letras(const std::string& str) {
    int count = 0;
    for (char c : str) {
        if (isalpha(c)) {
            ++count;
        }
    }
    return count;
}
//verifica que sean solo letras
bool solo_letras(const std::string& str) {
    for (char c : str) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}
//verifica que sean solo letras y numeros
bool solo_letras_numeros(const std::string& str) {
    for (char c : str) {
        if (!isalnum(c)) {
            return false;
        }
    }
    return true;
}