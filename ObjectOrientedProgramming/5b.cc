#include<iostream>
using namespace std;

inline int getCubicValue(int a){
    return a * a * a;
}

inline int getMultiplicationValues(int a, int b){
    return a * b;
}

int main(){
    
    int a, b;
    cout << "Enter the number you want to see cube of \n";
    cin >> a;
    cout << "The cube of the number you enter is :" << getCubicValue(a) << endl;
    
    cout << "Enter the two numbers you want to see multiplied:\n";
    cin >> a >> b;
    cout << "The multiplication of numbers is:" << getMultiplicationValues(a, b);

    return 0;
}
