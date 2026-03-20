#include <iostream>
#include <string>
#include <cctype>

int main() {
    std::string linea;
    std::getline(std::cin, linea);
    int contador = 0;
    for (char c : linea) {
        char min = std::tolower(c);
        if (min == 'a' || min == 'e' || min == 'i' || min == 'o' || min == 'u') {
            contador++;
        }
    }
    std::cout << contador << std::endl;
    return 0;
}
