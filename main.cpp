#include <iostream>

void printTree(int height)
{
    for (int i = 1; i <= height; ++i)
    {
        for (int j = 1; j <= height - i; ++j)
        {
            std::cout << " ";
        }
        for (int k = 1; k <= 2 * i - 1; ++k)
        {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}

int main()
{
    int height;
    std::cout << "Enter the height of the tree: ";
    std::cin >> height;

    printTree(height);

    // Add a pause before exiting
    std::cout << "Press Enter to exit...";
    std::cin.get();
    std::cin.ignore();

    return 0;
}
