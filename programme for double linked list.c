#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct account {
    int acc_no;
    char name[50];
    float balance;
    struct account *prev;
    struct account *next;
};

struct account *head = NULL;


void create(int n) {
    struct account *newNode, *temp;
    int i;

    for (i = 0; i < n; i++) {
        newNode = (struct account*)malloc(sizeof(struct account));

        printf("\nEnter Account Number: ");
        scanf("%d", &newNode->acc_no);

        printf("Enter Name: ");
        scanf(" %[^\n]", newNode->name);

        printf("Enter Balance: ");
        scanf("%f", &newNode->balance);

        newNode->next = NULL;

        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
}


void display() {
    struct account *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("\nAccount Details:\n");
    while (temp != NULL) {
        printf("\nAC No: %d", temp->acc_no);
        printf("\nName: %s", temp->name);
        printf("\nBalance: %.2f\n", temp->balance);
        temp = temp->next;
    }
}


void totalBalance() {
    struct account *temp = head;
    float total = 0;

    while (temp != NULL) {
        total += temp->balance;
        temp = temp->next;
    }

    printf("\nTotal Balance of all accounts: %.2f\n", total);
}

int main() {
    int n;

    printf("Enter number of account holders: ");
    scanf("%d", &n);

    create(n);
    display();
    totalBalance();

    return 0;
}