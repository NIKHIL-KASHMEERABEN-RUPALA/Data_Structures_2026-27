#include <stdio.h>
#include <stdlib.h>

/*
    Red-Black Tree Node nu Structure definition

    Color Encoding:
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


/*
    New Red-Black Tree Node allocate ane initialize karva mate nu Function
*/
struct node *newNode(int key)
{
    struct node *temp;

    // Memory allocation as per structure size
    temp = (struct node *)malloc(sizeof(struct node));

    temp->key = key;

    /* Newly inserted node hamesha RED (0) j hoy che */
    temp->color = 0;

    temp->left = NULL;
    temp->right = NULL;
    temp->parent = NULL;

    return temp;
}


/*
    Left Rotation Function

          x
           \
            y
           / \
          B   C

            ↓

            y
           / \
          x   C
           \
            B
*/
struct node *leftRotate(struct node *root, struct node *x)
{
    struct node *y;

    y = x->right;

    /* y no left subtree x na right child tarife reassign karo */
    x->right = y->left;

    if (y->left != NULL)
        y->left->parent = x;

    /* y ne x na original parent sathe connect karo */
    y->parent = x->parent;

    if (x->parent == NULL)
    {
        /* Jo x root hoto, to y new root banse */
        root = y;
    }
    else if (x == x->parent->left)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }

    /* x ne y na left child tarife place karo */
    y->left = x;
    x->parent = y;

    return root;
}


/*
    Right Rotation Function

              x
             /
            y
           / \
          A   B

            ↓

            y
           / \
          A   x
             /
            B
*/
struct node *rightRotate(struct node *root, struct node *x)
{
    struct node *y;

    y = x->left;

    /* y no right subtree x na left child tarife reassign karo */
    x->left = y->right;

    if (y->right != NULL)
        y->right->parent = x;

    /* y ne x na original parent sathe connect karo */
    y->parent = x->parent;

    if (x->parent == NULL)
    {
        /* Jo x root hoto, to y new root banse */
        root = y;
    }
    else if (x == x->parent->right)
    {
        x->parent->right = y;
    }
    else
    {
        x->parent->left = y;
    }

    /* x ne y na right child tarife place karo */
    y->right = x;
    x->parent = y;

    return root;
}


/*
    Insertion pachi Red-Red Conflict (violation) solve karva mate nu Function
*/
struct node *fixInsertion(struct node *root, struct node *z)
{
    struct node *parent;
    struct node *grandParent;
    struct node *uncle;

    /*
        Parent RED (0) hoy tya sudhi loop run thase.
        RED parent + RED child = Red-Red Violation.
    */
    while (z != root &&
           z->parent != NULL &&
           z->parent->color == 0)
    {
        parent = z->parent;
        grandParent = parent->parent;


        /*
            CASE 1:
            Parent, GrandParent no Left Child che
        */
        if (parent == grandParent->left)
        {
            uncle = grandParent->right;


            /*
                Uncle RED che.

                Recoloring Strategy:
                Parent      -> BLACK (1)
                Uncle       -> BLACK (1)
                GrandParent -> RED (0)
            */
            if (uncle != NULL && uncle->color == 0)
            {
                parent->color = 1;
                uncle->color = 1;
                grandParent->color = 0;

                /*
                    GrandParent RED thayo, etle farithi upper level
                    par conflict check karva pointer move karo.
                */
                z = grandParent;
            }

            else
            {
                /*
                    CASE 2:
                    Triangle Configuration (z, parent no Right Child che).

                    Left Rotate kari Case 3 (Line Configuration) ma convert karo.
                */
                if (z == parent->right)
                {
                    z = parent;

                    root = leftRotate(root, z);

                    parent = z->parent;
                    grandParent = parent->parent;
                }


                /*
                    CASE 3:
                    Line Configuration (z, parent no Left Child che).

                    Recolor karo ane GrandParent par Right Rotate karo.
                */
                parent->color = 1;
                grandParent->color = 0;

                root = rightRotate(root, grandParent);
            }
        }


        /*
            MIRROR CASE:
            Parent, GrandParent no Right Child che
        */
        else
        {
            uncle = grandParent->left;


            /*
                Uncle RED che -> Recoloring process.
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
                    MIRROR CASE 2:
                    Triangle Configuration (z, parent no Left Child che).
                */
                if (z == parent->left)
                {
                    z = parent;

                    root = rightRotate(root, z);

                    parent = z->parent;
                    grandParent = parent->parent;
                }


                /*
                    MIRROR CASE 3:
                    Line Configuration (z, parent no Right Child che).
                */
                parent->color = 1;
                grandParent->color = 0;

                root = leftRotate(root, grandParent);
            }
        }
    }


    /*
        Red-Black Tree Property: Root Node hamesha BLACK (1) j hovo joie.
    */
    root->color = 1;

    return root;
}


/*
    Red-Black Tree ma Key Insert karva mate nu Main Function.

    Pehle normal BST insertion thase, pachi Red-Red violation fix thase.
*/
struct node *insert(struct node *root, int key)
{
    struct node *temp;
    struct node *parent;
    struct node *new;


    // New node create karo
    new = newNode(key);


    /*
        Empty Tree Case:
        New node j root banse ane root hamesha BLACK (1) hovo joie.
    */
    if (root == NULL)
    {
        new->color = 1;
        return new;
    }


    /*
        Standard BST Insertion Traversal
    */
    temp = root;
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
            return root;
        }
    }


    /*
        New node ne ten na parent sathe link karo.
    */
    new->parent = parent;

    if (key < parent->key)
        parent->left = new;
    else
        parent->right = new;


    /*
        Red-Red Violation handle karo ane updated Root return karo.
    */
    root = fixInsertion(root, new);

    return root;
}


/*
    Inorder Traversal Function

    Tree elements ne Sorted order ma Color Code (R/B) sathe Display kare che.
*/
void inorder(struct node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);

    // Node Key ane teno color (R = RED, B = BLACK) print thase
    printf("%d(%s) ",
           root->key,
           root->color == 0 ? "R" : "B");

    inorder(root->right);
}


int main()
{
    struct node *root = NULL;


    /*
        Insertion sequence execution
    */
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


    printf("Inorder Traversal:\n");

    inorder(root);

    return 0;
}