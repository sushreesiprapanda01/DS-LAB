#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct player {
    char name[50];
    char team[50];
    float avg;
    struct player *next;
};

struct player *head = NULL;


void create(int n) {
    struct player *newNode, *temp;
    int i;

    for (i = 0; i < n; i++) {
        newNode = (struct player*)malloc(sizeof(struct player));

        printf("\nEnter player name: ");
        scanf(" %[^\n]", newNode->name);

        printf("Enter team name: ");
        scanf(" %[^\n]", newNode->team);

        printf("Enter batting average: ");
        scanf("%f", &newNode->avg);

        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}


void display() {
    struct player *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("\nPlayers with batting average >= 50:\n");

    while (temp != NULL) {
        if (temp->avg >= 50) {
            printf("\nName: %s", temp->name);
            printf("\nTeam: %s", temp->team);
            printf("\nAverage: %.2f\n", temp->avg);
        }
        temp = temp->next;
    }
}

int main() {
    int n;

    printf("Enter number of players: ");
    scanf("%d", &n);

    create(n);
    display();

    return 0;
}