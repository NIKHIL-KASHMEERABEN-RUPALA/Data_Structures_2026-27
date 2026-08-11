#include <stdio.h>
#include <stdlib.h>

/*
    Red-Black Tree Node nu Structure definition

    Color encoding:
    color = 0 -> RED
    color = 1 -> BLACK
*/
struct node
{
    int key;
    int color;

    struct node *left;
    struct node *right;
    struct node *parent;
};


/* New Red-Black Tree node allocate ane initialize karva mate nu Function */
struct node *newNode(int key)
{
    struct node *temp;

    // Structure size pramane dynamic memory allocation
    temp = (struct node *)malloc(sizeof(struct node));

    temp->key = key;

    /*
        Red-Black Tree Rule:
        Newly inserted node hamesha RED (0) j hoy che.
    */
    temp->color = 0;

    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;

    return temp;
}


/*
    Left Rotation Function

         x                         y
          \                       / \
           y        --->         x   C
          /                       \
         B                         B
*/
void leftRotate(struct node **root, struct node *x)
{
    struct node *y;

    y = x->right;

    /* y no left subtree x na right child trife attach karo */
    x->right = y->left;

    if (y->left != NULL)
        y->left->parent = x;

    /* y, x ni old parent position le che */
    y->parent = x->parent;

    if (x->parent == NULL)
        *root = y;                  // Jo x Root hoto, to y new Root banse

    else if (x == x->parent->left)
        x->parent->left = y;

    else
        x->parent->right = y;

    /* x ne y na Left child tarife re-assign karo */
    y->left = x;
    x->parent = y;
}


/*
    Right Rotation Function

             x                     y
            /                     / \
           y        --->         A   x
          / \                       /
         A   B                     B
*/
void rightRotate(struct node **root, struct node *x)
{
    struct node *y;

    y = x->left;

    /* y no right subtree x na left child tarife attach karo */
    x->left = y->right;

    if (y->right != NULL)
        y->right->parent = x;

    /* y, x ni old parent position le che */
    y->parent = x->parent;

    if (x->parent == NULL)
        *root = y;                  // Jo x Root hoto, to y new Root banse

    else if (x == x->parent->right)
        x->parent->right = y;

    else
        x->parent->left = y;

    /* x ne y na Right child tarife re-assign karo */
    y->right = x;
    x->parent = y;
}


/*
    Insertion pachi thāyela Red-Red Conflict ne fix karva mate nu Function.

    Recoloring ane Rotation techniques thi balance restore karay che.
*/
void fixInsertion(struct node **root, struct node *z)
{
    struct node *parent;
    struct node *grandParent;
    struct node *uncle;

    // Jo parent RED (0) hoy ane z root na hoy, tya sudhi loop chalashē (Red-Red violation)
    while (z != *root &&
           z->parent != NULL &&
           z->parent->color == 0)
    {
        parent = z->parent;
        grandParent = parent->parent;


        /*
            Case A: Parent, GrandParent no Left Child che
        */
        if (parent == grandParent->left)
        {
            uncle = grandParent->right;


            /*
                CASE 1: Uncle RED (0) che.

                Solution: Recoloring karo
                Parent -> BLACK
                Uncle -> BLACK
                GrandParent -> RED
            */
            if (uncle != NULL && uncle->color == 0)
            {
                parent->color = 1;
                uncle->color = 1;
                grandParent->color = 0;

                z = grandParent;    // GrandParent mathi farithi issue check karva pointer move karo
            }

            else
            {
                /*
                    CASE 2: z Right Child che (Triangle configuration).

                    First, parent par Left Rotation karo to convert it into Case 3.
                */
                if (z == parent->right)
                {
                    z = parent;
                    leftRotate(root, z);

                    parent = z->parent;
                    grandParent = parent->parent;
                }


                /*
                    CASE 3: z Left Child che (Line configuration).

                    Parent ane GrandParent nu Recoloring karo,
                    ane GrandParent par Right Rotation karo.
                */
                parent->color = 1;
                grandParent->color = 0;

                rightRotate(root, grandParent);
            }
        }


        /*
            Case B: Parent, GrandParent no Right Child che (Mirror Cases)
        */
        else
        {
            uncle = grandParent->left;


            /*
                CASE 1 (Mirror): Uncle RED (0) che.
                Recoloring process execution.
            */
            if (uncle != NULL && uncle->color == 0)
            {
                parent->color = 1;
                uncle->color = 1;
                grandParent->color = 0;

                z = grandParent;
            }

            else
            {
                /*
                    CASE 2 (Mirror): z Left Child che (Triangle configuration).

                    Parent par Right Rotation karo.
                */
                if (z == parent->left)
                {
                    z = parent;
                    rightRotate(root, z);

                    parent = z->parent;
                    grandParent = parent->parent;
                }


                /*
                    CASE 3 (Mirror): z Right Child che (Line configuration).

                    Recolor karo ane GrandParent par Left Rotation karo.
                */
                parent->color = 1;
                grandParent->color = 0;

                leftRotate(root, grandParent);
            }
        }
    }


    /*
        Red-Black Tree Property 2: Root Node hamesha BLACK (1) hovo joie.
    */
    (*root)->color = 1;
}


/*
    Red-Black Tree ma key insert karva mate nu Function.

    Pehle normal BST insertion thase, pachi Red-Red violation fix thase.
*/
void insert(struct node **root, int key)
{
    struct node *new;
    struct node *parent;
    struct node *temp;

    new = newNode(key);

    /*
        Empty Tree Case:
        New node root banse ane teno color BLACK thai jase.
    */
    if (*root == NULL)
    {
        new->color = 1;     /* Root hamesha BLACK hovo joie */
        *root = new;
        return;
    }


    /*
        Standard Binary Search Tree (BST) Insertion Traversal
    */
    temp = *root;
    parent = NULL;

    while (temp != NULL)
    {
        parent = temp;

        if (key < temp->key)
            temp = temp->left;

        else if (key > temp->key)
            temp = temp->right;

        else
        {
            /*
                Duplicate Keys Red-Black Tree ma allowed nathi.
            */
            free(new);
            return;
        }
    }


    // Parent pointers set karo
    new->parent = parent;

    if (key < parent->key)
        parent->left = new;
    else
        parent->right = new;


    /*
        Insert thaya pachi Red-Red Violation handle karo
    */
    fixInsertion(root, new);
}


/*
    Inorder Traversal Function

    Tree elements ne Sorted order ma Color (R/B) sathe Print kare che.
*/
void inorder(struct node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);

    // Node Key ane teno color (R = RED, B = BLACK) display thase
    printf("%d(%s) ",
           root->key,
           root->color == 0 ? "R" : "B");

    inorder(root->right);
}


int main()
{
    struct node *root = NULL;

    // Test data insertion sequence
    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 30);
    insert(&root, 15);
    insert(&root, 25);
    insert(&root, 5);
    insert(&root, 12);
    insert(&root, 35);
    insert(&root, 40);
    insert(&root, 32);
    insert(&root, 50);


    printf("Inorder Traversal:\n");
    inorder(root);

    return 0;
}