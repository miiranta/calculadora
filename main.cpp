#include <iostream>
#include <cctype>
#include <string>
#include <cmath>
#include "functions.hpp"

#define ADDITION 9700
#define SUBTRACTION 11500
#define MULTIPLICATION 10900
#define DIVISION 10000
#define EXPONENCIATION 10100

using namespace std;

const int ARGS = 4; // Exact number of arguments needed in the operation

int main(int argc, char **argv) {

    if (argc != ARGS) {
        if (argc == 2) {
            char command{tolower(argv[1][0])};

            if (command == 'h') {
                cout << "To use the calculater, please type in the terminal: " << "\n";
                cout << "{name_of_the_executable} {operation} {value1} {value2}" << "\n\n";

                cout << "Operation may be:" << "\n";
                cout << "'a': addition" << "\n";
                cout << "'s': subtraction" << "\n";
                cout << "'m': multiplication" << "\n";
                cout << "'d': division" << "\n";
                cout << "'e': exponentiation" << "\n\n";
            }
        }
        
        cout << "Not in the supported format." << "\n";
        cout << "Type '{name_of_the_executable} h' to know best." << "\n";

        return 0;
    }

    long long hash = stringToHash(argv[1]);
    int value1{stoi(argv[2])};
    int value2{stoi(argv[3])};
    int result;
    bool has_result{true};

    switch(hash) {
        case ADDITION:
            result = value1 + value2;
            break;
        case SUBTRACTION:
            result = value1 - value2;
            break;
        case MULTIPLICATION:
            result = value1 * value2;
            break;
        case DIVISION:
            result = value1 / value2;
            break;
        case EXPONENCIATION:
            result = pow(value1, value2);
            break;
        default:
            has_result = false;
    }

    if (has_result) {
        cout << "The result you want is " << result << "\n";
    }
    else {
        cout << "The operation that you ask is not supported yet!" << "\n";
    }

    return 0;
}