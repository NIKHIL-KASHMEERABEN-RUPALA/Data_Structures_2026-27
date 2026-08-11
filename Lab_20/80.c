#include <stdio.h>
#include <stdlib.h>

/*
    2-3 Tree Node Structure definition

    n = currently node ma ketli keys present che
    n = 1 -> Single key, maximum 2 child pointers
    n = 2 -> Double keys, maximum 3 child pointers
*/
struct node
{
    int key[2];
    int n;

    struct node *child[3];
};


/*
    Single key sathe new node allocate ane initialize karva mate nu Function
*/
struct node *newNode(int key)
{
    struct node *temp;

    // Structure size pramane dynamic memory allocation
    temp = (struct node *)malloc(sizeof(struct node));

    temp->key[0] = key;
    temp->n = 1;

    // Initial state ma badha child pointers NULL set karyo
    temp->child[0] = NULL;
    temp->child[1] = NULL;
    temp->child[2] = NULL;

    return temp;
}


/*
    Recursive Insertion Function for 2-3 Tree

    Return 0: Split thayo nathi (Normal insertion)
    Return 1: Node Split thayo che

    upKey    -> Parent level par promote thaye-li Middle Key
    newRight -> Node split pachi create thaye-lo new Right Node
*/
int insertRec(struct node *root,
              int key,
              int *upKey,
              struct node **newRight)
{
    int i;
    int tempKey[3];

    struct node *tempChild[4];
    struct node *right;


    /*
        CASE 1: Current node ek Leaf Node che
    */
    if (root->child[0] == NULL)
    {
        /*
            Node ma currently 1 key che (2-node condition).
            Directly sorted order ma key insert thai jase.
        */
        if (root->n == 1)
        {
            if (key < root->key[0])
            {
                root->key[1] = root->key[0];
                root->key[0] = key;
            }
            else if (key > root->key[0])
            {
                root->key[1] = key;
            }
            else
            {
                /* Duplicate keys handle thai rahya che - Ignored */
                return 0;
            }

            root->n = 2; // Key count update thayo

            return 0;
        }


        /*
            Node ma already 2 keys che (3-node condition).
            3rd key insert thavathi OVERFLOW condition create thase.

            Example: 10, 20 ma 15 insert karo -> 10, 15, 20
            Middle key (15) Parent par promote thase.
        */
        if (key == root->key[0] ||
            key == root->key[1])
        {
            return 0;
        }

        tempKey[0] = root->key[0];
        tempKey[1] = root->key[1];
        tempKey[2] = key;


        /* Standard Sorting Algorithm thi badhi 3 keys ne order karo */
        if (tempKey[0] > tempKey[1])
        {
            int t = tempKey[0];
            tempKey[0] = tempKey[1];
            tempKey[1] = t;
        }

        if (tempKey[1] > tempKey[2])
        {
            int t = tempKey[1];
            tempKey[1] = tempKey[2];
            tempKey[2] = t;
        }

        if (tempKey[0] > tempKey[1])
        {
            int t = tempKey[0];
            tempKey[0] = tempKey[1];
            tempKey[1] = t;
        }


        /* Middle key parent level par promote karo */
        *upKey = tempKey[1];


        /* Current left node pase smaller key rehse */
        root->key[0] = tempKey[0];
        root->n = 1;


        /* Larger key sathe new Right Node create karo */
        right = newNode(tempKey[2]);

        *newRight = right;

        return 1; // Split condition flag return
    }


    /*
        CASE 2: Current node Internal Node che.
        Key value compair karine correct Child Branch select karo.
    */
    if (key < root->key[0])
        i = 0;

    else if (root->n == 1 || key < root->key[1])
        i = 1;

    else
        i = 2;


    /* Selected child branch ma recursively insert karo */
    if (insertRec(root->child[i],
                  key,
                  upKey,
                  newRight) == 0)
    {
        return 0; // Bottom level e split thayo nathi
    }


    /*
        Child node split thayo che!
        Promoted key ne current Internal Node ma insert karvi padse.
    */

    /*
        Current node ma ek j key che (No overflow)
    */
    if (root->n == 1)
    {
        if (i == 0)
        {
            /*
                Left Child (index 0) split thayo hoto.
                Keys ane child pointers shift karo right direction ma.
            */
            root->key[1] = root->key[0];
            root->key[0] = *upKey;

            root->child[2] = root->child[1];
            root->child[1] = *newRight;
        }
        else
        {
            /*
                Right Child (index 1) split thayo hoto.
            */
            root->key[1] = *upKey;
            root->child[2] = *newRight;
        }

        root->n = 2;

        return 0;
    }


    /*
        Current node ma ALREADY 2 keys che.
        Promoted key add thavathi Internal Node par pan Overflow thase.
    */

    tempKey[0] = root->key[0];
    tempKey[1] = root->key[1];
    tempKey[2] = *upKey;


    /*
        Child split thavathi 4 Temporary Child pointers re-align karo.
    */
    if (i == 0)
    {
        tempChild[0] = root->child[0];
        tempChild[1] = *newRight;
        tempChild[2] = root->child[1];
        tempChild[3] = root->child[2];
    }

    else if (i == 1)
    {
        tempChild[0] = root->child[0];
        tempChild[1] = root->child[1];
        tempChild[2] = *newRight;
        tempChild[3] = root->child[2];
    }

    else
    {
        tempChild[0] = root->child[0];
        tempChild[1] = root->child[1];
        tempChild[2] = root->child[2];
        tempChild[3] = *newRight;
    }


    /*
        Internal Node Split Process:
        Middle key *upKey tarife promote thase ane new Right Internal Node banse.
    */
    if (i == 0)
    {
        root->key[0] = tempKey[0];
        *upKey = tempKey[1];

        right = newNode(tempKey[2]);

        root->child[0] = tempChild[0];
        root->child[1] = tempChild[1];

        right->child[0] = tempChild[2];
        right->child[1] = tempChild[3];
    }

    else if (i == 1)
    {
        root->key[0] = tempKey[0];
        *upKey = tempKey[1];

        right = newNode(tempKey[2]);

        root->child[0] = tempChild[0];
        root->child[1] = tempChild[1];

        right->child[0] = tempChild[2];
        right->child[1] = tempChild[3];
    }

    else
    {
        root->key[0] = tempKey[0];
        *upKey = tempKey[1];

        right = newNode(tempKey[2]);

        root->child[0] = tempChild[0];
        root->child[1] = tempChild[1];

        right->child[0] = tempChild[2];
        right->child[1] = tempChild[3];
    }


    /* Current Left node no key count reset karo */
    root->n = 1;

    /* New right node pointer update karo */
    *newRight = right;

    return 1; // Parent ne split notification moklo
}


/*
    Main Interface Function for Insertion in 2-3 Tree.
    Jo Root node split thase to New Root Tree ni height vadharse.
*/
void insert(struct node **root, int key)
{
    int upKey;
    struct node *newRight;
    struct node *newRoot;


    /*
        Empty Tree Case:
        Root node allocate kari direct element insert karo.
    */
    if (*root == NULL)
    {
        *root = newNode(key);
        return;
    }


    /* Recursive Insertion execute karo */
    if (insertRec(*root,
                  key,
                  &upKey,
                  &newRight) == 0)
    {
        return; // Normal insertion completed without root split
    }


    /*
        Root level par split thayo!
        Promoted Key sathe New Root Node create karo (Tree Height increases by 1).
    */
    newRoot = newNode(upKey);

    newRoot->child[0] = *root;
    newRoot->child[1] = newRight;

    *root = newRoot;
}


/*
    Inorder Traversal for 2-3 Tree

    Keys ne Sorted order ma Print karva mate multi-branch traversal:
    - Single key node (2-node): Left Child -> Key0 -> Right Child
    - Double key node (3-node): Child0 -> Key0 -> Child1 -> Key1 -> Child2
*/
void inorder(struct node *root)
{
    if (root == NULL)
        return;


    if (root->n == 1)
    {
        inorder(root->child[0]);

        printf("%d ", root->key[0]);

        inorder(root->child[1]);
    }

    else
    {
        inorder(root->child[0]);

        printf("%d ", root->key[0]);

        inorder(root->child[1]);

        printf("%d ", root->key[1]);

        inorder(root->child[2]);
    }
}


int main()
{
    struct node *root = NULL;

    /* Test dataset insertion sequence */
    insert(&root, 10);
    insert(&root, 20);
    insert(&root, 30);
    insert(&root, 15);
    insert(&root, 25);
    insert(&root, 5);
    insert(&root, 35);


    printf("Inorder Traversal:\n");

    inorder(root);

    return 0;
}