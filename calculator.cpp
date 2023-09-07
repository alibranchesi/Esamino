#include <iostream>
#include <stdexcept>
#include <string>

int main()
{
    try
    {
        std::cout << "First operand: ";
        double a;
        std::cin >> a;
        if (!std::cin.good())
            throw std::runtime_error{"Invalid first operand!"};

        std::cout << "Second operand: ";
        double b;
        std::cin >> b;
        if (!std::cin.good())
            throw std::runtime_error{"Invalid second operand!"};

        std::cout << "Select the operator (+ , - , * , / ): ";
        char operation;
        std::cin >> operation;

        double result;
        switch (operation)
        {
        case '+':
            result = a + b;
            break;

        case '-':
            result = a - b;
            break;

        case '*':
            result = a * b;
            break;

        case '/':
            result = a / b;
            break;

        default:
            std::string error = "Invalid operator: ";
            throw std::runtime_error{error + operation};
            break;
        }

        std::cout << "The result is: " << result << '\n';
    }
    catch (std::runtime_error const &e)
    {
        std::cerr << e.what() << '\n';
    }
}