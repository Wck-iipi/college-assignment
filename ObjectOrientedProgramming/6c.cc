#include <iostream>
#include <string>
using namespace std;
class student {
    public:
    int age ;
    string name ;
    student (){
        cout<<"Enter the age :";
        cin>>age ;
    }
    student(string s){
        name = s;
    }
    void getname(){ cout<<"Name is :"<<name<<endl; }
    void getage() { cout<<"Age is :"<<age<<endl; }
    student (student &a){
        name  = a.name;
   }
};
int main(){
    student a1;
    string n;
    cout<<"Enter the name ";
    cin>>n;
    student a(n);
    cout<<"info of student  "<<endl;
    a.getname();
    a1.getage();
    student c = a;
    c.getname();
    return 0;
}
