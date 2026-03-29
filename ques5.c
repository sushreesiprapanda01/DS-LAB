#include <stdio.h>


struct student {
    int roll;
    char name[50];
    int age;
};


void display(struct student s[], int n) {
    int i;
    printf("\nStudents with age >= 20:\n");

    for(i = 0; i < n; i++) {
        if(s[i].age >= 20) {
            printf("Roll No: %d\n", s[i].roll);
            printf("Name   : %s\n", s[i].name);
            printf("Age    : %d\n\n", s[i].age);
        }
    }
}

int main() {
    struct student s[5];
    int i;

    
    printf("Enter details of 5 students:\n");
    for(i = 0; i < 5; i++) {
        printf("\nStudent %d\n", i + 1);

        printf("Enter Roll No: ");
        scanf("%d", &s[i].roll);

        printf("Enter Name: ");
        scanf("%s", s[i].name);

        printf("Enter Age: ");
        scanf("%d", &s[i].age);
    }

    
    display(s, 5);

    return 0;
}