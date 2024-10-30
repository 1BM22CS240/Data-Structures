#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}


void insertAtPosition(struct Node** head, int data, int position) {
    if (position == 0) {
        insertAtBeginning(head, data);
        return;
    }

    struct Node* newNode = createNode(data);
    struct Node* current = *head;

    for (int i = 0; current != NULL && i < position - 1; i++) {
        current = current->next;
    }

    if (current == NULL) {
        printf("The previous node is null. Insertion failed.\n");
        free(newNode);
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}


void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}


void displayList(struct Node* node) {
    if (node == NULL) {
        printf("The list is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}


int main() {
    struct Node* head = NULL;

    displayList(head);
    insertAtEnd(&head, 50);
    insertAtEnd(&head, 65);
    insertAtEnd(&head, 74);
    displayList(head);


    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 1);
    insertAtBeginning(&head, 1);

    displayList(head);
    
    insertAtPosition(&head, 5, 4);
    displayList(head);

    insertAtEnd(&head, 100);
    displayList(head);

    return 0;
}
