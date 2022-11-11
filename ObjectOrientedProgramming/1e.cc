#include <iostream>
using namespace std;
int main()
{
    int n = 5;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << (char)('A' + j - 1) << " ";
        }
        cout << endl;
    }

    for (int i = 5; i >0; i--) {
        for (int j = 1; j <= i; j++) {
            cout << (char)('A' + j - 1) << " ";
        }
        cout << endl;
    }
    return 0;
}