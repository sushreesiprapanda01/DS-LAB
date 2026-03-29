#include <stdio.h>
#define MAX 5

int cq[MAX];
int front = -1, rear = -1;


void insert(int value) {
    if((front == 0 && rear == MAX - 1) || (front == rear + 1)) {
        printf("Queue Overflow!\n");
    } else {
        if(front == -1) {
            front = rear = 0;
        } else if(rear == MAX - 1) {
            rear = 0;
        } else {
            rear++;
        }
        cq[rear] = value;
        printf("Inserted %d\n", value);
    }
}


void deleteElement() {
    if(front == -1) {
        printf("Queue Underflow!\n");
    } else {
        printf("Deleted element: %d\n", cq[front]);

        if(front == rear) {
            front = rear = -1;
        } else if(front == MAX - 1) {
            front = 0;
        } else {
            front++;
        }
    }
}


void display() {
    int i;

    if(front == -1) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements are:\n");

    if(front <= rear) {
        for(i = front; i <= rear; i++) {
            printf("%d ", cq[i]);
        }
    } else {
        for(i = front; i < MAX; i++) {
            printf("%d ", cq[i]);
        }
        for(i = 0; i <= rear; i++) {
            printf("%d ", cq[i]);
        }
    }
    printf("\n");
}

int main() {
    int choice, value;

    do {
        printf("\n--- CIRCULAR QUEUE MENU ---\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
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