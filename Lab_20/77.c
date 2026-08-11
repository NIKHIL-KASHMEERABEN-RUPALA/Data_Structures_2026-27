#include <stdio.h>
#include <stdlib.h>

/* Binary Tree Node nu Structure defined che
   Tree na individual node mate key and pointers store kare che */
struct node
{
    int key;
    struct node *left;
    struct node *right;
};


/* New node dynamically allocate and initialize karva mate nu Function */
struct node *newNode(int key)
{
    struct node *temp;

    // Memory allocation size of structure pramane
    temp = (struct node *)malloc(sizeof(struct node));

    temp->key = key;
    temp->left = NULL;   // Initially left child NULL set karyu
    temp->right = NULL;  // Initially right child NULL set karyu

    return temp;
}


/* Be subtrees mirror images che ke nahi e recursively check karva mate nu Function */
int isMirror(struct node *left, struct node *right)
{
    /* Condition 1: Banne nodes NULL hoi -> Binary Tree Symmetric che */
    if (left == NULL && right == NULL)
        return 1;

    /* Condition 2: Ek node NULL hoi ane biju non-NULL hoi -> Symmetric nathi */
    if (left == NULL || right == NULL)
        return 0;

    /* Condition 3: Current Node keys match thavi joie
       ane opposite Subtrees (left-right & right-left) Mirror images hova joie */
    return (left->key == right->key) &&
           isMirror(left->left, right->right) &&
           isMirror(left->right, right->left);
}


/* Entire Binary Tree Symmetric che ke nahi e verify karva mate nu main Function */
int isSymmetric(struct node *root)
{
    /* Base Case: Empty tree hamesha Symmetric ganay */
    if (root == NULL)
        return 1;

    // Root na Left ane Right subtrees ni Mirror symmetry check karo
    return isMirror(root->left, root->right);
}


int main()
{
    struct node *root;

    /*
         Tree Structure Representation:
                 8
               /   \
              5     5
             / \   / \
            3   6 6   3
    */
   
    // Root node creation
    root = newNode(8);

    // Level 1 Nodes creation
    root->left = newNode(5);
    root->right = newNode(5);

    // Level 2 Left Subtree Nodes
    root->left->left = newNode(3);
    root->left->right = newNode(6);

    // Level 2 Right Subtree Nodes (Mirror configuration)
    root->right->left = newNode(6);
    root->right->right = newNode(3);


    // Symmetry validation result check ane output print
    if (isSymmetric(root))
        printf("Given tree is symmetric");
    else
        printf("Given tree is not symmetric");

    return 0;
}