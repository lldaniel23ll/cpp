#include <iostream>
#include <cmath>

int main()
{
    double a, b, c;
    std::cout << "Enter the value of a: ";
    std::cin >> a;
    std::cout << "Enter the value of b: ";
    std::cin >> b;
    std::cout << "Enter the value of c: ";
    std::cin >> c;

    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0)
    {
        double root1 = (-b + std::sqrt(discriminant)) / (2 * a);
        double root2 = (-b - std::sqrt(discriminant)) / (2 * a);
        std::cout << "The roots are real and distinct." << std::endl;
        std::cout << "Root 1: " << root1 << std::endl;
        std::cout << "Root 2: " << root2 << std::endl;
    }
    else if (discriminant == 0)
    {
        double root = -b / (2 * a);
        std::cout << "The roots are real and equal." << std::endl;
        std::cout << "Single Root: " << root << std::endl;
    }
    else
    {
        double realPart = -b / (2 * a);
        double imaginaryPart = std::sqrt(-discriminant) / (2 * a);
        std::cout << "The roots are complex." << std::endl;
        std::cout << "Root 1: " << realPart << " + " << imaginaryPart << "i" << std::endl;
        std::cout << "Root 2: " << realPart << " - " << imaginaryPart << "i" << std::endl;
    }

    std::cin.get();
    std::cin.ignore();
    return 0;
}
