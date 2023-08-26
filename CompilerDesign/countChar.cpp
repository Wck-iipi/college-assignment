#include <iostream>
#include <string>
#include <vector>

int main(){
    int characters, words, spaces = 0;
    int lines = 1;
    
    std::string originalString;

    std::cout << "Enter the string" << std::endl;
    std::getline(std::cin, originalString);

    characters = originalString.length();
    for (int i = 0; i < characters; i++) {
        if (originalString[i] == ' ') {
            spaces++;
            
            if (originalString[i-1] != ' ' && i != 0) {
                words++;
            }
        }
        if (originalString[i] == '.') {
            lines++;
        }
    }

    std::cout << "Characters: " << characters << std::endl;
    std::cout << "Words: " << words << std::endl;
    std::cout << "Spaces: " << spaces << std::endl;
    std::cout << "Lines: " << lines << std::endl;

    return 0;
}
