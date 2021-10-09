#include <iostream>
#include <cmath>

int main() {
    int a, b;
    double c;
    double P;

    std::cout << "Enter two catheti of a triangle\n";
    std::cin >> a >> b;
    c = sqrt(pow(a, 2) + pow(b, 2));
    P = a + b + c;
    std::cout << "Hypotenuse = " << c << '\n';
    std::cout << "Perimeter = " << P << std::endl;
}