    #include <stdio.h>
    #include <stdlib.h>

    // malloc in createNode

    typedef struct Node
    {
        int value;
        struct Node *next;
    } Node;

    Node *initList();
    Node *createNode(int value);
    void insertHead(int value, Node **head);
    void deleteByValue(int value, Node **head);
    void reverseList(Node **head);
    void printList(Node *head);

    int main()
    {
        Node *head = initList();
        insertHead(1, &head);
        insertHead(1, &head);
        insertHead(4, &head);
        insertHead(3, &head);
        insertHead(2, &head);
        reverseList(&head);
        deleteByValue(4, &head);
        printList(head);
    }
    inline Node *initList()
    {
        Node *head = NULL;
        return head;
    }

    Node *createNode(int value)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        if (newNode == NULL)
        {
            printf("malloc failed\n");
            exit(-1);
        }
        newNode->value = value;
        newNode->next = NULL;
        return newNode;
    }

    void insertHead(int value, Node **head)
    {
        Node *newNode = createNode(value);
        newNode->next = *head;
        *head = newNode;
    }

    void deleteByValue(int value, Node **head)
    {
        if ((*head) == NULL)
        {
            printf("the list is empty\n");
            return;
        }
        if ((*head)->value == value)
        {
            Node* tempHead = *head;
            *head = (*head)->next;
            free(tempHead);
            tempHead = NULL;
            return;
        }

        Node *curr = (*head)->next;
        Node *prev = *head;
        while (curr != NULL)
        {
            if (curr->value == value)
            {
                prev->next = curr->next;
                free(curr);
                curr = NULL;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    void reverseList(Node **head)
    {
        if (*head == NULL)
        {
            printf("reverse failed, list empty");
            return;
        }
        Node *prev = *head;
        Node *curr = (*head)->next;
        Node *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        (*head)->next = NULL;
        *head = prev;
        
    }

    void printList(Node *head)
    {
        printf("value of the linked list:\n");
        Node *curr = head;
        while (curr != NULL)
        {
            printf("%d ", curr->value);
            curr = curr->next;
        }
        printf("\n");
    }