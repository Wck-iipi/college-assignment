#include <iostream>
using namespace std;
template <class T>
int LinearSearch(T arr[], int n, T x) {
	for (int i = 0; i < n; ++i) {
		if (arr[i] == x)
			return i;
	}
	return -1;
}

int main() {
	int arr[] = {6, 43, 23, 6, 12 , 43, 3, 4, 2, 6};
	int n, index, x;
	n = sizeof(arr) / sizeof(int); 
	cout << "Integer Array: ";
	for (int i = 0; i < n; ++i)	cout << arr[i] << ' ';
	cout << endl;
	cout << "Enter Value you want to search: ";
	cin >> x;
	index = LinearSearch(arr, n, x);
	if (index != -1)
		cout << x << " is present in the array at position " << index << endl;
	else
		cout << x << " is not present in the array \n" << endl;
		
    return 0;
}
