#include <iostream>
#include <limits>
#include <cmath>
#include <complex>

using namespace std;

enum Actions {
    // This code defines an enum named Actions that assigns integer values to named mathematical operations, such as addition, subtraction, multiplication, division, exponentiation, and square root.
    Add = 1,
    Subtract = 2,
    Multiplicate = 3,
    Divide = 4,
    Exponentiate = 5,
    SquareRoot = 6
};

// This code defines a struct named DoMath that contains methods for performing addition, subtraction, multiplication, division, and exponentiation, and prints the result of each operation to the console.
struct DoMath {
    static void Addition(double& value1, double& value2) {
        auto answer = value1 + value2;
        cout << "Answer is: " << answer << endl;
    }
    static void Subtraction(double& value1, double& value2) {
        auto answer = value1 - value2;
        cout << "Answer is: " << answer << endl;
    }
    static void Multiplication(double& value1, double& value2) {
        auto answer = value1 * value2;
        cout << "Answer is: " << answer << endl;
    }
    static void Division(double& value1, double& value2) {
        auto answer = value1 / value2;
        cout << "Answer is: " << answer << endl;
    }
    static void Exponentiation(double& value1, double& value2) {
        // We use pow(double X, double Y) to calculate exponentiation.
        // https://cplusplus.com/reference/cmath/pow/
        // for negative exponentiation
        if (value2 < 0) {
            auto answer = value1 / pow(value1, abs(value2));
            cout << "Answer is: " << answer << endl;
        } else {
            // otherwise for positive exponentiation
            auto answer = pow(value1, value2);
            cout << "Answer is: " << answer << endl;
        }
    }
    static void GetSquareRoot(double& value1) {
        // We use sqrt(double X) to calculate the square root.
        // https://cplusplus.com/reference/cmath/sqrt/
        // for negative square root
        if (value1 < 0) {
            complex<double> answer = sqrt(complex<double>(value1));
            cout << "Answer is: " << answer << endl;
        } else {
            auto answer = sqrt(value1);
            cout << "Answer is: " << answer << endl;
        }
    }
};

int main() {
    // Our input values.
    double value1;
    double value2;

    // Main loop.
    while (true) {
        while (true) { // Using while (true) to make a simple check.
            cout << "Enter the first value: ";
            cin >> value1;
            if (cin.fail()) { // Checks if user inputs another value instead of a digit.
                cout << "Enter a valid value!" << endl;
                cin.clear(); // Clears the buffer
            }
            else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // if the user gives 2 values at once just checks for the first buffer
                break;
            }
        }
        while (true) { // Using while (true) to make a simple check.
            cout << "Enter the second value: ";
            cin >> value2;
            if (cin.fail()) { // Checks if user inputs another value instead of a digit.
                cout << "Enter a valid value!" << endl;
                cin.clear(); // Clears the buffer
            }
            else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // if the user gives 2 values at once just checks for the first buffer
                break;
            }
        }

        cout << "What are you wanna do?" << endl
             << "1: Addition" << endl
             << "2: Subtraction" << endl
             << "3: Multiplication" << endl
             << "4: Division" << endl
             << "5: Exponentiation" << endl
             << "6: Square Root (only gets the first value)" << endl
             << "Select: ";

        int input;
        cin >> input;

        switch (input) {
            case Actions::Add:
                DoMath::Addition(value1,value2);
                break;
            case Actions::Subtract:
                DoMath::Addition(value1,value2);
                break;
            case Actions::Multiplicate:
                DoMath::Addition(value1,value2);
                break;
            case Actions::Divide:
                DoMath::Addition(value1,value2);
                break;
            case Actions::Exponentiate:
                DoMath::Exponentiation(value1,value2);
                break;
            case Actions::SquareRoot:
                DoMath::GetSquareRoot(value1);
                break;
            default:
                cout << "Invalid input." << endl;
                break;
        }

        cout << "1: Continue" << endl
             << "2: Close" << endl
             << "Select: ";
        int closeInput;
        cin >> closeInput;

        if (closeInput == 2) {
            break;
        }
    }

    return 0;
}