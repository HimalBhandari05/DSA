#include <iostream>
using namespace std;

void swap(float a , float b){
    float temp;
    temp = a ;
    a = b ; 
    b = temp;
}

void selectionSort(int A[] , int n)
{
    int i , j , least , pos;
    for (i = 0; i < n-1; i++){
        least = A[i];
        pos = i;
        for (j=i+1; j<n; j++){
            if(A[j] < least){
                least = A[j];
                pos = j;
            }
        }
        if(i!=pos){
            swap(A[i] , A[pos]);
        }
    }
    for (i = 0; i<n; i++){
        cout << A[i] << "   " ;
    }
    cout << endl;
}

int main(){
    int A[10],size;
    cout<< "Enter 10 elements in the array one by one to sort !: " << endl;
    for (int i=0; i<10; i++){
        cin >> A[i];
    }
    cout << "Before sorting ! : \n";
    for (int i = 0; i<10 ; i++){
        cout<< i+1 << " is " << A[i] << "  "<<endl; 
    }
    cout << endl;

    size = sizeof(A)/sizeof(A[0]);

    cout << "After sorting is" << endl;
    selectionSort(A , size);
}

