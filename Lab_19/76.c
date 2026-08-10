#include <stdio.h>
#include <stdlib.h>

// BST na node mate nu structure definition
struct Node
{
    int key;               // Node ni data value store kare chhe
    struct Node *left;     // Left subtree no pointer
    struct Node *right;    // Right subtree no pointer
};

// Dynamic memory allocation thi navo node create karva mate nu function
struct Node *newNode(int item)
{
    struct Node *temp;

    // Heap memory ma node mate space allocate karo
    temp = (struct Node *)malloc(sizeof(struct Node));

    temp->key = item;
    temp->left = NULL;
    temp->right = NULL;

    // Created node pointer return karo
    return temp;
}

struct Node *insert(struct Node *node, int key)
{
    if (node == NULL)
        return newNode(key);

    if (node->key == key)
        return node;
      
    if (node->key < key)
        node->right = insert(node->right, key);
    else
        node->left = insert(node->left, key);

    return node;
}

// Be binary trees identical/same chhe ke nai ae check karva mate nu function
int sameTree(struct Node *root1, struct Node *root2)
{
    // Base Case 1: Jo banne trees/nodes empty (NULL) hoy, toh identical chhe (return 1/True)
    if (root1 == NULL && root2 == NULL)
        return 1;

    // Base Case 2: Jo ek tree NULL hoy ane biju non-NULL hoy, toh same nathi (return 0/False)
    if (root1 == NULL || root2 == NULL)
        return 0;

    // Value Check: Jo banne current nodes ni keys match na thay, toh structural inequality chhe
    if (root1->key != root2->key)
        return 0;

    // Recursive Check: Left-to-left ane Right-to-right subtrees simultaneous compare karo
    return sameTree(root1->left, root2->left) &&
           sameTree(root1->right, root2->right);
}

// Main execution function
int main()
{
    // Banne tree na root pointers initialize karo NULL sathe
    struct Node *root1 = NULL;
    struct Node *root2 = NULL;

    int n1, n2, key, i;

    // Pehla tree mate node count scan karo
    printf("Enter number of nodes for first tree: ");
    scanf("%d", &n1);

    // Loop na through First tree ma keys recursive insert karo
    printf("Enter nodes of first tree: ");
    for (i = 0; i < n1; i++)
    {
        scanf("%d", &key);
        root1 = insert(root1, key);
    }

    // Bija tree mate node count scan karo
    printf("Enter number of nodes for second tree: ");
    scanf("%d", &n2);

    // Loop na through Second tree ma keys recursive insert karo
    printf("Enter nodes of second tree: ");
    for (i = 0; i < n2; i++)
    {
        scanf("%d", &key);
        root2 = insert(root2, key);
    }

    // sameTree function call kari result evaluate karo
    if (sameTree(root1, root2))
        printf("Given trees are same");
    else
        printf("Given trees are not same");

    return 0;
}