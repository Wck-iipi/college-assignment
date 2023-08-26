#include <iostream>
#include <string>

int main(){
    std::string originalString;
    std::string wantedString;

    std::cout << "Enter the string" << std::endl;
    std::cin >> originalString;

    std::cout << "Enter the string you want to find" << std::endl;
    std::cin >> wantedString;

    int substringCount = 0;
    for (int i = 0; i < originalString.length() ; i++) {
        if (originalString.substr(i, wantedString.length()) == wantedString){
            substringCount++;
        }
    }

    std::cout << substringCount;
}
