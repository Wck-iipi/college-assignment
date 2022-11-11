#include <iostream>
#include <fstream>

using namespace std;

int main(){
	string source1text;
	string source2text;
	ifstream MyReadFile1("Source 1.txt");
	getline(MyReadFile1, source1text);
    MyReadFile1.close();

	ifstream MyReadFile2("Source 2.txt");
	getline(MyReadFile2, source2text);
	MyReadFile2.close();

    cout << source1text;
	return 0;
}
