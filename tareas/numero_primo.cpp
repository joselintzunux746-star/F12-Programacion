#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    if (n < 2) { std::cout << "no primo"; return 0; }
    if (n == 2) { std::cout << "primo"; return 0; }
    if (n % 2 == 0) { std::cout << "no primo"; return 0; }

    bool es_primo = true;
    for (int i = 3; i <= std::sqrt(n); i += 2) {
        if (n % i == 0) {
            es_primo = false;
            break;
        }
    }
    std::cout << (es_primo ? "primo" : "no primo");
    return 0;
}
