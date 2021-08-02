#include <iostream>
#include <string>
#include "handler.hpp"
using namespace std;

int getHelp();

int main(){

    string expression;
    float res = 0;

    //Instructions
    getHelp();

    //TURN ON DEBUG? 
    int debug = 0;

    //TURN ON LOOP?
    int loop = 1;

    do{

        //Get string
        cout << "\n\n\n"<< "Type expression: " << endl << " ";
        getline(cin, expression);
        
        try{
            res = parseExpression(expression, debug);
        }catch(...){
            cout << "\nError! Wrong syntax."; continue;
        }
        
        cout << "Response: ";
        cout << res;

    }while(loop == 1);
        
}

int getHelp(){
        cout << "\n" << "To use the calculator, please type in the terminal an expression using the following syntax: " << "\n\n";

        cout << "Operation may be:" << "\n";
        cout << "'+': addition" << "\n";
        cout << "'-': subtraction" << "\n";
        cout << "'x': multiplication" << "\n";
        cout << "'/': division" << "\n";
        cout << "'^': exponentiation" << "\n";
        cout << "'r': root (index r radicand)" << "\n";
        cout << "'n': negative number" << "\n";
        cout << "'()': give priority" << "\n\n";

    return 0;
}


