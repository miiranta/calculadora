#include <iostream>
#include <cctype>
#include <string>
#include <cmath>

#define ADDITION 9700
#define SUBTRACTION 11500
#define MULTIPLICATION 10900
#define DIVISION 10000
#define EXPONENCIATION 10100
#define ROOT 11400

using namespace std;

long long stringToHash(string a){
    long long add = 0;
    for(int i = 0; i < a.size() ;i++){
        add = a[i] + add;
        add = add*100;
    }
    return add;
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


float calculate(string command, float value1 = 0, float value2 = 0) {

    long long hash = stringToHash(command);
    float result;
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
        case ROOT:
            result = pow(value2, 1/value1);
            break;
        default:
            has_result = false;
    }

    if (has_result) {
        return result;
    }
    else {
        cout << "The operation that you ask is not supported yet!" << "\n";
    }

    return 0;
}


int trimComponents(int componentsLen, string *components){
    int j = 0, k = 0, blanckSpaces = 0;

    do{
        blanckSpaces = 0;
        for(j = 0; j < componentsLen; j++){
            if(components[j] == " "){
                blanckSpaces = 1;
                for(k = 0; k < componentsLen-j; k++){
                    components[j+k] = components[j+1+k]; 
                }   
            }
        }
    }while(blanckSpaces == 1);
        
}


int removeExtraParenthesis(int componentsLen, string *components){
    int j = 0, k = 0, exist = 0;

    do{
        exist = 0;
        for(j = 0; j < componentsLen; j++){
            if(components[j] == ")"){
                exist = 1;
                for(k = 0; k < componentsLen-j; k++){
                    components[j+k] = components[j+1+k]; 
                }   
            }
        }
    }while(exist == 1);
        
}


float calculateParenthesis(int componentsLen, int pStart, int pEnd, string *components){

    int j = 0, k = 0;
    float res = 0;

    //DONT unite these loops
    for(j = pStart+1; j < pEnd; j++){
        if(components[j] == "e"||components[j] == "r"){
            res = calculate(components[j], stof(components[j-1]), stof(components[j+1]));  
            components[j-1] = to_string(res);
            components[j] = " ";
            components[j+1] = " ";
            trimComponents(componentsLen ,components);
            j = pStart+1, res = 0, pEnd = pEnd-3;
        }
    }

    for(j = pStart+1; j < pEnd; j++){
        if(components[j] == "m"||components[j] == "d"){
            res = calculate(components[j], stof(components[j-1]), stof(components[j+1]));  
            components[j-1] = to_string(res);
            components[j] = " ";
            components[j+1] = " ";
            trimComponents(componentsLen ,components);
            j = pStart+1, res = 0, pEnd = pEnd-3;
        }
    }

    for(j = pStart+1; j < pEnd; j++){
        if(components[j] == "a"||components[j] == "s"){
            res = calculate(components[j], stof(components[j-1]), stof(components[j+1]));  
            components[j-1] = to_string(res);
            components[j] = " ";
            components[j+1] = " ";
            trimComponents(componentsLen ,components);
            j = pStart+1, res = 0, pEnd = pEnd-3;
        }
    }

}


bool isParam(string line){
    if(line == ""){return 0;}
    char* p;
    strtol(line.c_str(), &p, 10);
    return *p == 0;
}


bool isNotParam(string line){
    if(line == ""){return 1;}
    if(line == "("){return 1;}
    if(line == ")"){return 1;}
    char* p;
    strtol(line.c_str(), &p, 10);
    return *p == 0;
}
