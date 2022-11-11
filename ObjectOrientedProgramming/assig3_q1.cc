#include <iostream>
#include <iomanip>
using namespace std;
int** read_sq_mat(int order);  
void  display_mat(int** ,int); 
void diag_sum (int** , int);    
int main(){
    int order;
    cout << "Write the order of the matrix : " << endl;
    cin >> order ;  
    int** squareMatrix = read_sq_mat(order);  
    display_mat(squareMatrix,order);         
    diag_sum(squareMatrix,order);            
    return 0;
}
int** read_sq_mat(int order){
    int** matrix = new int*[order];   
    for (int k =0 ; k < order ; k++){   
        *(matrix+k) = new int[order];
    }
    for (int g =0 ; g < order ; g++){  

            for (int h =0 ; h < order ; h++){
                    cout << "ENTER (" << (g+1) << ")(" << (h+1) << ") ELEMENT :";
                    cin >> *(*(matrix+h) + g);

            }
    }
    return matrix;
}

void  display_mat(int** mat , int order){  
    cout << "\n_____MATRIX_____"<< endl;
    for (int g =0 ; g < order ; g++){  
            for (int h =0 ; h < order ; h++){
                    cout << setw(4)<< *(*(mat +h) + g)<<" ";
            }
                cout << endl;
    }
}

void diag_sum (int** mat, int order){
    int sum =0 ;
    while(order--){
        sum += *(*(mat+order)+order);
        
    }
    cout << "\nTHE SUM OF DIAGNOL ELEMENTS: " << sum;

}