#include <iostream>

int main() {
    long long n;
    std::cin >> n;
    int suma = 0;
    while (n > 0) {
        suma += n % 10;
        n /= 10;
    }
    std::cout << suma << std::endl;
    return 0;
}
