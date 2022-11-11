#include <iostream>
#include<string>
using namespace std;
  
int vowelCount(char *Strptr)
{
    int count = 0; 
    cout << "Following are the vowels in the code :\n";
    while ((*Strptr) != '\0') {
        if (*Strptr == 'a' || *Strptr == 'e' || *Strptr == 'i'
            || *Strptr == 'o' || *Strptr == 'u') {
            count++;
            cout<<*Strptr<<endl;
        }
        Strptr++;
    }
    return count;
}
int main()
{
    cout << "Input the string you want to see vowels of:\n";
    char str[100];
        cin>>str;
    int vowelCountNumber = vowelCount(str);
    cout << "Vowels in above string are :\n" << vowelCountNumber;
  
    return 0;
}