#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 200000

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
        QuickSort(A, l, P - 1);
        QuickSort(A, P + 1, r);
    }
}

struct binaryTree
{
    int data;
    struct binaryTree *left;
    struct binaryTree *right;
    struct binaryTree *parent;
};

struct binaryTree *root = NULL;

struct binaryTree *createNode(int data)
{
    struct binaryTree *newNode = (struct binaryTree *)malloc(sizeof(struct binaryTree));
    newNode->data = data;
    newNode->right = NULL;
    newNode->left = NULL;
    newNode->parent = NULL;
    return newNode;
}

void preorder(struct binaryTree *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct binaryTree *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(struct binaryTree *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

struct binaryTree *insertNode(struct binaryTree *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
        root->left->parent = root;
    }
    if (data > root->data)
    {
        root->right = insertNode(root->right, data);
        root->right->parent = root;
    }
    return root;
}

struct binaryTree *searchNode(struct binaryTree *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }
    else
    {
        if (data < root->data)
        {
            return searchNode(root->left, data);
        }
        else
        {
            return searchNode(root->right, data);
        }
    }
}

struct binaryTree *findMax(struct binaryTree *root)
{
    while (root->right != NULL)
        root = root->right;
    return root;
}

struct binaryTree *findMin(struct binaryTree *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct binaryTree *deleteNode(struct binaryTree *root, int data)
{
    if (root == NULL)
        return root;

    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else
    {
        if (root->left == NULL)
        {
            struct binaryTree *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct binaryTree *temp = root->left;
            free(root);
            return temp;
        }
        struct binaryTree *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main()
{
    int choice, value;
    int A[MAX], i, n;

    printf("Enter n: \n");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        A[i] = rand() % 1000;
    }

    display(A, n);
    QuickSort(A, 0, n - 1);
    printf("Data after sorting: \n");
    display(A, n);

    for (i = 0; i < n; i++)
        root = insertNode(root, A[i]);

    do
    {
        printf("1. Insert\n2. FindMax\n3. FindMin\n4. Search\n5. Delete\n");
        printf("6. Inorder\n7. Preorder\n8. Postorder\n9. Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted: \n");
            scanf("%d", &value);
            root = insertNode(root, value);
            printf("%d inserted successfully\n", value);
            break;

        case 2:
        {
            struct binaryTree *maxNode = findMax(root);
            if (maxNode)
                printf("Max value is: %d\n", maxNode->data);
            else
                printf("Tree is empty.\n");
            break;
        }

        case 3:
        {
            struct binaryTree *minNode = findMin(root);
            if (minNode)
                printf("Min value is: %d\n", minNode->data);
            else
                printf("Tree is empty.\n");
            break;
        }

        case 4:
            printf("Enter the value to be searched: \n");
            scanf("%d", &value);
            if (searchNode(root, value))
                printf("%d found\n", value);
            else
                printf("%d not found\n", value);
            break;

        case 5:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            if (searchNode(root, value))
            {
                root = deleteNode(root, value);
                printf("%d deleted successfully.\n", value);
            }
            else
                printf("%d not found in tree.\n", value);
            break;
            
        case 6:
            printf("Inorder traversal: ");
            inorder(root);
            printf("\n");
            break;
            
        case 7:
            printf("Preorder traversal: ");
            preorder(root);
            printf("\n");
            break;
            
        case 8:
            printf("Postorder traversal: ");
            postorder(root);
            printf("\n");
            break;

        case 9:
            printf("Exited\n");
            exit(0);
        }
    } while (choice != 9);

    return 0;
}