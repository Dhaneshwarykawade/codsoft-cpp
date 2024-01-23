#include <iostream>

using namespace std;

int main() {
    char choice;

    do {
        double num1, num2, result;
        char operation;

        // Input
        cout << "Enter first number: ";
        cin >> num1;

        cout << "Enter second number: ";
        cin >> num2;

        cout << "Choose operation (+, -, *, /): ";
        cin >> operation;

        // Calculation
        switch (operation) {
            case '+':
                result = num1 + num2;
                break;
            case '-':
                result = num1 - num2;
                break;
            case '*':
                result = num1 * num2;
                break;
            case '/':
                // Check for division by zero
                if (num2 != 0) {
                    result = num1 / num2;
                } else {
                    cout << "Error: Division by zero is not allowed." << endl;
                    continue; // Skip the rest of the loop and start over
                }
                break;
            default:
                cout << "Error: Invalid operation." << endl;
                continue; // Skip the rest of the loop and start over
        }

        // Output
        cout << "Result: " << result << endl;

        // Ask if the user wants to perform another calculation
        cout << "Do you want to perform another calculation? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "Calculator program exited. Goodbye!" << endl;

    return 0;
}
