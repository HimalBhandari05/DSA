// to implement avl tree in C

#include <stdio.h>
#include <stdlib.h>

int Partition(int A[], int l, int r)
{
    int x = l;
    int y = r;
    int pivot = A[l];
    while (x < y)
    {
        while (A[x] <= pivot && x <= r)
        {
            x++;
        }
        while (A[y] > pivot && y >= l)
        {
            y--;
        }
        if (x < y)
        {
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

void display(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d  ", A[i]);
    }
    printf("\n");
}


void QuickSort(int A[], int l, int r)
{
    if (l < r)
    {
        int P = Partition(A, l, r);
        QuickSort(A, l, P - 1); // p is already sorted
        QuickSort(A, P + 1, r);
    }
}

struct avlTree
{
    int data;
    struct avlTree *left;
    struct avlTree *right;
    struct avlTree *parent;
};

struct avlTree *insertNode(struct avlTree *root, int data);
struct avlTree *createNode(int data)
{
    struct avlTree *newNode = (struct avlTree *)malloc(sizeof(struct avlTree));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    return newNode;
}