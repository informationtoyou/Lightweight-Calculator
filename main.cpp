#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Function to add two large numbers represented as strings
string addLargeNumbers(const string& num1, const string& num2) {
    string result;
    int carry = 0, sum = 0;
    int i = num1.size() - 1, j = num2.size() - 1;

    while (i >= 0 || j >= 0 || carry) {
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
        sum = digit1 + digit2 + carry;
        carry = sum / 10;
        result.push_back((sum % 10) + '0');
    }

    reverse(result.begin(), result.end());
    return result;
}

// Function to subtract two large numbers represented as strings
string subtractLargeNumbers(const string& num1, const string& num2) {
    string result;
    int borrow = 0, diff = 0;
    int i = num1.size() - 1, j = num2.size() - 1;

    while (i >= 0 || j >= 0) {
        int digit1 = (i >= 0) ? num1[i--] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j--] - '0' : 0;
        digit2 += borrow;

        if (digit1 < digit2) {
            borrow = 1;
            digit1 += 10;
        }
        else {
            borrow = 0;
        }

        diff = digit1 - digit2;
        result.push_back(diff + '0');
    }

    // Remove leading zeros
    while (result.size() > 1 && result.back() == '0')
        result.pop_back();

    reverse(result.begin(), result.end());
    return result;
}

// Function to multiply two large numbers represented as strings
string multiplyLargeNumbers(const string& num1, const string& num2) {
    int n = num1.size(), m = num2.size();
    vector<int> result(n + m, 0);

    for (int i = n - 1; i >= 0; --i) {
        for (int j = m - 1; j >= 0; --j) {
            int mul = (num1[i] - '0') * (num2[j] - '0');
            int sum = mul + result[i + j + 1];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }

    string resultStr;
    for (int num : result) {
        if (!(resultStr.empty() && num == 0)) {
            resultStr.push_back(num + '0');
        }
    }

    return resultStr.empty() ? "0" : resultStr;
}

// Function to divide two large numbers represented as strings
string divideLargeNumbers(const string& num1, const string& num2, int precision) {
    if (num2 == "0") return "Error: Division by zero";

    string result = "";
    string remainder = "0";

    for (size_t i = 0; i < num1.size(); ++i) {
        remainder += num1[i];
        int count = 0;

        while (remainder.size() > num2.size() ||
            (remainder.size() == num2.size() && remainder >= num2)) {
            remainder = subtractLargeNumbers(remainder, num2);
            count++;
        }

        result += to_string(count);
    }

    // Handle precision
    if (precision > 0) {
        result += ".";
        for (int i = 0; i < precision; ++i) {
            remainder += "0";
            int count = 0;
            while (remainder.size() > num2.size() ||
                (remainder.size() == num2.size() && remainder >= num2)) {
                remainder = subtractLargeNumbers(remainder, num2);
                count++;
            }
            result += to_string(count);
        }
    }

    // Remove leading zeros in result
    result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));
    return result.empty() ? "0" : result;
}

// Conversion Functions
void convertWeight() {
    double value;
    string unit;
    cout << "Enter the weight value: ";
    cin >> value;
    cout << "Enter the unit (kg, lb): ";
    cin >> unit;

    if (unit == "kg") {
        cout << value << " kg = " << value * 2.20462 << " lb" << endl;
    }
    else if (unit == "lb") {
        cout << value << " lb = " << value / 2.20462 << " kg" << endl;
    }
    else {
        cout << "Invalid unit!" << endl;
    }
}

void convertTemperature() {
    double value;
    string unit;
    cout << "Enter the temperature value: ";
    cin >> value;
    cout << "Enter the unit (C, F): ";
    cin >> unit;

    if (unit == "C") {
        cout << value << " °C = " << (value * 9 / 5) + 32 << " °F" << endl;
    }
    else if (unit == "F") {
        cout << value << " °F = " << (value - 32) * 5 / 9 << " °C" << endl;
    }
    else {
        cout << "Invalid unit!" << endl;
    }
}

void convertLength() {
    double value;
    string unit;
    cout << "Enter the length value: ";
    cin >> value;
    cout << "Enter the unit (m, ft): ";
    cin >> unit;

    if (unit == "m") {
        cout << value << " m = " << value * 3.28084 << " ft" << endl;
    }
    else if (unit == "ft") {
        cout << value << " ft = " << value / 3.28084 << " m" << endl;
    }
    else {
        cout << "Invalid unit!" << endl;
    }
}

void convertVolume() {
    double value;
    string unit;
    cout << "Enter the volume value: ";
    cin >> value;
    cout << "Enter the unit (L, gal): ";
    cin >> unit;

    if (unit == "L") {
        cout << value << " L = " << value * 0.264172 << " gal" << endl;
    }
    else if (unit == "gal") {
        cout << value << " gal = " << value / 0.264172 << " L" << endl;
    }
    else {
        cout << "Invalid unit!" << endl;
    }
}

// Main calculator loop
int main() {
    string number1, number2;
    char operation;
    int precision = 3; // Default precision for division

    cout << "Welcome to Lightweight Calculator!" << endl;
    cout << "This calculator was made by informationtoyou and is freely available on GitHub and is under an MIT License" << endl;

    while (true) {
        cout << "\nChoose an option:" << endl;
        cout << "C - Calculator" << endl;
        cout << "T - Convert Temperature" << endl;
        cout << "W - Convert Weight" << endl;
        cout << "L - Convert Length" << endl;
        cout << "V - Convert Volume" << endl;
        cout << "Q - Quit" << endl;
        cout << "Your choice: ";
        cin >> operation;

        if (operation == 'Q' || operation == 'q') {
            cout << "Exiting Lightweight Calculator. Goodbye!" << endl;
            break;
        }

        switch (operation) {
        case 'C':
        case 'c':
            cout << "\nEnter the first number: ";
            cin >> number1;
            cout << "Enter the second number: ";
            cin >> number2;

            cout << "Choose an operation:" << endl;
            cout << "A - Addition" << endl;
            cout << "S - Subtraction" << endl;
            cout << "M - Multiplication" << endl;
            cout << "D - Division" << endl;
            cout << "P - Set Precision for Division" << endl;
            cout << "Your choice: ";
            cin >> operation;

            switch (operation) {
            case 'A':
            case 'a':
                cout << "Result: " << addLargeNumbers(number1, number2) << endl;
                break;
            case 'S':
            case 's':
                if (number1 >= number2)
                    cout << "Result: " << subtractLargeNumbers(number1, number2) << endl;
                else
                    cout << "Result: -" << subtractLargeNumbers(number2, number1) << endl;
                break;
            case 'M':
            case 'm':
                cout << "Result: " << multiplyLargeNumbers(number1, number2) << endl;
                break;
            case 'D':
            case 'd':
                cout << "Result: " << divideLargeNumbers(number1, number2, precision) << endl;
                break;
            case 'P':
            case 'p':
                cout << "Enter the number of decimal places for division: ";
                cin >> precision;
                if (precision < 0) {
                    cout << "Precision must be non-negative. Setting to default 3." << endl;
                    precision = 3;
                }
                break;
            default:
                cout << "Invalid operation. Try again." << endl;
            }
            break;

        case 'T':
        case 't':
            convertTemperature();
            break;
        case 'W':
        case 'w':
            convertWeight();
            break;
        case 'L':
        case 'l':
            convertLength();
            break;
        case 'V':
        case 'v':
            convertVolume();
            break;

        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}
