//
// Benedikt Lüken-Winkels, 1138844
//


#include <iostream>
#include <vector>
#include <string>
#include "Nat.h"

// Member functions definitions including constructor
Nat::Nat(int n){
    base = 1337;
    toBaseX(n);
}

Nat::Nat(){
    base = 1337;
}

int Nat::getBase() {
    return base;
}

void Nat::toBaseX(int n) {
    int rest = n;
    while (rest > 0){
        valueBaseX.push_back(rest % base);
        rest = rest / base;
    }

}

//x * 2^n
Nat Nat::shift(Nat x, int n){

    Nat result = x;

    for (int i = 0; i < n ; i++){
        result = add( result , result);
    }

    return result;

}

Nat Nat::add(Nat x, Nat y){
    Nat result;
    int rest = 0;

    if(x.valueBaseX.size() >= y.valueBaseX.size()){

        for (int n = 0 ; n <= x.valueBaseX.size(); n++){
            if(n == x.valueBaseX.size()){
                result.valueBaseX.push_back(rest);
            }
            else if(n >= y.valueBaseX.size()){
                if(x.valueBaseX.at(n) + rest >= result.base) {
                    result.valueBaseX.push_back((x.valueBaseX.at(n) + rest) / result.getBase());
                    rest = (x.valueBaseX.at(n) + rest) % result.getBase();
                }
                else{
                    result.valueBaseX.push_back(x.valueBaseX.at(n) + rest);
                }
            }
            else{
                if(x.valueBaseX.at(n) + y.valueBaseX.at(n) + rest >= result.base) {
                    result.valueBaseX.push_back((x.valueBaseX.at(n) + y.valueBaseX.at(n) + rest) / result.getBase());
                    rest = (x.valueBaseX.at(n) + y.valueBaseX.at(n) + rest) % result.getBase();
                }
                else{
                    result.valueBaseX.push_back(x.valueBaseX.at(n) + rest + y.valueBaseX.at(n));
                }
            }
        }

    } else{

        for (int n = 0 ; n <= y.valueBaseX.size(); n++){
            if(n == y.valueBaseX.size()){
                result.valueBaseX.push_back(rest);
            }
            else if(n >= x.valueBaseX.size()){
                if(y.valueBaseX.at(n) + rest >= result.base) {
                    result.valueBaseX.push_back((y.valueBaseX.at(n) + rest) / result.getBase());
                    rest = (y.valueBaseX.at(n) + rest) % result.getBase();
                }
                else{
                    result.valueBaseX.push_back(y.valueBaseX.at(n) + rest);
                }
            }
            else{
                if(x.valueBaseX.at(n) + y.valueBaseX.at(n) + rest >= result.base) {
                    result.valueBaseX.push_back((x.valueBaseX.at(n) + y.valueBaseX.at(n) + rest) / result.getBase());
                    rest = (x.valueBaseX.at(n) + y.valueBaseX.at(n) + rest) % result.getBase();
                }
                else{
                    result.valueBaseX.push_back(x.valueBaseX.at(n) + rest + y.valueBaseX.at(n));
                }
            }
        }
    }

    return result;


}

string Nat::toString() {
    string result = "( ";
    for (int n = valueBaseX.size(); n > 0; n--){
        result += to_string(valueBaseX.at(n-1)) + " ";
    }
    return result += ")";
}


// Main program
int main(){
    int input = 20000;
    Nat number(input), a(1337), b(133800), one(1);
    cout << to_string(input)<< " = " << number.toString() << " in Basis 1337\n";
    cout << a.toString() << " + " << b.toString() << " = " << Nat::add(a, b).toString() << "\n";
    cout << "1234567890 * 2^100 + 1 = " << Nat::add(Nat::shift(1234567890, 100), one).toString() << "\n";
    cout << "1337 * 2^4 = " << Nat::shift(a, 4).toString() << "\n";
    return 0;

}