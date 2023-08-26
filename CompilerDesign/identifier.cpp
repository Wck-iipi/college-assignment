#include <iostream>
#include <string>
#include <vector>

bool isInArray(char c, std::vector<char> arr) {
    for (int i = 0; i < sizeof(arr); i++) {
        if (c == arr[i]) {
            return true;
        }
    }
    return false;
}

int main() {
    std::vector<char> operators = {'+', '-', '*', '/'};
    std::string originalString;

    std::cout << "Enter the string" << std::endl;
    std::cin >> originalString;

    std::vector<char> identifiers;

    for (int i = 0; i < originalString.length(); i++) {
        if (originalString[i] != ' ' && !(isInArray(originalString.at(i), operators))) {
            identifiers.push_back(originalString[i]);
        }
    }
    for (int i = 0; i < identifiers.size(); i++) {
        std::cout << identifiers[i] << std::endl;
    }
}
