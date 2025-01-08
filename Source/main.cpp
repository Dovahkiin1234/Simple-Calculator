#include <iostream>
#include <limits>
#include <cmath>
#include <complex>

using namespace std;

// Enum defining available calculator actions.
enum Actions {
    Add = 1,
    Subtract,
    Multiply,
    Divide,
    Exponentiate,
    SquareRoot
};

// Struct containing static methods for mathematical operations.
struct Calculator {
    static void Add(double value1, double value2) {
        cout << "Result: " << value1 + value2 << endl;
    }

    static void Subtract(double value1, double value2) {
        cout << "Result: " << value1 - value2 << endl;
    }

    static void Multiply(double value1, double value2) {
        cout << "Result: " << value1 * value2 << endl;
    }

    static void Divide(double value1, double value2) {
        if (value2 == 0) {
            cout << "Error: Division by zero is undefined!" << endl;
        } else {
            cout << "Result: " << value1 / value2 << endl;
        }
    }

    static void Exponentiate(double value1, double value2) {
        if (value1 < 0 && value2 != floor(value2)) {
            cout << "Error: Exponentiation with a negative base and fractional exponent is unsupported." << endl;
        } else {
            cout << "Result: " << pow(value1, value2) << endl;
        }
    }

    static void SquareRoot(double value1) {
        if (value1 < 0) {
            complex<double> result = sqrt(complex<double>(value1));
            cout << "Result (complex): " << result << endl;
        } else {
            cout << "Result: " << sqrt(value1) << endl;
        }
    }
};

// Helper function to safely get a number from the user.
double getNumber(const string& prompt) {
    double number;
    while (true) {
        cout << prompt;
        cin >> number;
        if (cin.fail()) {
            cout << "Invalid input. Please enter a valid number." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            return number;
        }
    }
}

int main() {
    cout << "Welcome to the Simple C++ Calculator!" << endl;

    while (true) {
        // Get input values.
        double value1 = getNumber("Enter the first number: ");
        double value2 = getNumber("Enter the second number: ");

        // Display operation menu.
        cout << "\nSelect an operation:\n"
             << "1: Addition\n"
             << "2: Subtraction\n"
             << "3: Multiplication\n"
             << "4: Division\n"
             << "5: Exponentiation\n"
             << "6: Square Root (only uses the first number)\n"
             << "Choice: ";

        int choice;
        cin >> choice;

        // Perform the selected operation.
        switch (choice) {
            case Actions::Add:
                Calculator::Add(value1, value2);
                break;
            case Actions::Subtract:
                Calculator::Subtract(value1, value2);
                break;
            case Actions::Multiply:
                Calculator::Multiply(value1, value2);
                break;
            case Actions::Divide:
                Calculator::Divide(value1, value2);
                break;
            case Actions::Exponentiate:
                Calculator::Exponentiate(value1, value2);
                break;
            case Actions::SquareRoot:
                Calculator::SquareRoot(value1);
                break;
            default:
                cout << "Error: Invalid choice. Please select a valid operation." << endl;
        }

        // Ask if the user wants to continue or exit.
        int continueChoice = getNumber("\nEnter 1 to continue or 2 to exit: ");
        if (continueChoice == 2) {
            cout << "Goodbye!" << endl;
            break;
        }
    }

    return 0;
}