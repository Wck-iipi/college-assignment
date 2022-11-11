#include<iostream>
using namespace std;
int alwaysTrue = true;
inline int getCubicValue(int a){  
    static int c = a;
    switch(alwaysTrue){
        case true:
            return c * c * c;
        default:
            return 22;
    }
return 22;
}
inline int getMultiplicationValues(int a, int b){
    static int c = a, d = b;
    switch(alwaysTrue){
        case true:
            return  c * d;
    }
    return 22;
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
