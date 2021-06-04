#include <iostream>
#include <cctype>
#include <string>

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
                cout << "'a': adition" << "\n";
                cout << "'s': subtraction" << "\n";
                cout << "'m': multiplication" << "\n";
                cout << "'d': division" << "\n\n";
            }
        }
        
        cout << "Not in the supported format." << "\n";
        cout << "Type '{name_of_the_executable} h' to know best." << "\n";

        return 0;
    }

    char operation{tolower(argv[1][0])};
    int value1{stoi(argv[2])};
    int value2{stoi(argv[3])};
    int result;
    bool has_result{true};

    switch(operation) {
        case 'a':
            result = value1 + value2;
            break;
        case 's':
            result = value1 - value2;
            break;
        case 'm':
            result = value1 * value2;
            break;
        case 'd':
            result = value1 / value2;
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