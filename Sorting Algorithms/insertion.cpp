#include <iostream>
using namespace std;


void insertionSort( int A[] , int n){
    for (int i = 1; i<n; i++){
        int temp = A[i];
        int j=i-1;   // this points to the lastly sorted elements. 
        //  since when i = 2 in the iteration 1 one element will already be sorted  and j = i-1 so it will be 1 so it will point to the 2nd index of the array 
        while ( j >=0 && temp < A[j])    // compare temp with the right element in that particular index of i 
        {
            A[j+1] = A[j];
            j--;  // sorted part tira ghatdei jaanxa but j ko value >= 0 samma matra jaanxa
        }
        A[j+1]=temp;
    }
    for (int i = 0; i<n; i++){
        cout << A[i] <<" "; 
    }
    cout << endl;
}

int main(){
    int n;
    cout << "Enter n: " << endl ; 
    cin >> n; 
    int A[n];
    for (int i = 0 ; i<n; i++){
        cin >> A[i];
    }
    insertionSort(A , n);

    return 0;
}

// #include <iostream>
// using namespace std;
 
// void insertionSort(int A[] , int n){
//     int i , j , temp;
//     for (i = 1; i < n ; i++){
//         j = i - 1;
//         temp = A[i];
//         while( j >= 0  &&  temp < A[j])
//         {
//             A[j+1] = A[j];
//             j--;
//         } 
//         A[j+1] = temp;
//     }
//     for(i = 0 ; i < 6 ; i++){
//         cout << A[i] << "  ";
//     }
// }

// int main() {
//     int A[6] = {4,5,6,1,2,3};
//     int n = 6;
//     insertionSort(A, n);
//     return 0;
// } 