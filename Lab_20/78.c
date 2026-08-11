#include <stdio.h>
#include <stdlib.h>

/* Binary Tree Node nu Structure definition
   aa structure node key ane left/right pointers store kare che */
struct node
{
    int key;
    struct node *left;
    struct node *right;
};


/* Dynamic memory allocation dwara new node create karva mate nu Function */
struct node *newNode(int key)
{
    struct node *temp;

    // Memory allocate karo using malloc
    temp = (struct node *)malloc(sizeof(struct node));

    temp->key = key;
    temp->left = NULL;   // Left pointer NULL set karyu
    temp->right = NULL;  // Right pointer NULL set karyu

    return temp;
}


/*
    Tree ni height calculate karva ane balance check karva mate nu Recursive Function.
    Jo Tree Height-Balanced na hoi, to -1 return kare che immediately.
*/
int checkHeight(struct node *root)
{
    int leftHeight;
    int rightHeight;

    /* Base Case: Empty Tree ni height hamesha 0 hoi */
    if (root == NULL)
        return 0;


    /* Left Subtree ni height recursively calculate karo */
    leftHeight = checkHeight(root->left);

    /* Jo Left Subtree already unbalanced hoi (-1 flag), to immediate -1 return karo */
    if (leftHeight == -1)
        return -1;


    /* Right Subtree ni height recursively calculate karo */
    rightHeight = checkHeight(root->right);

    /* Jo Right Subtree already unbalanced hoi (-1 flag), to immediate -1 return karo */
    if (rightHeight == -1)
        return -1;


    /*
        Balance Condition Check:
        Left ane Right subtrees ni height no absolute difference 1 thi vadharay na hovo joie.
    */
    if (abs(leftHeight - rightHeight) > 1)
        return -1;


    /*
        Current node ni height calculation = 1 + Maximum of (leftHeight, rightHeight)
    */
    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}


/* Complete Tree height-balanced che ke nahi e check karva mate nu Helper Function */
int isBalanced(struct node *root)
{
    // Jo checkHeight -1 return na kare, to tree balanced che (Returns 1 for TRUE, 0 for FALSE)
    return checkHeight(root) != -1;
}


int main()
{
    struct node *root;

    /*
         Tree Structure Representation:
                 3
                / \
               9   20
                  /  \
                 15   7
    */

    // Root node creation
    root = newNode(3);

    // Level 1 Nodes creation
    root->left = newNode(9);
    root->right = newNode(20);

    // Level 2 Right Subtree Nodes creation
    root->right->left = newNode(15);
    root->right->right = newNode(7);


    // Height balance check and output printing
    if (isBalanced(root))
        printf("TRUE");
    else
        printf("FALSE");

    return 0;
}