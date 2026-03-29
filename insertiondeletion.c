#include <stdio.h>
#define MAX 10

int queue[MAX];
int front = -1, rear = -1;


void insert(int value) {
    if(rear == MAX - 1) {
        printf("Queue Overflow!\n");
    } else {
        if(front == -1)
            front = 0;
        rear++;
        queue[rear] = value;
        printf("Inserted %d\n", value);
    }
}


void deleteElement() {
    if(front == -1 || front > rear) {
        printf("Queue Underflow!\n");
    } else {
        printf("Deleted element: %d\n", queue[front]);
        front++;
    }
}


void display() {
    int i;
    if(front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements are:\n");
        for(i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    do {
        printf("\n--- QUEUE MENU ---\n");
        printf("1. Insert (Enqueue)\n2. Delete (Dequeue)\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                deleteElement();
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 4);

    return 0;
}