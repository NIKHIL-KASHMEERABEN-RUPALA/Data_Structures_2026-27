#include <stdio.h>
#include <stdlib.h>

/* Color Encoding Constants */
#define RED 0
#define BLACK 1

/*
    Red-Black Tree Node Structure
*/
struct node
{
    int key;
    int color; // RED (0) or BLACK (1)

    struct node *left;
    struct node *right;
    struct node *parent;
};


/*
    Helper Function: Allocate and initialize a new Red-Black Tree node
*/
struct node *newNode(int key)
{
    struct node *tempNode;

    tempNode = (struct node *)malloc(sizeof(struct node));

    tempNode->key = key;

    /* Golden Rule: Newly inserted node is ALWAYS RED (0) initially */
    tempNode->color = 0;

    tempNode->left = NULL;
    tempNode->right = NULL;
    tempNode->parent = NULL;

    return tempNode;
}


/*
    Left Rotation Function
    
    Pulls 'y' (right child) UP, and pushes 'rotatedNode' DOWN to the left.
*/
struct node *leftRotate(struct node *root, struct node *rotatedNode)
{
    struct node *rightChild;

    rightChild = rotatedNode->right;

    /* Step 1: Reassign rightChild's left subtree to rotatedNode's right */
    rotatedNode->right = rightChild->left;

    if (rightChild->left != NULL)
        rightChild->left->parent = rotatedNode;

    /* Step 2: Connect rightChild to rotatedNode's parent */
    rightChild->parent = rotatedNode->parent;

    if (rotatedNode->parent == NULL)
    {
        /* If rotatedNode was Root, rightChild becomes the new Root */
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

    /* Step 3: Put rotatedNode as rightChild's left child */
    rightChild->left = rotatedNode;
    rotatedNode->parent = rightChild;

    return root;
}


/*
    Right Rotation Function
    
    Pulls 'leftChild' UP, and pushes 'rotatedNode' DOWN to the right.
*/
struct node *rightRotate(struct node *root, struct node *rotatedNode)
{
    struct node *leftChild;

    leftChild = rotatedNode->left;

    /* Step 1: Reassign leftChild's right subtree to rotatedNode's left */
    rotatedNode->left = leftChild->right;

    if (leftChild->right != NULL)
        leftChild->right->parent = rotatedNode;

    /* Step 2: Connect leftChild to rotatedNode's parent */
    leftChild->parent = rotatedNode->parent;

    if (rotatedNode->parent == NULL)
    {
        /* If rotatedNode was Root, leftChild becomes the new Root */
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

    /* Step 3: Put rotatedNode as leftChild's right child */
    leftChild->right = rotatedNode;
    rotatedNode->parent = leftChild;

    return root;
}


/*
    Fix Insertion Function
    
    Fixes Red-Red violations after standard BST insertion using 
    Recoloring and Rotations.
*/
struct node *fixInsertion(struct node *root, struct node *currentNode)
{
    struct node *parentNode;
    struct node *grandParentNode;
    struct node *uncleNode;

    /*
        Loop runs as long as parent is RED.
        RED parent + RED currentNode = Red-Red Violation!
    */
    while (currentNode != root &&
           currentNode->parent != NULL &&
           currentNode->parent->color == RED)
    {
        parentNode = currentNode->parent;
        grandParentNode = parentNode->parent;

        /*
            --------------------------------------------------------
            GROUP A: Parent is the LEFT child of Grandparent
            --------------------------------------------------------
        */
        if (parentNode == grandParentNode->left)
        {
            uncleNode = grandParentNode->right;

            /*
                CASE 1: Uncle is RED
                Solution: Just Recolor!
            */
            if (uncleNode != NULL && uncleNode->color == RED)
            {
                parentNode->color = BLACK;
                uncleNode->color = BLACK;
                grandParentNode->color = RED;

                // Move problem pointer up to Grandparent to check higher levels
                currentNode = grandParentNode;
            }
            else
            {
                /*
                    CASE 2: Triangle Configuration (currentNode is RIGHT child)
                    Solution: Left Rotate Parent to convert into Case 3 (Line shape)
                */
                if (currentNode == parentNode->right)
                {
                    currentNode = parentNode;
                    root = leftRotate(root, currentNode);

                    // Re-assign pointer references after rotation
                    parentNode = currentNode->parent;
                    grandParentNode = parentNode->parent;
                }

                /*
                    CASE 3: Line Configuration (currentNode is LEFT child)
                    Solution: Recolor Parent & Grandparent, then Right Rotate Grandparent
                */
                parentNode->color = BLACK;
                grandParentNode->color = RED;

                root = rightRotate(root, grandParentNode);
            }
        }

        /*
            --------------------------------------------------------
            GROUP B (MIRROR): Parent is the RIGHT child of Grandparent
            --------------------------------------------------------
        */
        else
        {
            uncleNode = grandParentNode->left;

            /*
                CASE 1 (MIRROR): Uncle is RED
                Solution: Just Recolor!
            */
            if (uncleNode != NULL && uncleNode->color == RED)
            {
                parentNode->color = BLACK;
                uncleNode->color = BLACK;
                grandParentNode->color = RED;

                currentNode = grandParentNode;
            }
            else
            {
                /*
                    CASE 2 (MIRROR): Triangle Configuration (currentNode is LEFT child)
                    Solution: Right Rotate Parent to convert into Case 3 (Line shape)
                */
                if (currentNode == parentNode->left)
                {
                    currentNode = parentNode;
                    root = rightRotate(root, currentNode);

                    // Re-assign pointer references after rotation
                    parentNode = currentNode->parent;
                    grandParentNode = parentNode->parent;
                }

                /*
                    CASE 3 (MIRROR): Line Configuration (currentNode is RIGHT child)
                    Solution: Recolor Parent & Grandparent, then Left Rotate Grandparent
                */
                parentNode->color = BLACK;
                grandParentNode->color = RED;

                root = leftRotate(root, grandParentNode);
            }
        }
    }

    /* Golden Rule: The Root Node must ALWAYS be BLACK (1) */
    root->color = BLACK;

    return root;
}


/*
    Insert Function
    
    Inserts a key using standard Binary Search Tree logic,
    then repairs any Red-Black Tree rule violations.
*/
struct node *insert(struct node *root, int key)
{
    struct node *tempTraversal;
    struct node *parentNode;
    struct node *insertedNode;

    // Create the new node
    insertedNode = newNode(key);

    /* Case: Empty Tree */
    if (root == NULL)
    {
        insertedNode->color = BLACK; // Root must be BLACK
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
            /* Duplicate Keys are NOT allowed in Red-Black Tree */
            free(insertedNode);
            return root;
        }
    }

    /* Connect Parent and Child Pointers */
    insertedNode->parent = parentNode;

    if (key < parentNode->key)
        parentNode->left = insertedNode;
    else
        parentNode->right = insertedNode;

    /* Fix Red-Red Violations and return updated Root */
    root = fixInsertion(root, insertedNode);

    return root;
}


/*
    Inorder Traversal Function
    
    Prints tree elements in sorted order with color code:
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
