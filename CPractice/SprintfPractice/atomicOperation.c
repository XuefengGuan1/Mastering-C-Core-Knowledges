#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

typedef struct LinkNode
{
    int value;
    struct LinkNode *next;
} LinkNode;

LinkNode *createNode(int value);
void insertHeadList(int value, LinkNode **head);
void reverseList(LinkNode **head);
void printList(LinkNode *head);
void freeList(LinkNode *head);

// insert head
// delete tail

int main()
{
    LinkNode *myNode = NULL;
    insertHeadList(5, &myNode);
    insertHeadList(4, &myNode);
    insertHeadList(3, &myNode);
    insertHeadList(2, &myNode);
    insertHeadList(1, &myNode);

    reverseList(&myNode);
    printList(myNode);

    freeList(myNode);

    return 0;
}

LinkNode *createNode(int value)
{
    LinkNode *newNode = (LinkNode *)malloc(sizeof(LinkNode));
    if (newNode == NULL)
    {
        printf("Malloc failed: %s", strerror(errno));
        exit(-1);
    }
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}

void insertHeadList(int value, LinkNode **head)
{
    LinkNode *newHead = createNode(value);
    newHead->next = *head;
    *head = newHead;
}

void reverseList(LinkNode **head)
{
    // list empty  ,     list only has 1 value
    if ((*head == NULL) && ((*head)->next == NULL))
    {
        return;
    }
    LinkNode *prev = NULL;
    LinkNode *curr = *head;
    LinkNode *next = (*head)->next;
    // list has 2 or more value

    // a->b->c->d
    while (curr != NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = next;
        if (curr != NULL)
        {
            next = curr->next;
        }
    }
    *head = prev;
}

void printList(LinkNode *head)
{
    LinkNode *curr = head;
    printf("printing the linkedlist: \n");
    while (curr != NULL)
    {
        printf("%d", curr->value);
        curr = curr->next;
    }
    printf("\n");
}

void freeList(LinkNode *head)
{
    LinkNode *curr = head;
    LinkNode *next = head->next;
    while (curr != NULL)
    {
        free(curr);
        curr = NULL;
        curr = next;
        if (curr != NULL)
        {
            next = curr->next;
        }
    }
}