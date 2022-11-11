#include <iostream>
using namespace std;
class bank_account{
    private:
        string name;
        long account_number;
        string type;
        int balance;
    public:
        void read(){
            cout << "Enter the name: ";
            cin >> this->name;
            cout << "Enter your account number: ";
            cin >> this->account_number;
            cout << "Enter the type of your account: ";
            cin >> this->type;
            this->balance = 0;
        }
        void deposit(int balance){
            this->balance += balance;
            cout << "Cash Deposited Successfully" << endl;
        }
        void withdrawn(int cash){
            if (cash <= this->balance){
                this->balance -= cash;
                cout << "Money successfully Withdrawn" << endl;
            }
            else{
                cout << "Not enough balance" << endl;
            }
        }
        int getAvailableBalance(){
                return this->balance;
        }
};
int main(){
    bank_account cus1, cus2, cus3, cus4, cus5;
    cout << "Enter the details of first customer" << endl;
    cus1.read();
    cout << "Enter the details of second customer" << endl;
    cus2.read();
    cout << "Enter the details of third customer" << endl;
    cus3.read();
    cout << "Enter the details of forth customer" << endl;
    cus4.read();
    cout << "Enter the details of fifth customer" << endl;
    cus5.read();

    cus1.deposit(1000);
    cus1.withdrawn(52);
    cout << cus1.getAvailableBalance() << endl;
    cus2.deposit(30);
    cus2.withdrawn(100);
    cout << cus2.getAvailableBalance() << endl;

    return 0;
}