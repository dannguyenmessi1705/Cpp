#include <iostream>

int main()
{
    int x = 10, y = 0, z;

    try
    {
        if (y == 0)
        {
            throw "Division by zero error";
        }
        z = x / y;
        std::cout << z << std::endl;
    }
    catch (const char *error)
    {
        std::cerr << "Error: " << error << std::endl;
    }
    return 0;
}