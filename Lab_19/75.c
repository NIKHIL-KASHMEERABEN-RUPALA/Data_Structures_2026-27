#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int info;
    struct Node *left;
    struct Node *right;
};


struct Node *createNode(int item)
{
    struct Node *temp;

    // Dynamic Memory Allocation - heap ma space allocate karva mate
    temp = (struct Node *)malloc(sizeof(struct Node));

    // Check karo ke memory allocation successful thayu ke nai
    if (temp == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);    
    }

    // Node na member variables initialize karo
    temp->info = item;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}



struct Node *insert(struct Node *node, int info)
{
    //  Jo Tree empty (NULL) hoy, toh navo node banavi ne return karo 
    if (node == NULL)
        return createNode(info);

    //  Duplicate info validation - already exist karti info insert na thay
    if (node->info == info)
    {
        printf("Duplicate info is not allowed.\n");
        return node;
    }

    // Jo info moti (greater) hoy toh Right subtree ma recursive insert call karo
    if (node->info < info)
        node->right = insert(node->right, info);

    // Jo info nani (smaller) hoy toh Left subtree ma recursive insert call karo
    else
        node->left = insert(node->left, info);

    // Unchanged node pointer return karo 
    return node;
}





struct Node *search(struct Node *root, int info)
{
    
    if (root == NULL || root->info == info)
        return root;

   
    if (root->info < info)
        return search(root->right, info);

    
    return search(root->left, info);
}



    

    // BST rule pramane, minimum value hamesha extreme left node par j malse.


struct Node *minValueNode(struct Node *node)
{
    struct Node *current;

    current = node;

    // Extreme left node sudhi traverse karte raho 
    while (current != NULL && current->left != NULL)
        current = current->left;

    return current;
}






    // Total 3 Cases handled :

    // Case 1: Node leaf node hoy (Zero children).
    //          -> Direct memory free kari ne delete dyo.

    // Case 2: Node ne just 1 Child hoy.
    //          -> Node ne ena child sathe replace kari dyo.

    // Case 3: Node ne 2 Children hoy.
    //          -> Inorder successor (Right subtree ni minimum info) shodho.
    //          -> Successor ni info copy karo.
    //          -> Successor node ne delete karo.

struct Node *deleteNode(struct Node *root, int info)
{
    struct Node *temp;

    //  Tree empty hoy athva info exist na karti hoy 
    if (root == NULL)
        return root;

    // 
    //      Delete karva mate node ne search karo:
    //      Smaller info -> Left subtree
    //      Greater info -> Right subtree
    // 
    if (info < root->info)
    {
        root->left = deleteNode(root->left, info);
    }
    else if (info > root->info)
    {
        root->right = deleteNode(root->right, info);
    }
    else
    {
        // 
        //      Target Node madiii gayo!

        //      CASE 1 and CASE 2:
        //      Zero child OR Single child condition.
        // 
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }

        if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }

        
        //      CASE 3:
        //      Node ne 2 children chhe.

        //      Right subtree mathi smallest node find karo  = Inorder Successor.
        
        temp = minValueNode(root->right);

        // Inorder successor ni info current node ma copy karo
        root->info = temp->info;

        // Duplicate Inorder Successor node ne recursive delete karo
        root->right = deleteNode(root->right, temp->info);
    }

    return root;
}



    // Recursive Preorder Traversal.

    // Traversal Order:
    //      Root -> Left Subtree -> Right Subtree

void RPREORDER(struct Node *T)
{
    // Empty tree condition check
    if (T == NULL)
        return;

    // Current root node ni info print/process karo 
    printf("%d ", T->info);

    // Left subtree travers karo 
    if (T->left != NULL)
        RPREORDER(T->left);

    // Right subtree travers karo
    if (T->right != NULL)
        RPREORDER(T->right);
}



//      Recursive Inorder Traversal.

//      Traversal Order:
//          Left Subtree -> Root -> Right Subtree

//      Note: BST ma Inorder Traversal thi elements hamesha sorted order ma malse.


void RINORDER(struct Node *T)
{
    // Empty tree check 
    if (T == NULL)
        return;

    // Left subtree traverse karo 
    if (T->left != NULL)
        RINORDER(T->left);

    // Root node ni info print karo 
    printf("%d ", T->info);

    // Right subtree traverse karo 
    if (T->right != NULL)
        RINORDER(T->right);
}
    

    // Traversal Order:
    //      Left Subtree -> Right Subtree -> Root

void RPOSTORDER(struct Node *T)
{
    // Empty tree check 
    if (T == NULL)
        return;

    // Left subtree traverse karo 
    if (T->left != NULL)
        RPOSTORDER(T->left);

    //  Right subtree traverse karo 
    if (T->right != NULL)
        RPOSTORDER(T->right);

    //  Root node ni info print karo 
    printf("%d ", T->info);
}


int main()
{
    struct Node *root = NULL; // Initial state ma tree ne empty set karo
    struct Node *result;

    int choice;
    int info;

    do
    {
        printf("\n\n========== BINARY SEARCH TREE ==========\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Search a node\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Inorder Traversal\n");
        printf("7. Exit\n");
        printf("========================================\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:

                printf("Enter info to insert: ");
                scanf("%d", &info);

                // Insert function call
                root = insert(root, info);

                printf("Node inserted successfully.\n");

                break;


            case 2:

                printf("Enter info to delete: ");
                scanf("%d", &info);

                
                    // Delete karta pehla info exist kare chhe ke nai ae search karo,
                    // jethi user ne proper confirmation message aapi shakaye.
                
                result = search(root, info);

                if (result == NULL)
                {
                    printf("Node not found.\n");
                }
                else
                {
                    root = deleteNode(root, info);
                    printf("Node deleted successfully.\n");
                }

                break;


            case 3:

                printf("Enter info to search: ");
                scanf("%d", &info);

                // Search function call
                result = search(root, info);

                if (result == NULL)
                    printf("Node not found.\n");
                else
                    printf("Node found: %d\n", result->info);

                break;


            case 4:

                if (root == NULL)
                {
                    printf("Empty Tree\n");
                }
                else
                {
                    printf("Preorder Traversal: ");
                    RPREORDER(root);
                    printf("\n");
                }

                break;


            case 5:

                if (root == NULL)
                {
                    printf("Empty Tree\n");
                }
                else
                {
                    printf("Postorder Traversal: ");
                    RPOSTORDER(root);
                    printf("\n");
                }

                break;


            case 6:

                if (root == NULL)
                {
                    printf("Empty Tree\n");
                }
                else
                {
                    printf("Inorder Traversal: ");
                    RINORDER(root);
                    printf("\n");
                }

                break;


            case 7:

                printf("Program terminated.\n");

                break;


            default:

                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 7);


    return 0;
}
