#include <iostream>
using namespace std;

int Partition(int A[] , int l , int r ){
    int x = l;
    int y = r;
    int pivot = A[l];
    while(x<y){
        while(A[x] <= pivot && x <= r){
            x++;
        }
        while(A[y] > pivot){
            y--;
        }
        if(x<y){
            int temp = A[x];
            A[x] = A[y];
            A[y] = temp;
        }
    }
    int temp = A[l];
    A[l] = A[y];
    A[y] = temp;

    return y;
}



void QuickSort(int A[] , int l , int r){
    if(l < r ){
        int P = Partition(A , l , r);
        QuickSort(A , l , P-1);
        QuickSort(A , P+1, r);
    }
}

int main(){
    int n;
    cout << "Enter the total number of elements! " << endl;
    cin >> n;

    int array[100];
    cout << "Enter the number to be sorted ! " << endl;
    int arr_len = n;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    cout << "The array before sorting is:\n";
    for (int i = 0; i < arr_len; i++) {
        cout << array[i] << "  ";
    }
    cout << endl;
    int last = arr_len - 1;
    QuickSort(array , 0 , last);

    cout << "The array after sorting is:\n";
    for (int i = 0; i < arr_len; i++) {
        cout << array[i] << "  ";
    }
    cout << endl;

    return 0;
}