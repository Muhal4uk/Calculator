#include <iostream>
#include <cctype>
#include <stdexcept>
#include <cmath>

using namespace std;

bool isNumber(const string& input) {
    for (char c : input) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int getNumber() {
    string input;
    bool numInt = false;
    
    while (!numInt) {
        cout << "Enter a number: ";
        cin >> input;
        
        if (isNumber(input)) {
            numInt = true;
        } else {
            cerr << "Invalid input. Please enter a valid number." << endl;
        }
    }
    
    return stoi(input);
}

char getOperator() {
    char op;
    bool validOperator = false;
    while(!validOperator)
    {
        cout << "Enter operator: ";
        cin >> op;
        if(op == '+' || op == '-' || op == '*' || op == '/' || op == '^')
        {
            validOperator = true;
        }
        else
        {
            cerr << "Invalid operator. Please enter a valid operator." << endl;
        }
    }
    return op;
}

void performOperation(int num1, int num2, char op) {
    switch (op) {
        case '+':
            cout << num1 + num2;
            break;
        case '-':
            cout << num1 - num2;
            break;
        case '*':
            cout << num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                cout << num1 / num2;
            } else {
                throw invalid_argument("Division by zero is not possible");
            }
            break;
        case '^':
            cout << pow(num1, num2);
            break;
        default:
            throw invalid_argument("Invalid operator. Try again.");
    }
}

int main() {
    int num1, num2;
    char op;
    
    try {
        num1 = getNumber();
        num2 = getNumber();
        
        bool validOperator = false;
    
        while (!validOperator) {
            op = getOperator();
            performOperation(num1, num2, op);
            validOperator = true;
        }
    } catch (const invalid_argument& e) {
        cerr << e.what() << '\n';
    }

    return 0;
}