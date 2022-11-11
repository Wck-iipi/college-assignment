#include <iostream>
using namespace std;
int main(){
    int rows, columns, a[100][100], b[100][100], sum[100][100], i, j;

    cout << "Enter number of rows (between 1 and 100): ";
    cin >> rows;

    cout << "Enter number of columns (between 1 and 100): ";
    cin >> columns;

    cout << endl << "Enter elements of 1st matrix: " << endl;

    // First matrix element input
    for(i = 0; i < rows; ++i)
       for(j = 0; j < columns; ++j)
       {
           cout << "Enter element a" << i + 1 << j + 1 << " : ";
           cin >> a[i][j];
       }

    // Second matrix element input
    cout << endl << "Enter elements of 2nd matrix: " << endl;
    for(i = 0; i < rows; ++i)
       for(j = 0; j < columns; ++j)
       {
           cout << "Enter element b" << i + 1 << j + 1 << " : ";
           cin >> b[i][j];
       }

    // Adding Two matrices
    for(i = 0; i < rows; ++i)
        for(j = 0; j < columns; ++j)
            sum[i][j] = a[i][j] + b[i][j];

    // Displaying the resultant sum matrix.
    cout << endl << "Sum of two matrix is: " << endl;
    for(i = 0; i < rows; ++i)
        for(j = 0; j < columns; ++j)
        {
            cout << sum[i][j] << "  ";
            if(j == columns - 1)
                cout << endl;
        }

    return 0;
}