#include <iostream>
using namespace std;

// 1. Template Function to find maximum of two values
template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

// 2. Template Class for Calculator
template <typename T>
class Calculator {
private:
    T num1, num2;

public:
    // Constructor
    Calculator(T a, T b) {
        num1 = a;
        num2 = b;
    }

    T add() { return num1 + num2; }
    T subtract() { return num1 - num2; }
    T multiply() { return num1 * num2; }

    T divide() {
        if (num2 != 0)
            return num1 / num2;
        else {
            cout << "Error: Division by zero!" << endl;
            return 0;
        }
    }
};

int main() {
    // Demonstrate findMax function
    int a = 5, b = 10;
    float c = 3.5f, d = 2.0f;
    double e = 10.5, f = 20.25;

    cout << "Max of " << a << " and " << b << " is: " << findMax(a, b) << endl;

    // Integer Calculator
    Calculator<int> intCalc(a, b);
    cout << "Integer Operations: "
         << a << " + " << b << " = " << intCalc.add() << ", "
         << a << " - " << b << " = " << intCalc.subtract() << ", "
         << a << " * " << b << " = " << intCalc.multiply() << ", "
         << a << " / " << b << " = " << intCalc.divide() << endl;

    // Float Calculator
    Calculator<float> floatCalc(c, d);
    cout << "Float Operations: "
         << c << " + " << d << " = " << floatCalc.add() << ", "
         << c << " - " << d << " = " << floatCalc.subtract() << ", "
         << c << " * " << d << " = " << floatCalc.multiply() << ", "
         << c << " / " << d << " = " << floatCalc.divide() << endl;

    // Double Calculator
    Calculator<double> doubleCalc(e, f);
    cout << "Double Operations: "
         << e << " + " << f << " = " << doubleCalc.add() << ", "
         << e << " - " << f << " = " << doubleCalc.subtract() << ", "
         << e << " * " << f << " = " << doubleCalc.multiply() << ", "
         << e << " / " << f << " = " << doubleCalc.divide() << endl;

    return 0;
}

