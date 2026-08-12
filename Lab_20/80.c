#include <stdio.h>
#include <stdlib.h>

/*
    2-3 Tree Node Structure Definition
    
    keysCount = 1 -> Single key (keys[0]), up to 2 children (children[0], children[1])
    keysCount = 2 -> Double keys (keys[0], keys[1]), up to 3 children (children[0], children[1], children[2])
*/
struct node
{
    int keys[2];
    int keysCount;

    struct node *children[3];
};


/*
    Helper Function: Allocate and initialize a new 2-3 Tree node with a single key
*/
struct node *newNode(int initialKey)
{
    struct node *newNodePtr;

    newNodePtr = (struct node *)malloc(sizeof(struct node));

    newNodePtr->keys[0] = initialKey;
    newNodePtr->keysCount = 1;

    // Initialize all child pointers to NULL
    newNodePtr->children[0] = NULL;
    newNodePtr->children[1] = NULL;
    newNodePtr->children[2] = NULL;

    return newNodePtr;
}



/*
    Recursive Insertion Function for 2-3 Tree

    Returns 0: Normal insertion (No split occurred at this node)
    Returns 1: Node split occurred (Promotes middle key upward)

    promotedKey  -> Key promoted to the parent level during a split
    newRightNode -> New right node created as a result of a node split
*/

int insertRecursive(struct node *currentNode,
                    int keyToInsert,
                    int *promotedKey,
                    struct node **newRightNode)
{
    int childIndex;
    int sortedKeys[3];

    struct node *tempChildren[4];
    struct node *createdRightNode;


    /*
        ================================================================
        CASE 1: Current node is a LEAF NODE (children[0] == NULL)
        ================================================================
    */
    if (currentNode->children[0] == NULL)
    {
        /*
            Subcase 1A: Node currently has 1 key (Capacity for 1 more key).
            Directly insert key in sorted order.
        */
        if (currentNode->keysCount == 1)
        {
            if (keyToInsert < currentNode->keys[0])
            {
                currentNode->keys[1] = currentNode->keys[0];
                currentNode->keys[0] = keyToInsert;
            }
            else if (keyToInsert > currentNode->keys[0])
            {
                currentNode->keys[1] = keyToInsert;
            }
            else
            {
                /* Ignore duplicate keys */
                return 0;
            }

            currentNode->keysCount = 2; // Updated key count

            return 0; // No split needed
        }


        /*
            Subcase 1B: Node already has 2 keys (Full).
            Inserting a 3rd key creates an OVERFLOW that forces a SPLIT.
        */
        if (keyToInsert == currentNode->keys[0] ||
            keyToInsert == currentNode->keys[1])
        {
            return 0; // Ignore duplicate keys
        }

        sortedKeys[0] = currentNode->keys[0];
        sortedKeys[1] = currentNode->keys[1];
        sortedKeys[2] = keyToInsert;


        /* Sort all 3 keys using simple bubble sort */
        if (sortedKeys[0] > sortedKeys[1])
        {
            int temp = sortedKeys[0];
            sortedKeys[0] = sortedKeys[1];
            sortedKeys[1] = temp;
        }

        if (sortedKeys[1] > sortedKeys[2])
        {
            int temp = sortedKeys[1];
            sortedKeys[1] = sortedKeys[2];
            sortedKeys[2] = temp;
        }

        if (sortedKeys[0] > sortedKeys[1])
        {
            int temp = sortedKeys[0];
            sortedKeys[0] = sortedKeys[1];
            sortedKeys[1] = temp;
        }


        /* The middle key is promoted to the parent level */
        *promotedKey = sortedKeys[1];


        /* The current node retains the smallest key (Left Node) */
        currentNode->keys[0] = sortedKeys[0];
        currentNode->keysCount = 1;


        /* Create a new Right Node containing the largest key */
        createdRightNode = newNode(sortedKeys[2]);

        *newRightNode = createdRightNode;

        return 1; // Signal a split to the parent
    }


    /*
        ================================================================
        CASE 2: Current node is an INTERNAL NODE
        ================================================================
    */
    
    // Determine which child branch to descend into based on key values
    if (keyToInsert < currentNode->keys[0])
        childIndex = 0;

    else if (currentNode->keysCount == 1 || keyToInsert < currentNode->keys[1])
        childIndex = 1;

    else
        childIndex = 2;


    /* Recursively insert into the selected child subtree */
    if (insertRecursive(currentNode->children[childIndex],
                        keyToInsert,
                        promotedKey,
                        newRightNode) == 0)
    {
        return 0; // Child did not split, nothing left to fix
    }


    /*
        A CHILD NODE SPLIT!
        We must now absorb the promoted key and new child pointer into currentNode.
    */

    /*
        Subcase 2A: Current internal node has 1 key (Room for the promoted key).
    */
    if (currentNode->keysCount == 1)
    {
        if (childIndex == 0)
        {
            /*
                Left child (index 0) split:
                Shift existing keys and children rightward.
            */
            currentNode->keys[1] = currentNode->keys[0];
            currentNode->keys[0] = *promotedKey;

            currentNode->children[2] = currentNode->children[1];
            currentNode->children[1] = *newRightNode;
        }
        else
        {
            /*
                Right child (index 1) split:
                Place promoted key into right slot.
            */
            currentNode->keys[1] = *promotedKey;
            currentNode->children[2] = *newRightNode;
        }

        currentNode->keysCount = 2;

        return 0; // Internal node absorbed the key without splitting
    }


    /*
        Subcase 2B: Current internal node ALREADY has 2 keys.
        Absorbing the promoted key causes an OVERFLOW on this internal node, forcing it to split as well!
    */
    sortedKeys[0] = currentNode->keys[0];
    sortedKeys[1] = currentNode->keys[1];
    sortedKeys[2] = *promotedKey;


    /* Re-align all 4 temporary child pointers after the child split */
    if (childIndex == 0)
    {
        tempChildren[0] = currentNode->children[0];
        tempChildren[1] = *newRightNode;
        tempChildren[2] = currentNode->children[1];
        tempChildren[3] = currentNode->children[2];
    }
    else if (childIndex == 1)
    {
        tempChildren[0] = currentNode->children[0];
        tempChildren[1] = currentNode->children[1];
        tempChildren[2] = *newRightNode;
        tempChildren[3] = currentNode->children[2];
    }
    else
    {
        tempChildren[0] = currentNode->children[0];
        tempChildren[1] = currentNode->children[1];
        tempChildren[2] = currentNode->children[2];
        tempChildren[3] = *newRightNode;
    }


    /*
        Internal Node Split Execution:
        Middle key is promoted up, and a new right internal node is created.
    */
    currentNode->keys[0] = sortedKeys[0];
    *promotedKey = sortedKeys[1];

    createdRightNode = newNode(sortedKeys[2]);

    currentNode->children[0] = tempChildren[0];
    currentNode->children[1] = tempChildren[1];

    createdRightNode->children[0] = tempChildren[2];
    createdRightNode->children[1] = tempChildren[3];


    /* Reset current node's key count to 1 */
    currentNode->keysCount = 1;

    /* Pass new right node back up */
    *newRightNode = createdRightNode;

    return 1; // Signal parent that this internal node split
}


/*
    Main Interface Function for Inserting into 2-3 Tree
*/
void insert(struct node **rootPtr, int keyToInsert)
{
    int promotedKey;
    struct node *newRightNode;
    struct node *newRootNode;


    /* Empty Tree Case */
    if (*rootPtr == NULL)
    {
        *rootPtr = newNode(keyToInsert);
        return;
    }


    /* Execute recursive insertion */
    if (insertRecursive(*rootPtr,
                        keyToInsert,
                        &promotedKey,
                        &newRightNode) == 0)
    {
        return; // Insertion completed without root splitting
    }


    /*
        ROOT NODE SPLIT!
        Create a new root containing the promoted key (Tree height increases by 1).
    */
    newRootNode = newNode(promotedKey);

    newRootNode->children[0] = *rootPtr;
    newRootNode->children[1] = newRightNode;

    *rootPtr = newRootNode;
}


/*
    Inorder Traversal for 2-3 Tree
    Prints tree keys in ascending sorted order.
*/
void inorder(struct node *rootNode)
{
    if (rootNode == NULL)
        return;

    if (rootNode->keysCount == 1)
    {
        inorder(rootNode->children[0]);
        printf("%d ", rootNode->keys[0]);
        inorder(rootNode->children[1]);
    }
    else
    {
        inorder(rootNode->children[0]);
        printf("%d ", rootNode->keys[0]);
        inorder(rootNode->children[1]);
        printf("%d ", rootNode->keys[1]);
        inorder(rootNode->children[2]);
    }
}


int main()
{
    struct node *rootNode = NULL;

    /* Insertion Test Sequence */
    insert(&rootNode, 10);
    insert(&rootNode, 20);
    insert(&rootNode, 30);
    insert(&rootNode, 15);
    insert(&rootNode, 25);
    insert(&rootNode, 5);
    insert(&rootNode, 35);

    printf("Inorder Traversal:\n");
    inorder(rootNode);
    printf("\n");

    return 0;
}