#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Phone Book Contact mate BST Node nu Self-Referential Structure Definition
    Name (Alphabetical Key), Phone Number string, ane Left/Right pointers store kare che.
*/
struct TreeNode {
    char name[100];
    char phone[15];
    struct TreeNode* left;
    struct TreeNode* right;
};

/*
    Helper Function: Dynamic Heap Memory Allocate kari new Node initialize karva mate.
*/
struct TreeNode* createNode(char name[], char phone[]) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));[cite: 1]
    
    // String payload values copy karo[cite: 1]
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    
    // Child pointers initially NULL terminate karo[cite: 1]
    newNode->left = NULL;[cite: 1]
    newNode->right = NULL;[cite: 1]
    
    return newNode;[cite: 1]
}

/*
    Alphabetical Order (Dictionary Order) ma Contact Insert karva mate nu Function[cite: 1].
    strcmp() result pramane Left athva Right subtree ma traverse kare che[cite: 1].
*/
struct TreeNode* insertNode(struct TreeNode* root, char name[], char phone[]) {
    // Base Case: Empty spot male tya new node attach karo[cite: 1]
    if (root == NULL) {
        return createNode(name, phone);[cite: 1]
    }

    // Lexicographical comparison: Given name chhotu hoy to Left branch ma jao[cite: 1]
    if (strcmp(name, root->name) < 0) {
        root->left = insertNode(root->left, name, phone);[cite: 1]
    }
    // Given name motu hoy to Right branch ma jao[cite: 1]
    else if (strcmp(name, root->name) > 0) {
        root->right = insertNode(root->right, name, phone);[cite: 1]
    }
    else {
        printf("\nContact already exists with name: %s\n", name);
    }

    return root;[cite: 1]
}

/*
    Helper Function: Right Subtree no Left-most node (Inorder Successor) find karva mate[cite: 1].
*/
struct TreeNode* getInOrderSuccessor(struct TreeNode* root) {
    while (root != NULL && root->left != NULL) {[cite: 1]
        root = root->left;[cite: 1]
    }
    return root;[cite: 1]
}

/*
    Phone Book mathi specific Name walo Contact Delete karva mate nu Function[cite: 1].
    3 standard BST deletion cases handle kare che: Leaf node, 1 Child, ane 2 Children[cite: 1].
*/
struct TreeNode* delNode(struct TreeNode* root, char name[]) {
    if (root == NULL) {
        printf("\nContact not found / Phone Book is empty!\n");[cite: 1]
        return NULL;[cite: 1]
    }

    // Target node search karo[cite: 1]
    if (strcmp(name, root->name) < 0) {
        root->left = delNode(root->left, name);[cite: 1]
    } 
    else if (strcmp(name, root->name) > 0) {
        root->right = delNode(root->right, name);[cite: 1]
    } 
    // Target Node match thai gayo[cite: 1]
    else {
        // CASE 1: Leaf Node (No children)[cite: 1]
        if (root->left == NULL && root->right == NULL) {
            free(root);[cite: 1]
            return NULL;[cite: 1]
        }
        // CASE 2: Single Right Child[cite: 1]
        else if (root->left == NULL) {
            struct TreeNode* temp = root->right;[cite: 1]
            free(root);[cite: 1]
            return temp;[cite: 1]
        }
        // CASE 3: Single Left Child[cite: 1]
        else if (root->right == NULL) {
            struct TreeNode* temp = root->left;[cite: 1]
            free(root);[cite: 1]
            return temp;[cite: 1]
        }
        // CASE 4: Node with Two Children[cite: 1]
        else {
            // Right subtree no Inorder Successor fetch karo[cite: 1]
            struct TreeNode* successor = getInOrderSuccessor(root->right);[cite: 1]
            
            // Successor no data current node ma copy/replace karo[cite: 1]
            strcpy(root->name, successor->name);
            strcpy(root->phone, successor->phone);
            
            // Right subtree mathi duplicate successor node delete karo[cite: 1]
            root->right = delNode(root->right, successor->name);
        }
    }
    return root;[cite: 1]
}

/*
    Name search karva mate nu Recursive BST Lookup Function[cite: 1].
*/
struct TreeNode* searchNode(struct TreeNode* root, char name[]) {
    if (root == NULL || strcmp(root->name, name) == 0) {[cite: 1]
        return root;[cite: 1]
    }

    if (strcmp(name, root->name) < 0) {
        return searchNode(root->left, name);[cite: 1]
    } else {
        return searchNode(root->right, name);[cite: 1]
    }
}

/*
    Ascending Order (A to Z) Traversal: Standard Inorder (Left -> Root -> Right)[cite: 1]
*/
void ascOrder(struct TreeNode* root) {
    if (root == NULL) return;[cite: 1]

    ascOrder(root->left);[cite: 1]
    printf("Name: %-15s | Phone: %s\n", root->name, root->phone);[cite: 1]
    ascOrder(root->right);[cite: 1]
}

/*
    Descending Order (Z to A) Traversal: Reverse Inorder (Right -> Root -> Left)[cite: 1]
*/
void decOrder(struct TreeNode* root) {
    if (root == NULL) return;[cite: 1]

    decOrder(root->right);[cite: 1]
    printf("Name: %-15s | Phone: %s\n", root->name, root->phone);[cite: 1]
    decOrder(root->left);[cite: 1]
}

int main() {
    struct TreeNode* root = NULL;
    int choice;
    char name[100], phone[15];
    struct TreeNode* foundNode = NULL;

    /* Interactive Menu-Driven CLI Implementation */
    while (1) {
        printf("\n================ PHONE BOOK (BST) ================\n");
        printf("1. Add New Entry (Insert)\n");[cite: 1]
        printf("2. Remove Entry (Delete)\n");[cite: 1]
        printf("3. Search Phone Number (Search by Name)\n");[cite: 1]
        printf("4. List All Entries Ascending (A-Z)\n");[cite: 1]
        printf("5. List All Entries Descending (Z-A)\n");[cite: 1]
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter Name: ");
                scanf(" %s", name);
                printf("Enter Phone Number: ");
                scanf(" %s", phone);
                root = insertNode(root, name, phone);
                printf("Contact '%s' successfully added!\n", name);
                break;

            case 2:
                printf("Enter Name to delete: ");
                scanf(" %s", name);
                root = delNode(root, name);
                break;

            case 3:
                printf("Enter Name to search: ");
                scanf(" %s", name);
                foundNode = searchNode(root, name);
                if (foundNode != NULL) {
                    printf("\n[Found] Name: %s | Phone: %s\n", foundNode->name, foundNode->phone);
                } else {
                    printf("\n[Not Found] Contact '%s' does not exist.\n", name);
                }
                break;

            case 4:
                printf("\n--- Contacts in Ascending Order (A-Z) ---\n");
                if (root == NULL) printf("Phone Book is empty.\n");
                else ascOrder(root);
                break;

            case 5:
                printf("\n--- Contacts in Descending Order (Z-A) ---\n");
                if (root == NULL) printf("Phone Book is empty.\n");
                else decOrder(root);
                break;

            case 6:
                printf("Exiting Phone Book. Program Terminated.\n");
                exit(0);

            default:
                printf("Invalid Choice! Please enter a number between 1 and 6.\n");
        }
    }

    return 0;
}
