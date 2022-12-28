#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
int data;
struct Node* nxp;
};


struct Node* XOR(struct Node* a, struct Node* b)
{
return (struct Node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}


struct Node* insert(struct Node** head, int value)
{
if (*head == NULL) {


struct Node* node
= (struct Node*)malloc(sizeof(struct Node));

node->data = value;

node->nxp = XOR(NULL, NULL);
*head = node;
}

else {

struct Node* curr = *head;
struct Node* prev = NULL;


struct Node* node
= (struct Node*)malloc( sizeof(struct Node));

curr->nxp = XOR(node,
XOR(NULL, curr->nxp));

node->nxp = XOR(NULL, curr);
*head = node;

node->data = value;
}
return *head;
}

struct Node* insertPos(struct Node** head,
                    int value, int position)
{
    // If XOR linked list is empty
    if (*head == NULL) {

        // If given position
        // is equal to 1
        if (position == 1) {

            // Initialize a new Node
            struct Node* node
                = (struct Node*)malloc(
                    sizeof(struct Node));

            // Stores data value in
            // the node
            node->data = value;

            // Stores XOR of previous
            // and next pointer
            node->nxp = XOR(NULL, NULL);

            // Update pointer of head node
            *head = node;
        }

        // If required position was not found
        else {
            printf("Invalid Position\n");
        }
    }

    // If the XOR linked list
    // is not empty
    else {

        // Stores position of a node
        // in the XOR linked list
        int Pos = 1;

        // Stores the address
        // of current node
        struct Node* curr = *head;

        // Stores the address
        // of previous node
        struct Node* prev = NULL;

        // Stores the XOR of next
        // node and previous node
        struct Node* next
            = XOR(prev, curr->nxp);

        // Traverse the XOR linked list
        while (next != NULL && Pos < position - 1) {

            // Update prev
            prev = curr;

            // Update curr
            curr = next;

            // Update next
            next = XOR(prev, curr->nxp);

            // Update Pos
            Pos++;
        }

        // If the position of the current
        // node is equal to the given position
        if (Pos == position - 1) {

            // Initialize a new Node
            struct Node* node
                = (struct Node*)malloc(
                    sizeof(struct Node));

            // Stores pointer to previous Node
            // as (prev ^ next ^ next) = prev
            struct Node* temp
                = XOR(curr->nxp, next);

            // Stores XOR of prev and new node
            curr->nxp = XOR(temp, node);

            // Connecting new node with next
            if (next != NULL) {

                // Update pointer of next
                next->nxp = XOR(node,
                                XOR(next->nxp, curr));
            }

            // Connect node with curr and
            // next curr<--node-->next
            node->nxp = XOR(curr, next);
            node->data = value;
        }

        // Insertion node at beginning
        else if (position == 1) {

            // Initialize a new Node
            struct Node* node
                = (struct Node*)malloc(
                    sizeof(struct Node));

            // Update curr node address
            curr->nxp = XOR(node,
                            XOR(NULL, curr->nxp));

            // Update new node address
            node->nxp = XOR(NULL, curr);

            // Update head
            *head = node;

            // Update data value of
            // current node
            node->data = value;
        }
        else {
            printf("Invalid Position\n");
        }
    }
    return *head;
}



void printList(struct Node** head)
{
struct Node* curr = *head;

struct Node* prev = NULL;

struct Node* next;

while (curr != NULL) {

printf("%d ", curr->data);

next = XOR(prev, curr->nxp);

prev = curr;

curr = next;
}
}


struct Node* delEnd(struct Node** head)
{

if (*head == NULL)
printf("List is empty");
else {


struct Node* curr = *head;


struct Node* prev = NULL;


struct Node* next;


while (XOR(curr->nxp, prev) != NULL) {

next = XOR(prev, curr->nxp);


prev = curr;


curr = next;
}

if (prev != NULL)
prev->nxp = XOR(XOR(prev->nxp, curr), NULL);


else
*head = NULL;

free(curr);
}

return *head;
}

int main()
{
    int n,x,pos;
struct Node* head = NULL;
    printf("Enter number of nodes\n");
    scanf("%d", &n);
    for(int i=0;i<n;i++)
    {
        scanf("%d", &x);
        insert(&head, x);
    }

    printf("Before deletion:\n");
    printList(&head);
    printf("\n");

    printf("After deletion\n");
    delEnd(&head);
    printList(&head);
    printf("\n");

    printf("Enter an element to be added:\n");
    scanf("%d", &x);
    printf("Enter the position\n");
    scanf("%d", &pos);
    insertPos(&head, x,pos);

if (head == NULL)
printf("List is empty");
else

printList(&head);

return (0);
}

