#include <iostream>
using namespace std;
class coordinate {
 private:
    double x, y, z;
 public:
    void operator++ () {
        this-> x = ++this->x;
        this-> y = ++this->y;
        this-> z = ++this->z;
    }
    void operator-- () {
        this-> x = --this->x;
        this-> y = --this->y;
        this-> z = --this->z;
    }
    void operator+= (coordinate B) {
        this-> x += B.x;
        this-> y += B.y;
        this-> z += B.z;
    }
    bool operator== (coordinate B){
        if (this->x == B.x && this->y == B.y && this->z == B.z) {
            return true;
        } else{
            return false;
        }
    }
    void displayValues(){
        cout << "(" << this->x << "," << this->y <<"," << this->z <<")" << endl;
    }
    coordinate(double x, double y, double z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
};
int main() {
    class coordinate A(2, 3, 4);
    class coordinate B(1, 1, 1);
    class coordinate C(3, 4, 5);
    ++A;
    A.displayValues();
    --A;
    A.displayValues();
    A+=B;
    A.displayValues();
    cout << (A == B) << endl;
    cout << (A == C) << endl;
    return 0;
}
