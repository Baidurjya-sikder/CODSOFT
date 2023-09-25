#include <iostream>

using namespace std;

int main() {
    double num1, num2, result;
    char operation;

    // Input first number
    cout << "Enter the first number: ";
    cin >> num1;

    // Input second number
    cout << "Enter the second number: ";
    cin >> num2;

    // Input the operation (+, -, *, /)
    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    // Perform the selected operation and display the result
    switch (operation) {
        case '+':
            result = num1 + num2;
            cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
            break;
        case '-':
            result = num1 - num2;
            cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
            break;
        case '*':
            result = num1 * num2;
            cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
            }
            break;
        default:
            cout << "Invalid operation. Please enter +, -, *, or /." << endl;
            break;
    }

    return 0;
}