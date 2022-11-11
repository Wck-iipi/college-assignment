#include<iostream>
using namespace std;

class Student {
    public:
        int publicInteger = 15;    
    private:
        int privateInteger = 20;
    protected:
        int protectedInteger = 25;
};

class inheritedStudent : Student {
    public:
        int getProtectedVariable( inheritedStudent& ss){
            return ss.protectedInteger;
        }
};

int main(){

    Student s1;
    cout << "Public integer can be accessed below.\n";
    cout << s1.publicInteger << endl;

    inheritedStudent s2;
    cout << "The protected variable can be accessed as below.\n";
    cout << s2.getProtectedVariable(s2) << endl;

    cout << "Private variable can't be accessed at all.";
    return 0;
}
