#include <iostream>
#include <cmath>
using namespace std;

void merge(int A[], int l, int m, int r) {
    int temp[100];
    int left = l;
    int right = m + 1;
    int k = 0;

    while (left <= m && right <= r) {
        if (A[left] < A[right]) {
            temp[k] = A[left];
            k++;
            left++;
        } else {
            temp[k] = A[right];
            k++;
            right++;
        }
    }

    for (; left <= m; k++, left++) {
        temp[k] = A[left];
    }   

    for (; right <= r; k++, right++) {
        temp[k] = A[right];
    }

    for (int i = 0; i < k; i++) {
        A[l+i] = temp[i];
    }
}

void mergeSort(int A[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(A, l, m);
        mergeSort(A, m + 1, r);
        merge(A, l, m, r);
    }
}

int main() {
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
    mergeSort(array, 0, last);

    cout << "The array after sorting is:\n";
    for (int i = 0; i < arr_len; i++) {
        cout << array[i] << "  ";
    }
    cout << endl;
}
