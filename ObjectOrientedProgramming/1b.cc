#include <iostream>
#include <ctype.h>
using namespace std;

int main(){
    bool isVowel = true;
    char inputCharacter;
    while(isVowel){
        cin >> inputCharacter;
        inputCharacter = tolower(inputCharacter);
        switch (inputCharacter) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                break;
            default:
                isVowel = false;
                break;
        }       
    }
    cout <<"Program ended";
    return 0;
}