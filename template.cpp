#include <iostream>

template <class T>
class Calculator
{
    T a;
    T b;

public:
    Calculator(T a, T b)
    {
        this->a = a;
        this->b = b;
    }

    T add();
    T sub();
    T mul();
    T div();
};

template <class T>
T Calculator<T>::add()
{
    return a + b;
}

template <class T>
T Calculator<T>::sub()
{
    return a - b;
}

template <class T>
T Calculator<T>::mul()
{
    return a * b;
}

template <class T>
T Calculator<T>::div()
{
    return a / b;
}

int main()
{
    double a;
    double b;

    std::cout << "Enter first number >> ";
    std::cin >> a;
    std::cout << "Enter second number >> ";
    std::cin >> b;

    Calculator<double> calc(a, b);
    std::cout << "Add: " << calc.add() << std::endl;
    std::cout << "Subtract: " << calc.sub() << std::endl;
    std::cout << "Multiply: " << calc.mul() << std::endl;
    std::cout << "Divide: " << calc.div() << std::endl;

    return 0;
}