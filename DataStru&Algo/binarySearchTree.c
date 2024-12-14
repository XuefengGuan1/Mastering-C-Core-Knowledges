#include <stdio.h>
#include <stdlib.h>

// todo: free Node created in nodeCreate
// Disable duplications
typedef struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
} Node;

Node *nodeCreate(int value);
Node *nodeInsert(int value, Node *root);
Node *search(int value, Node *root);
void nodeDelete(int value, Node *root);
Node *findMin(Node *root);
void deepFirstSearch(Node *root);

int main()
{
    return 0;
}

Node *nodeCreate(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->value = value;
    return newNode;
}

Node *nodeInsert(int value, Node *root)
{
    // Check if tree is empty
    if (root == NULL)
    {
        return nodeCreate(value);
    }

    if (value < root->value)
    {
        root->left = nodeInsert(value, root->left);
    }
    else if (value > root->value)
    {
        root->right = nodeInsert(value, root->right);
    }

    // If value exists in the tree, simply ignore it
    return root;
}

Node *search(int value, Node *root)
{
    if (root == NULL)
    {
        printf("value not found\n");
        return root;
    }
    if (root->value == value)
    {
        printf("value found");
        return root;
    }

    if (root->value < value)
    {
        return search(value, root->left);
    }
    return search(value, root->right);
}

// Replace with largest value that is smaller than the Node
void nodeDelete(int value, Node *root)
{
    /*
    case 1: no child
    case 2: one child
    case 3: two child
    */

    Node *toDelete = search(value, root);
    if (toDelete == NULL)
    {
        return NULL;
    }
    // Case 1: no child
    if (toDelete->left == NULL && toDelete->right == NULL)
    {
        free(toDelete);
        return NULL;
    }
    // Case 2: one child
    else if (toDelete->left == NULL)
    {
        Node *temp = toDelete->right;
        *toDelete = *temp; 
        free(temp);       
    }
    else if (toDelete->right == NULL)
    {
        Node *temp = toDelete->left;
        *toDelete = *temp;
        free(temp);
    }
    // Case 3: two children
    else
    {
        Node *largestSmall = findMin(toDelete->right);
        toDelete->value = largestSmall->value;
        nodeDelete(largestSmall->value, toDelete->right);
    }
}

Node *findMin(Node *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root;
}