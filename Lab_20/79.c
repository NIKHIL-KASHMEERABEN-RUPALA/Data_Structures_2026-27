#include <stdio.h>
#include <stdlib.h>

/* Color Encoding Constants */
#define RED 0
#define BLACK 1

/*
    Red-Black Tree Node Structure
    Key, Color status (RED/BLACK) ane Left, Right, Parent Pointers store kare che.
*/
struct node
{
    int key;
    int color; // RED (0) athva BLACK (1)

    struct node *left;
    struct node *right;
    struct node *parent;
};


/*
    Helper Function: New Red-Black Tree Node mate Memory Allocate ane Initialize karva.
*/
struct node *newNode(int key)
{
    struct node *tempNode;

    // Structure size pramane dynamic memory allocation
    tempNode = (struct node *)malloc(sizeof(struct node));

    tempNode->key = key;

    /* Golden Rule: Navu inserted node ALWAYS initial state ma RED (0) j hoy che */
    tempNode->color = 0;

    tempNode->left = NULL;
    tempNode->right = NULL;
    tempNode->parent = NULL;

    return tempNode;
}


/*
    Left Rotation Function
    
    'rightChild' (y) ne UP pull kare che, ane 'rotatedNode' (x) ne Left side DOWN push kare che.
*/
struct node *leftRotate(struct node *root, struct node *rotatedNode)
{
    struct node *rightChild;

    rightChild = rotatedNode->right;

    /* Step 1: rightChild na left subtree ne rotatedNode na right child tarife reassign karo */
    rotatedNode->right = rightChild->left;

    if (rightChild->left != NULL)
        rightChild->left->parent = rotatedNode;

    /* Step 2: rightChild ne rotatedNode na original parent sathe connect karo */
    rightChild->parent = rotatedNode->parent;

    if (rotatedNode->parent == NULL)
    {
        /* Jo rotatedNode Root hoto, to rightChild new Root banse */
        root = rightChild;
    }
    else if (rotatedNode == rotatedNode->parent->left)
    {
        rotatedNode->parent->left = rightChild;
    }
    else
    {
        rotatedNode->parent->right = rightChild;
    }

    /* Step 3: rotatedNode ne rightChild na left child tarife attach karo */
    rightChild->left = rotatedNode;
    rotatedNode->parent = rightChild;

    return root;
}


/*
    Right Rotation Function
    
    'leftChild' (y) ne UP pull kare che, ane 'rotatedNode' (x) ne Right side DOWN push kare che.
*/
struct node *rightRotate(struct node *root, struct node *rotatedNode)
{
    struct node *leftChild;

    leftChild = rotatedNode->left;

    /* Step 1: leftChild na right subtree ne rotatedNode na left child tarife reassign karo */
    rotatedNode->left = leftChild->right;

    if (leftChild->right != NULL)
        leftChild->right->parent = rotatedNode;

    /* Step 2: leftChild ne rotatedNode na original parent sathe connect karo */
    leftChild->parent = rotatedNode->parent;

    if (rotatedNode->parent == NULL)
    {
        /* Jo rotatedNode Root hoto, to leftChild new Root banse */
        root = leftChild;
    }
    else if (rotatedNode == rotatedNode->parent->right)
    {
        rotatedNode->parent->right = leftChild;
    }
    else
    {
        rotatedNode->parent->left = leftChild;
    }

    /* Step 3: rotatedNode ne leftChild na right child tarife attach karo */
    leftChild->right = rotatedNode;
    rotatedNode->parent = leftChild;

    return root;
}


/*
    Fix Insertion Function
    
    Standard BST insertion pachi thaye-la Red-Red violations ne Recoloring 
    ane Rotations dwara repair/fix kare che.
*/
struct node *fixInsertion(struct node *root, struct node *currentNode)
{
    struct node *parentNode;
    struct node *grandParentNode;
    struct node *uncleNode;

    /*
        Loop chalase jya sudhi Parent RED hoy.
        RED parent + RED currentNode = Red-Red Violation!
    */
    while (currentNode != root &&
           currentNode->parent != NULL &&
           currentNode->parent->color == 0)
    {
        parentNode = currentNode->parent;
        grandParentNode = parentNode->parent;

        /*
            --------------------------------------------------------
            GROUP A: Parent Grandparent no LEFT child che
            --------------------------------------------------------
        */
        if (parentNode == grandParentNode->left)
        {
            uncleNode = grandParentNode->right;

            /*
                CASE 1: Uncle RED (0) che.
                Solution: Simply Recoloring karo!
            */
            if (uncleNode != NULL && uncleNode->color == 0)
            {
                parentNode->color = 1;
                uncleNode->color = 1;
                grandParentNode->color = 0;

                // Problem pointer ne Grandparent par move karo higher levels check karva
                currentNode = grandParentNode;
            }
            else
            {
                /*
                    CASE 2: Triangle Configuration (currentNode RIGHT child che)
                    Solution: Parent par Left Rotate kari Case 3 (Line shape) ma convert karo
                */
                if (currentNode == parentNode->right)
                {
                    currentNode = parentNode;
                    root = leftRotate(root, currentNode);

                    // Rotation pachi pointer references re-assign karo
                    parentNode = currentNode->parent;
                    grandParentNode = parentNode->parent;
                }

                /*
                    CASE 3: Line Configuration (currentNode LEFT child che)
                    Solution: Parent & Grandparent nu Recoloring karo, ane Grandparent par Right Rotate karo
                */
                parentNode->color = 1;
                grandParentNode->color = 0;

                root = rightRotate(root, grandParentNode);
            }
        }

        /*
            --------------------------------------------------------
            GROUP B (MIRROR): Parent Grandparent no RIGHT child che
            --------------------------------------------------------
        */
        else
        {
            uncleNode = grandParentNode->left;

            /*
                CASE 1 (MIRROR): Uncle RED (0) che.
                Solution: Simply Recoloring process execution!
            */
            if (uncleNode != NULL && uncleNode->color == 0)
            {
                parentNode->color = 1;
                uncleNode->color = 1;
                grandParentNode->color = 0;

                currentNode = grandParentNode;
            }
            else
            {
                /*
                    CASE 2 (MIRROR): Triangle Configuration (currentNode LEFT child che)
                    Solution: Parent par Right Rotate kari Case 3 (Line shape) ma convert karo
                */
                if (currentNode == parentNode->left)
                {
                    currentNode = parentNode;
                    root = rightRotate(root, currentNode);

                    // Rotation pachi pointer references re-assign karo
                    parentNode = currentNode->parent;
                    grandParentNode = parentNode->parent;
                }

                /*
                    CASE 3 (MIRROR): Line Configuration (currentNode RIGHT child che)
                    Solution: Parent & Grandparent nu Recoloring karo, ane Grandparent par Left Rotate karo
                */
                parentNode->color = 1;
                grandParentNode->color = 0;

                root = leftRotate(root, grandParentNode);
            }
        }
    }

    /* Golden Rule: Root Node hamesha BLACK (1) j hovo joie */
    root->color = 1;

    return root;
}


/*
    Insert Function
    
    Standard Binary Search Tree logic thi key insert kare che,
    pachi Red-Black Tree properties fix kare che.
*/
struct node *insert(struct node *root, int key)
{
    struct node *tempTraversal;
    struct node *parentNode;
    struct node *insertedNode;

    // New node create karo
    insertedNode = newNode(key);

    /* Case: Empty Tree */
    if (root == NULL)
    {
        insertedNode->color = BLACK; // Root mandatory BLACK hovo joie
        return insertedNode;
    }

    /* Standard Binary Search Tree Placement */
    tempTraversal = root;
    parentNode = NULL;

    while (tempTraversal != NULL)
    {
        parentNode = tempTraversal;

        if (key < tempTraversal->key)
            tempTraversal = tempTraversal->left;

        else if (key > tempTraversal->key)
            tempTraversal = tempTraversal->right;

        else
        {
            /* Duplicate Keys Red-Black Tree ma allowed nathi */
            free(insertedNode);
            return root;
        }
    }

    /* Parent ane Child Pointers connect karo */
    insertedNode->parent = parentNode;

    if (key < parentNode->key)
        parentNode->left = insertedNode;
    else
        parentNode->right = insertedNode;

    /* Red-Red Violations fix karo ane updated Root return karo */
    root = fixInsertion(root, insertedNode);

    return root;
}


/*
    Inorder Traversal Function
    
    Tree elements ne sorted order ma Color code sathe print kare che:
    R = RED, B = BLACK
*/
void inorder(struct node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);

    printf("%d(%s) ",
           root->key,
           root->color == RED ? "R" : "B");

    inorder(root->right);
}


int main()
{
    struct node *root = NULL;

    /* Insertion Test Sequence */
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 15);
    root = insert(root, 25);
    root = insert(root, 5);
    root = insert(root, 12);
    root = insert(root, 35);
    root = insert(root, 40);
    root = insert(root, 32);
    root = insert(root, 50);

    printf("Inorder Traversal (Key with Color):\n");
    inorder(root);
    printf("\n");

    return 0;
}
