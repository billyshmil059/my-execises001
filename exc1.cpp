#include <iostream>

int main() {
    int a;
    std::cin >> a;
    int kl = 1 + (a-1)*2;
    for (int i = 1; i <= kl; i++) {
        if (kl/2+1 >= i) {
            for (int j = 1; j <= i; j++) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
        else if (kl/2+1 < i) {
            for (int j = kl - i + 1; j > 0; j--) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
    }
}