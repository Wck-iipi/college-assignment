#include <iostream>
#include <ctype.h>
using namespace std;

int main(){
    int year = 1800;
    while(year <=2000){
        bool isLeapYear = false;
        if (year % 400 == 0)
            isLeapYear = true;

        else if (year % 100 == 0)
            isLeapYear = false;

        else if (year % 4 == 0)
            isLeapYear = true;
        
        if(isLeapYear)
            cout << year << ",";
        year++; 
    }       
    return 0;
}