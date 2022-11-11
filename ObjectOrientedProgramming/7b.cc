#include <iostream>
using namespace std;
class DM {   
 public:
    double meter;
    void getdata() {
        cout<< "Enter distance in meters and centimeters :";
        cin>> meter; }
    friend void add();
} a1;
class DB {   
 public:
    double inch;
    void getdata() {
        cout<< "Enter distance in feets and inches :";
        cin>> inch; }
    friend void add();
} a2;
void add() {   
    double a, res;
    a = a1.meter*39.37;
    res = a+a2.inch;
    cout<< "Total inches = " << res <<endl;
    a = a2.inch/39.37;
    res = a+a1.meter;
    cout<< "Total meters = " << res;
} 
int main() {
    a1.getdata();
    a2.getdata();
    add();
    return 0;
}

