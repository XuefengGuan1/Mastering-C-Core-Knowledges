#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *prev;
    struct Node *next;
} Node;

Node *createNode(int value);
void append(int value, Node **head, Node **tail);
void insertStart(int value, Node **head, Node **tail);
void deleteValue(int value, Node **head, Node **tail);

int main()
{
    Node *myHead = NULL;
    Node *myTail = NULL;
    append(5, &myHead, &myTail);
    insertStart(3, &myHead, &myTail);
    deleteValue(5, &myHead, &myTail);
    return 0;
}

Node *createNode(int value)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->next = NULL;
    node->prev = NULL;
    node->value = value;
    return node;
}

void append(int value, Node **head, Node **tail)
{
    Node *newNode = createNode(value);
    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
        return;
    }
    (*tail)->next = newNode;
    newNode->prev = *tail;
    *tail = newNode;
}
void insertStart(int value, Node **head, Node **tail)
{
    Node *newNode = createNode(value);
    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
        return;
    }
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
}
void deleteValue(int value, Node **head, Node **tail)
{
    if (*head == NULL)
    {
        printf("list is empty\n");
        return;
    }
    if ((*head)->next == NULL && (*head)->value == value)
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
        return;
    }

    if ((*head)->value == value)
    {
        Node *temp = *head;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
        return;
    }
    Node *curr = (*head)->next;

    while (curr != NULL)
    {
        if (curr->value == value)
        {
            if (curr->next == NULL)
            {
                *tail = curr->prev;
                (*tail)->next = NULL;
                free(curr);
                return;
            }

            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
            free(curr);
            return;
        }
        curr = curr->next;
    }

    printf("no identical value found in the linkedlist\n");
}