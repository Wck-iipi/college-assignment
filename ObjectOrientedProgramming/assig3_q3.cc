 #include <iostream>
 #include <cstdlib>
 using namespace std;
 struct complex{
    float real;
    float img;
 };
 void complexAddition(struct complex a, struct complex b){
    struct complex sum;
      sum.real = a.real + b.real ;
    sum.img = a.img + b.img ;
    cout<<sum.real<<" +"<<" i"<<sum.img;


 }
 void complexSubtraction(struct complex a, struct complex b){
    struct complex dif;
      dif.real = a.real -  b.real ;
    dif.img = a.img - b.img ;

    if(dif.img > 0)
      cout<<dif.real<<" + "<<"i"<<abs(dif.img);
    else
      cout << dif.real << " - " <<"i" << abs(dif.img);
 }

 int main(){
    struct complex a, b;
    cout<<"Enter the value of real and img part of first num   ";
    cin>>a.real>>a.img;
    cout<<"Enter the value of real and img part of second num  ";
    cin>>b.real>>b.img;

    complexAddition(a,b);
    cout<<endl;
    complexSubtraction(a,b);
     return 0;
 }