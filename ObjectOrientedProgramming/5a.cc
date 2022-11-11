#include <iostream>
using namespace std;

void swapValues(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

int main(){
    int a,b;
    cout << "Enter the the numbers you want swapped.";
    cin >> a >> b ;
    swapValues(a, b);
    cout << a << b;
    return 0;
}
