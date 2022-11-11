#include <ctype.h>
#include <iostream>
using namespace std;

int main() {
    char inputCharacter;
    cout << "Enter the character.\n";
    cin >> inputCharacter;
    inputCharacter = tolower(inputCharacter);
    switch (inputCharacter) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            cout << "You have entered a vowel";
            break;
        default:
            cout << "You have entered a consonant";
            break;
    }
    return 0;
}
