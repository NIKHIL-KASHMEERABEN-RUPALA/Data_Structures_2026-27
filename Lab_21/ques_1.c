#include <stdio.h>
#include <stdlib.h>

/* Binary Search Tree (BST) Node nu Structural Blueprint */
struct Node {
    int data;
    struct Node *left, *right;
};


/*
    Dynamic Heap Memory Allocate kari new Node initialize karva mate nu Helper Function
*/
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL; // Left ane Right Child Pointers initially NULL set karela che
    return node;
}


/*
    Inorder Array ma target key/value no exact Index locate karva mate Linear Search Function
*/
int search(int in[], int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (in[i] == val) return i;
    }
    return -1; // Value na male to -1 return thase (Boundary Exception)
}


/*
    Preorder ane Inorder Sequences par thi Binary Tree Reconstruct karva mate nu Recursive Function.
    Preorder sequence mathi Root elements select thay che, ane Inorder sequence Left/Right Boundaries split kare che.
*/
struct Node* buildTree(int pre[], int in[], int inStart, int inEnd, int* preIndex) {
    /* Base Case: Valid Subtree Range exhaust thai jay to NULL return karo */
    if (inStart > inEnd) return NULL;

    /* Preorder Traversal mathi sequentially Current Root Node pick karo ane Pointer Increment karo */
    struct Node* root = newNode(pre[(*preIndex)++]);

    /* Leaf Node Condition: Jo Subtree ma single element hoy to direct root return karo */
    if (inStart == inEnd) return root;

    /* Current Root Node no Index Inorder Array ma search/locate karo */
    int inIndex = search(in, inStart, inEnd, root->data);

    /* 
       Divide and Conquer Strategy:
       - inIndex ni left side na elements thi Left Subtree construct karo
       - inIndex ni right side na elements thi Right Subtree construct karo
    */
    root->left = buildTree(pre, in, inStart, inIndex - 1, preIndex);
    root->right = buildTree(pre, in, inIndex + 1, inEnd, preIndex);

    return root;
}

/*
    Reconstructed Tree ni Structural Validity verify karva Inorder Traversal Function (Left -> Root -> Right)
*/
void printInorder(struct Node* node) {
    if (!node) return;
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main() {
    /* Traversal Input Datasets */
    int inorder[]  = {4, 10, 12, 15, 18, 22, 24};
    int preorder[] = {15, 10, 4, 12, 22, 18, 24};
    int n = sizeof(inorder) / sizeof(inorder[0]);
    int preIndex = 0; // Preorder Traversal sequence mate Reference Index Pointer

    /* Tree Reconstruction Execution Call */
    struct Node* root = buildTree(preorder, inorder, 0, n - 1, &preIndex);

    printf("Inorder traversal of constructed tree: ");
    printInorder(root);
    printf("\n");

    return 0;
}
