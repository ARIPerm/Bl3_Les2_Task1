#include <iostream>
#include <Windows.h>

class Calculator {
private:
    double num1;
    double num2;

public:
    bool setNum1(double num) {
        if (num != 0)
        {
            num1 = num;
            return true;
        }
        return false;
    }

    bool setNum2(double num) {
        if (num != 0)
        {
            num2 = num;
            return true;
        }
        return false;
    }

    double add() {
        return num1 + num2;
    }

    double multiply() {
        return num1 * num2;
    }

    double subtract_1_2() {
        return num1 - num2;
    }

    double subtract_2_1() {
        return num2 - num1;
    }

    double divide_1_2() {
        return num1 / num2;
    }

    double divide_2_1() {
        return num2 / num1;
    }
};

void createNumber(std::string string, Calculator& calc);
void printInfo(Calculator calc);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    while (true)
    {
        Calculator calc;
        createNumber("num1", calc);
        createNumber("num2", calc);
        printInfo(calc);
    }    
}

void createNumber(std::string string, Calculator& calc)
{
    bool isOk = false;
    while (!isOk) 
    {
        std::cout << "Введите " << string << ": ";
        double number;
        std::cin >> number;

        if (string == "num1")
        {
            isOk = calc.setNum1(number);
        }
        else if (string == "num2")
        {
            isOk = calc.setNum2(number);
        }

        if (!isOk)
            std::cout << "Неверный ввод!" << std::endl;
    }
}

void printInfo(Calculator calc)
{
    std::cout << "num1 + num2 = " << calc.add() << std::endl;
    std::cout << "num1 - num2 = " << calc.subtract_1_2() << std::endl;
    std::cout << "num2 - num1 = " << calc.subtract_2_1() << std::endl;
    std::cout << "num1 * num2 = " << calc.multiply() << std::endl;
    std::cout << "num1 / num2 = " << calc.divide_1_2() << std::endl;
    std::cout << "num2 / num1 = " << calc.divide_2_1() << std::endl;
}