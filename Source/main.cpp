#include <iostream>
#include <limits>
#include <cmath>
#include <complex>

using namespace std;

// This code defines an enum named Actions that assigns integer values to named mathematical operations, such as addition, subtraction, multiplication, division, exponentiation, and square root.
enum Actions {
    Add = 1,
    Subtract = 2,
    Multiplicate = 3,
    Divide = 4,
    Exponentiate = 5,
    SquareRoot = 6
};

// This code defines a struct named DoMath that contains methods for performing addition, subtraction, multiplication, division, exponentiation and square root, and prints the result of each operation to the console.
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
            complex<double> answer = sqrt(complex<double>(value1)); // Using complex<double> to get the negative value. If you use auto or double here you will get nan.
            cout << "Answer is: " << answer << endl;
        } else {
            auto answer = sqrt(value1);
            cout << "Answer is: " << answer << endl;
        }
    }
};

// Getting the input number for values.
int getNumber(const string& prompt) {
    int number;
    while (true) {
        cout << prompt;
        cin >> number;
        if (cin.fail()) {
            cout << "Enter a valid digit!" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else break;
    }
    return number;
}

int main() {
    // Main loop.
    while (true) {
        // Our input values.
        double value1 = getNumber("Enter the first value: ");
        double value2 = getNumber("Enter the second value: ");

        // Selections
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

        // Checking the input for selection
        switch (input) {
            case Actions::Add:
                DoMath::Addition(value1,value2);
                break;
            case Actions::Subtract:
                DoMath::Subtraction(value1,value2);
                break;
            case Actions::Multiplicate:
                DoMath::Multiplication(value1,value2);
                break;
            case Actions::Divide:
                DoMath::Division(value1,value2);
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

        // Getting close input for the program.
        int closeInput;
        while (true) {
            cout << "1: Continue" << endl
                 << "2: Close" << endl;

            closeInput = getNumber("Select: ");
            // Closing the input if input is 2
            if (closeInput > 2 or closeInput < 0) {
                cout << "Enter a valid number!" << endl;
            } else break;
        }
        if (closeInput == 2) {
            break;
        }
    }
    return 0;
}
