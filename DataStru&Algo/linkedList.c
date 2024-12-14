// Singlely Linkedlist Implementation
#include <stdio.h>

typedef struct MyLLNode
{
    int value;
    struct MyLLNode *next;
} MyLLNode;

MyLLNode *createNode(int);
void listInsertHead(int, MyLLNode **, MyLLNode **);
void listInsertTail(int, MyLLNode **, MyLLNode **);
void listDeleteByValue(int, MyLLNode **, MyLLNode **);
void reverseLinkedlist(MyLLNode **head);

int main()
{
    MyLLNode *head = NULL;
    MyLLNode *tail = NULL;

    listInsertHead(5, &head, &tail);

    return 0;
}

MyLLNode *createNode(int value)
{
    MyLLNode *newNode = (MyLLNode *)malloc(sizeof(MyLLNode));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void listInsertHead(int value, MyLLNode **head, MyLLNode **tail)
{
    MyLLNode *newHead = createNode(value);
    newHead->next = *head;
    if (*head == NULL)
    {
        *tail = newHead;
    }
    *head = newHead;
}

void listInsertTail(int value, MyLLNode **head, MyLLNode **tail)
{
    MyLLNode *newTail = createNode(value);
    if ((*tail) == NULL)
    {
        *head = newTail;
        *tail = newTail;
        return;
    }
    (*tail)->next = newTail;
    *tail = newTail;
}

void listDeleteByValue(int value, MyLLNode **head, MyLLNode **tail)
{
    if (*head == NULL)
    {
        printf("the list is empty\n");
        return;
    }
    if ((*head)->next == NULL && (*head)->value == value)
    {
        free(*head);
        *head = NULL;
        *tail = NULL;
        return;
    }
    MyLLNode *curr = *head;
    MyLLNode *last = NULL;
    if (curr->value == value)
    {
        (*head) = (*head)->next;
        free(curr);
        return;
    }
    last = curr;
    curr = (*head)->next;
    while (curr != NULL)
    {
        if (curr->value == value)
        {
            last->next = curr->next;
            free(curr);
            return;
        }
        last = curr;
        curr = curr->next;
    }

    printf("no node with the value %d found\n", value);
}

void reverseLinkedlist(MyLLNode **head)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        return;
    }
    MyLLNode *curr = (*head)->next;
    MyLLNode *last;
    MyLLNode *next;

    // head(last)->b(curr)->c->d->e->f->g
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = last;
        last = curr;
        curr = next;
    }
    *head = last;
}