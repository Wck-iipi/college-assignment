#include <iostream>
using namespace std;
class student{
    public :
    static int num ;
    static void counter(){
        num+=1;
    }
    static void getdata(){
        cout<<num<<endl;

        
    }
    
};
int student :: num;
int main(){
    student a ;
    student::counter();
    student::getdata();
    

    
    return 0;
}
