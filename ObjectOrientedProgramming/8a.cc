#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
vector<string> split(string str){
    vector<string> splitVector;
    int j = 0;
    for (size_t i = 0; i < str.size(); i++) {
        if(str[i] == ','){
            splitVector.push_back(str.substr(j,(i-j)));
            j = i+1;
        }
    } return splitVector; 
}
vector<int> convertToInt(vector<string> splitArray){
    vector<int> finalVector;
    for (size_t i = 0; i < splitArray.size(); i++) {
        string str = splitArray.at(i);
        int toBeAdded = stoi(str);
        finalVector.push_back(toBeAdded);
    } return finalVector;
}
vector<int> sortVector(vector<int> arr1, vector<int> arr2){
    vector<int> sortedArray;
    int totalLength = arr1.size() + arr2.size();
    int i = 0;
    int j = 0;
    while (i<arr1.size() && j<arr2.size()) {
        if(arr1.at(i) <= arr2.at(j)){
            sortedArray.push_back(arr1.at(i)); i++;
        }else{
            sortedArray.push_back(arr2.at(j)); j++;    
        }
    }
    while(i < arr1.size()){
        sortedArray.push_back(arr1.at(i)); i++;
    }
    while(j < arr2.size()){
        sortedArray.push_back(arr2.at(j)); j++;
    }
    return sortedArray; }
int main(){
    string source1text, source2text;
	ifstream MyReadFile1("Source 1.txt");
	getline(MyReadFile1, source1text);
    MyReadFile1.close();
	ifstream MyReadFile2("Source 2.txt");
	getline(MyReadFile2, source2text);
	MyReadFile2.close();
    vector<string> splitArray = split(source1text);
    vector<int> intArraySource1 = convertToInt(splitArray);
    vector<string> splitArray1 = split(source2text);
    vector<int> intArraySource2 = convertToInt(splitArray1);
    vector<int> finalVector = sortVector(intArraySource1, intArraySource2);
    for (size_t i = 0; i < finalVector.size(); i++) {
        cout << finalVector[i] << endl;
    }
    return 0;
}
