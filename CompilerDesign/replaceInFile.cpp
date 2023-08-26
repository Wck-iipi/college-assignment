#include <iostream>
#include <string>
#include <fstream>

int main(){
    std::string originalString;
    std::string wantedString;
    std::string replaceString;

    std::cout << "Enter the string you want to find" << std::endl;
    std::cin >> wantedString;

    std::cout << "What do you want to replace this with" << std::endl;
    std::cin >> replaceString;

    std::string newString;
    int substringCount = 0;

    std::ifstream fin("fileWhereTextIsReplaced.txt");
    while(getline(fin, originalString)) {
        for (int i = 0; i < originalString.length() ; i++) {
            if (originalString.substr(i, wantedString.length()) == wantedString){
                newString += replaceString;
                i += wantedString.length() - 1;
            }else {
                newString += originalString[i];
            }
        }
        std::ofstream fout("new.txt");
        fout << newString << std::endl;
    }
}
