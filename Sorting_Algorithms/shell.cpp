#include <iostream>
using namespace std;

void shellSort(int A[] , int n){
    int gap;
    for( gap = n/2 ; gap > 0 ; gap/=2){
        for(int j = gap ; j < n ; j++){
            for( int i = j - gap ; i >= 0 ; i -= gap){
                if(A[i+gap] > A[i]){
                    break;
                }
                else{
                    int temp = A[i];
                    A[i] = A[i+gap];
                    A[i+gap] = temp;
                }
            }
        }
    }
    cout << " After sorting is " << endl;
    for (int i = 0; i < n; i ++){
        cout << A[i]<< "  " ;
    }
    cout << endl;
}


int main(){
    int A[] = {4545, 55 , 0 , 1 , 4 , 6 , 90};
    int size = sizeof(A)/sizeof(A[0]);
    shellSort(A , size);
    return 0;
}