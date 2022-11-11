#include <iostream>
#include <string>
using namespace std;
class student{
    private:
        string name;
        string rollno;
        string Department;
    public:
        void read() {
            cout << "Enter your name\n";
            getline(cin, this->name);
            cout << "Enter your roll no\n";
            getline(cin, this-> rollno);
            cout << "Enter your department\n";
            getline(cin, this->Department);
        };
        void display(){
            cout << "Name: " << name << "\nRoll no:" << rollno << "\nDepartment: "<< Department << endl;
        };
};
int main(){
    student student1, student2, student3, student4, student5;
    cout << "Enter details of Student 1: ";
    student1.read();
    cout << "Enter details of Student 2: ";
    student2.read();
    cout << "Enter details of Student 3: ";
    student3.read();
    cout << "Enter details of Student 4: ";
    student4.read();
    cout << "Enter details of Student 5: ";
    student5.read();
    cout << "Details of Student 1 are: ";
    student1.display();
    cout << "Details of Student 2 are: ";
    student2.display();
    cout << "Details of Student 3 are: ";
    student3.display();
    cout << "Detalis of Studnet 4 are: ";
    student4.display();
    cout << "Details of Studnet 5 are: ";
    student5.display();
    return 0;
}