#include <iostream>

int add(int a, int b) {
    return a + b;
}

int main() {
    int x = 5;
    int y = 7;
    int sum = add(x, y);
    std::cout << "Sum: " << sum << std::endl;
    return 0;
}