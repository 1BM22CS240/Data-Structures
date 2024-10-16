#include <stdio.h>
#include <stdbool.h>
#define MAX 5

void enterqueue(int queue[], int *start, int *end, int value) {
    if (*end == MAX - 1) {
        printf("Overflow\n");
    } else {
        if (*start == -1 && *end == -1) {
            (*start)++;
        }
        (*end)++;
        queue[*end] = value;
        printf("%d has been added\n", value);
    }
}

void deletequeue(int queue[], int *start, int *end) {
    if (*start == -1 || *start > *end) {
        printf("Underflow\n");
    } else {
        int removed = queue[*start];
        (*start)++;
        printf("%d has been deleted\n", removed);
    }
}

void displayQueue(int queue[], int *start, int *end) {
    if (*start == -1 || *start > *end) {
        printf("The queue is empty\n");
    } else {
        for (int i = *start; i <= *end; i++) {
            printf("%d  ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int queue[MAX];
    int front = -1, rear = -1;
    int choice;
    printf("Enter 1 to Add\n");
    printf("Enter 2 to Delete\n");
    printf("Enter 3 to Display\n");
    printf("Enter 4 to Exit\n");
    bool continueRunning = true;
    while (continueRunning) {
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        if (choice == 1) {
            printf("Enter the number to add:\n");
            int value;
            scanf("%d", &value);
            enterqueue(queue, &front, &rear, value);
        } else if (choice == 2) {
            deletequeue(queue, &front, &rear);
        } else if (choice == 3) {
            displayQueue(queue, &front, &rear);
        } else if (choice == 4) {
            printf("!Exit!\n");
            continueRunning = false;
        }
    }
    return 0;
}
