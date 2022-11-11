#include <iostream>
using namespace std;
class student{
    public :
    int age ;
    void getinfo(){
        cout<<"Enter the age of student ";
        cin>>age;
    }
    
};
void func(student a){
        int nage = a.age  + 1;
        cout<<nage;
}
int main(){
    student a;
    a.getinfo();
    cout << "Age after one year is :";
    func(a);
    return 0;
}
