#include <iostream>
using namespace std;
int binarySearch(int arr[],int n, int key){
    int s = 0, e=n;
    while(s<=e){
        int mid = (s/2)+(e/2);
        if(arr[mid]==key)
            return mid;
        else if(arr[mid]>key)
            e = mid;
        else
            s = mid;
    }
    return -1;
}
int main(){
    int n,key;
    cout<<"Enter the size of the array ";
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    cout<<"Enter what you want to be searched. ";
    cin>>key;
    cout<<"The index of what you searched is (starting with 0) :" << binarySearch(arr,n,key);
    return 0;
}