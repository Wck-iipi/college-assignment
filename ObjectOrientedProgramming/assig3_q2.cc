  #include <iostream>
  using namespace std;
  int main(){
    int n, *p;
    cout<<"Enter the no of elements : ";
    cin>>n;
    int arr[n];
    for( int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    p = arr;
     int m ;
     cout<<"Enter value of m : ";
     cin>>m;
    
    for(int i = m-1; i>=0; i--){
        cout<<*(p+i)<<endl;
    }
      
    return 0;
  }