#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};


struct Node* createNode(int value)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


struct Node* insert(struct Node *root, int value)
{
    if(root == NULL)
        return createNode(value);

    if(value < root->data)
        root->left = insert(root->left, value);

    else if(value > root->data)
        root->right = insert(root->right, value);

    return root;
}


struct Node* search(struct Node *root, int key)
{
    if(root == NULL || root->data == key)
        return root;

    if(key < root->data)
        return search(root->left, key);

    return search(root->right, key);
}


struct Node* findMin(struct Node *root)
{
    while(root->left != NULL)
        root = root->left;

    return root;
}


struct Node* deleteNode(struct Node *root, int key)
{
    if(root == NULL)
        return NULL;

    if(key < root->data)
    {
        root->left = deleteNode(root->left, key);
    }
    else if(key > root->data)
    {
        root->right = deleteNode(root->right, key);
    }
    else
    {

        if(root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

   
        else if(root->left == NULL)
        {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL)
        {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }


        struct Node *temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}


void inorder(struct Node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}


void preorder(struct Node *root)
{
    if(root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}


void postorder(struct Node *root)
{
    if(root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{
    struct Node *root = NULL;
    int choice, value;

    do
    {
        printf("\n\n===== BST MENU =====");
        printf("\n1. Insert Node");
        printf("\n2. Delete Node");
        printf("\n3. Search Node");
        printf("\n4. Inorder Traversal");
        printf("\n5. Preorder Traversal");
        printf("\n6. Postorder Traversal");
        printf("\n7. Exit");

        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);

                root = insert(root, value);

                printf("Node Inserted Successfully");
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);

                root = deleteNode(root, value);

                printf("Node Deleted Successfully");
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);

                if(search(root, value))
                    printf("Node Found");
                else
                    printf("Node Not Found");

                break;

            case 4:
                printf("Inorder Traversal: ");
                inorder(root);
                break;

            case 5:
                printf("Preorder Traversal: ");
                preorder(root);
                break;

            case 6:
                printf("Postorder Traversal: ");
                postorder(root);
                break;

            case 7:
                printf("Program Ended");
                break;

            default:
                printf("Invalid Choice");
        }

    } while(choice != 7);

    return 0;
}