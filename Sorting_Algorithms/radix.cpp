#include <iostream>
using namespace std;


void countSort(int A[] , int n , int place);

int getMax(int A[] , int n){
    int i;
    int max = A[0];
    for (i =0 ; i < n ; i++){
        if(A[i] > max ){
            max = A[i];
        }
    }
    return max;
}

void radixSort(int A[] , int n){
    int max = getMax(A , n);
    for (int place = 1 ; max/place > 0 ; place*=10){
        countSort(A , n , place);
    }
}

void countSort(int A[] , int n , int place){
    int digit, i; 
    int output[n];
    int count[10] = {0};

    // To store the digit counts 
    for (i = 0; i < n; i++){
        digit = (A[i]/place)%10;
        count[digit]++;
    }

    // Sum_counts or comulative count

    for ( i = 1 ; i < 10 ; i ++){
        count[i]+=count[i-1];
    }


    // To fill the output after LSB 1 or 2 or 3 -------- and so on traversly

    for( i = n-1 ; i >= 0; i-- ){
        digit = (A[i]/place)%10;
        output[count[digit]-1] = A[i];
        count[digit]--;
    }


    //  To copy the array of output to the main array 

    for(i = 0; i < n ; i++){
        A[i] = output[i];
    }
}

int main(){
    int A[]={5,3,7,4,5,5,2,4,6};
    int n = ( sizeof(A) / sizeof(A[0]));
    cout << "The sorted array  is ! \n";
    radixSort(A , n);
    for (int i=0; i<n; i++){
        cout << A[i] << "   " ;
    }
    cout << endl;
    return 0;
}