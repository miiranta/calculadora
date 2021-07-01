#include <iostream>
#include <cctype>
#include <string>
#include <cmath>

using namespace std;

long long stringToHash(string a){

    long long add = 0;

    for(int i = 0; i < a.size() ;i++){
        add = a[i] + add;
        add = add*100;
    }

    return add;

}