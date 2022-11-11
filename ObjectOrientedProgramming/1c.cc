#include <iostream>
using namespace std;
int main(){
    int inputNumber;
    int positiveNumber = 0;
    int negativeNumber = 0;
    int zeroes = 0;
    while (true) {
        cin >> inputNumber;
        if(inputNumber > 0){
            positiveNumber++;
        }else if(inputNumber<0){
            negativeNumber++;
            if(inputNumber == -1){
                break;
            }  
        }else{
            zeroes++;
        }
    }
    cout << "You have entered " << zeroes << " zeroes, " 
         << positiveNumber << " positive Numbers and "
         << negativeNumber << " negative Numbers";

    return 0;
}