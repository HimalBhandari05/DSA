#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 200000

int Partition(int A[], int l, int r)
{
    int x = l, y = r;
    int pivot = A[l];
    while (x < y)
    {
        while (A[x] <= pivot && x <= r)
            x++;
        while (A[y] > pivot && y >= l)
            y--;
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

void QuickSort(int A[], int l, int r)
{
    if (l < r)
    {
        int P = Partition(A, l, r);
        QuickSort(A, l, P - 1);
        QuickSort(A, P + 1, r);
    }
}

void display(int A[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d  ", A[i]);
    printf("\n");
}
struct AVLTree
{
    int data;
    struct AVLTree *left;
    struct AVLTree *right;
    struct AVLTree *parent;
    int height;
};

struct AVLTree *root = NULL;

struct AVLTree *create_node(int value)
{
    struct AVLTree *NewNode = (struct AVLTree *)malloc(sizeof(struct AVLTree));
    NewNode->data = value;
    NewNode->left = NewNode->right = NewNode->parent = NULL;
    NewNode->height = 1;
    return NewNode;
}

int getHeight(struct AVLTree *node)
{
    if (node != NULL)
    {
        return node->height;
    }
    else
    {
        return 0;
    }
}

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int checkBalance(struct AVLTree *node)
{
    if (node != NULL)
    {
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        int balanceFactor = leftHeight - rightHeight;
        return balanceFactor;
    }
    else
    {
        return 0;
    }
}

struct AVLTree *rightRotate(struct AVLTree *y)
{
    struct AVLTree *x = y->left;
    struct AVLTree *T2 = x->right;
    x->right = y;
    y->left = T2;
    // to update the height
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    return x;
}

struct AVLTree *leftRotate(struct AVLTree *x)
{
    struct AVLTree *y = x->right;
    struct AVLTree *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;
    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    return y;
}

struct AVLTree *insert(struct AVLTree *root, int data)
{
    if (!root)
        return create_node(data);
    if (data < root->data)
    {
        root->left = insert(root->left, data);
        root->left->parent = root;
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
        root->right->parent = root;
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = checkBalance(root);

    if (balance > 1 && data < root->left->data) // left - left case so rotate right (left tira data tankeko xa )
        return rightRotate(root);
    if (balance > 1 && data > root->left->data) // left right case / \ case xa first left rotate ani right rotate
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && data > root->right->data) // right right case -> solution rotate left 
        return leftRotate(root);
    if (balance < -1 && data < root->right->data) // right left case -> rotate right then left 
    {
        root->right = rightRotate(root->right); 
        return leftRotate(root);
    }

    return root;
}

struct AVLTree *search(struct AVLTree *root, int key)
{
    if (!root || root->data == key)
        return root;
    return (key < root->data) ? search(root->left, key) : search(root->right, key);
}

struct AVLTree *findMin(struct AVLTree *root)
{
    while (root->left)
        root = root->left;
    return root;
}
struct AVLTree *findMax(struct AVLTree *root)
{
    while (root->right)
        root = root->right;
    return root;
}

struct AVLTree *delete_node(struct AVLTree *root, int value)
{
    if (!root)
        return root;
    if (value < root->data)
    {
        root->left = delete_node(root->left, value);
        if (root->left)
            root->left->parent = root;
    }
    else if (value > root->data)
    {
        root->right = delete_node(root->right, value);
        if (root->right)
            root->right->parent = root;
    }
    else
    {
        if (!root->left)
        {
            struct AVLTree *temp = root->right;
            if (temp)
                temp->parent = root->parent;
            free(root);
            return temp;
        }
        else if (!root->right)
        {
            struct AVLTree *temp = root->left;
            if (temp)
                temp->parent = root->parent;
            free(root);
            return temp;
        }

        struct AVLTree *temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
        if (root->right)
            root->right->parent = root;
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = checkBalance(root);
    if (balance > 1 && checkBalance(root->left) >= 0)
        return rightRotate(root);
    if (balance > 1 && checkBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && checkBalance(root->right) <= 0)
        return leftRotate(root);
    if (balance < -1 && checkBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void inorder(struct AVLTree *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
void preorder(struct AVLTree *root)
{
    if (root)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct AVLTree *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    int choice, value, n;
    int *A;
    struct AVLTree *temp;
    srand(time(0));

    do
    {
        printf("1. Insert\n2. Delete\n3. Search\n4. Inorder\n5. Preorder\n6. Postorder\n");
        printf("7. Find Max\n8. Find Min\n9. Create\n10. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            printf("%d inserted successfully\n", value);
            break;

        case 2:
            printf("Enter element to delete: ");
            scanf("%d", &value);
            temp = search(root, value);
            if (temp)
            {
                root = delete_node(root, value);
                printf("%d deleted successfully\n", value);
            }
            else
                printf("%d not found in tree\n", value);
            break;

        case 3:
            printf("Enter element to search: ");
            scanf("%d", &value);
            temp = search(root, value);
            if (temp)
                printf("%d found\n", value);
            else
                printf("%d not found\n", value);
            break;

        case 4:
            printf("Inorder traversal: ");
            inorder(root);
            printf("\n");
            break;

        case 5:
            printf("Preorder traversal: ");
            preorder(root);
            printf("\n");
            break;

        case 6:
            printf("Postorder traversal: ");
            postorder(root);
            printf("\n");
            break;

        case 7:
            temp = findMax(root);
            if (temp)
                printf("Max value is: %d\n", temp->data);
            break;

        case 8:
            temp = findMin(root);
            if (temp)
                printf("Min value is: %d\n", temp->data);
            break;

        case 9:
            printf("Enter number of elements to create: ");
            scanf("%d", &n);
            A = (int *)malloc(sizeof(int) * n);
            for (int i = 0; i < n; i++)
                A[i] = rand() % 1000;
            printf("Random array:\n");
            display(A, n);
            QuickSort(A, 0, n - 1);
            printf("Sorted array:\n");
            display(A, n);
            for (int i = 0; i < n; i++)
                root = insert(root, A[i]);
            free(A);
            printf("Tree created successfully!\n");
            break;

        case 10:
            printf("Exited!\n");
            break;
        }
    } while (choice != 10);

    return 0;
}
