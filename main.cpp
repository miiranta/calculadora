#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
#include <string.h>
#include <cstring>
#include <cmath>
#include "functions.hpp"

using namespace std;

int main(){

    //TURN ON DEBUG? 
    int debug = 0;

    //Vars
    char buffer[1000], expressionFilter[1000];
    string expression;
    string components[1000];
    int space = 0, i = 0, j = 0, k = 0, bufferLen = 0, componentsLen = 0, moreParenthesisAhead = 0, pStart = 0, pEnd = 0;

    //Instructions
    getHelp();

    //Get string
    cout << "Type expression: " << endl << " ";
    getline(cin, expression);
    int stringLen = expression.length();


    //Space formatting
    space = 0;
    for (j =0; j < stringLen; j++){
        switch (expression[j])
        {
        case '(':
            expressionFilter[j + space + 1] = '(';
            expressionFilter[j + space] = ' ';
            expressionFilter[j + space + 2] = ' ';
            space = space + 2;
            break;
        case ')':
            expressionFilter[j + space + 1] = ')';
            expressionFilter[j + space] = ' ';
            expressionFilter[j + space + 2] = ' ';
            space = space + 2;
            break;
        case '+':
            expressionFilter[j + space + 1] = 'a';
            expressionFilter[j + space] = ' ';
            expressionFilter[j + space + 2] = ' ';
            space = space + 2;
            break;
        case '-':
            expressionFilter[j + space + 1] = 's';
            expressionFilter[j + space] = ' ';
            expressionFilter[j + space + 2] = ' ';
            space = space + 2;
            break;
        case 'x':
            expressionFilter[j + space + 1] = 'm';
            expressionFilter[j + space] = ' ';
            expressionFilter[j + space + 2] = ' ';
            space = space + 2;
            break;
        case '/':
            expressionFilter[j + space + 1] = 'd';
            expressionFilter[j + space] = ' ';
            expressionFilter[j + space + 2] = ' ';
            space = space + 2;
            break;
        case '^':
            expressionFilter[j + space + 1] = 'e';
            expressionFilter[j + space] = ' ';
            expressionFilter[j + space + 2] = ' ';
            space = space + 2;
            break;
        case 'r':
            expressionFilter[j + space + 1] = 'r';
            expressionFilter[j + space] = ' ';
            expressionFilter[j + space + 2] = ' ';
            space = space + 2;
            break;
        case 'n':
            expressionFilter[j + space + 1] = 'n';
            expressionFilter[j + space] = ' ';
            expressionFilter[j + space + 2] = ' ';
            space = space + 2;
            break;
        default:
            expressionFilter[j + space] = expression[j];
        }
    }


    //Remove unnecessary spaces
    k = 0;
    for(j = 0; j<stringLen+space; j++ ){
        if(expressionFilter[j-1] == ' '){
            if(expressionFilter[j] == ' '){
                continue;
            }
        }
        buffer[k] = expressionFilter[j];
        k++;
        bufferLen = k;
    }
    buffer[bufferLen] = '\0';


    //Cut string in components (array of strings)
    istringstream ss(buffer);
    string del;
    fflush(stdin);
    k = 0;
    while(getline(ss, del, ' ')) {
        components[k] = del; 
        k++;
        componentsLen = k;
    }


    //Little filters - DONT unite these loops
    //Apply n
    for(j = 0; j < componentsLen; j++){
        if(components[j] == "n"){
            components[j] = " ";
            if(!isParam(components[j+1])){cout << "Error! Wrong syntax."; return 0;}
            int swap = stof(components[j+1]);
            swap = swap * (-1);
            components[j+1] = to_string(swap);
            trimComponents(componentsLen ,components);
        }
    }
    //Verify 2 2 ...
    for(j = 0; j < componentsLen; j++){
         if(isParam(components[j])){
            if(isParam(components[j+1])){
                cout << "Error! Wrong syntax."; 
                return 0;
            }
        }
    }
    //Verify ++ -- ...
    for(j = 0; j < componentsLen; j++){
         if(!isNotParam(components[j])){
            if(!isNotParam(components[j+1])){
                cout << "Error! Wrong syntax."; 
                return 0;
            }
        }
    }
    

    //Print
    for(j = 0; j < componentsLen && debug == 1; j++){
        cout << components[j] << " ";
    }


    //Search for parenthesis
    for(j = 0; j < componentsLen; j++){
        if(components[j] == "("){

            //Is there a parenthesis with higher priority?
            moreParenthesisAhead = 0;
            for(k=j+1; k<stringLen; k++){
                if(components[k] == "("){
                    moreParenthesisAhead = 1;
                }
            }

            pStart = 0;
            pEnd = 0;
            //NO
            if(moreParenthesisAhead == 0){
                pStart = j;
                for(k = pStart + 1; k<stringLen+1; k++){
                    if(components[k] == ")"){
                        pEnd = k;
                        break;
                    }
                }

                if(pEnd == 0){cout << "Error! Your expression is missing a )."; return 0;}

                components[pStart] = " ";
                components[pEnd] = " ";
                calculateParenthesis(componentsLen, pStart, pEnd, components);
                
                //Print
                if(debug == 1){cout << "\n";}
                for(j = 0; j < componentsLen && debug == 1; j++){
                    cout << components[j] << " ";
                }

                j=0;
                continue;

            }
        }
    }


    //Last step
    calculateParenthesis(componentsLen, 0, componentsLen, components);
    removeExtraParenthesis(componentsLen ,components);
    trimComponents(componentsLen ,components);           
    if(components[0] == ""){components[0] = components[1];} // bug fix


    cout << "\nResponse: ";
    cout << components[0];
    
    


}

