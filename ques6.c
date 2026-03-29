#include <stdio.h>
#include <stdlib.h>


struct product {
    int pno;
    char name[50];
    float cost;
};


void display(struct product *p, int n) {
    int i;
    printf("\nProducts with cost between 100 and 1000:\n");

    for(i = 0; i < n; i++) {
        if(p[i].cost >= 100 && p[i].cost <= 1000) {
            printf("\nProduct No: %d", p[i].pno);
            printf("\nName      : %s", p[i].name);
            printf("\nCost      : %.2f\n", p[i].cost);
        }
    }
}

int main() {
    struct product *p;
    int n, i;

    
    printf("Enter number of products: ");
    scanf("%d", &n);

    
    p = (struct product*) malloc(n * sizeof(struct product));

    if(p == NULL) {
        printf("Memory allocation failed!\n");
        return 0;
    }

    
    printf("\nEnter product details:\n");
    for(i = 0; i < n; i++) {
        printf("\nProduct %d\n", i + 1);

        printf("Enter Product No: ");
        scanf("%d", &p[i].pno);

        printf("Enter Name: ");
        scanf("%s", p[i].name);

        printf("Enter Cost: ");
        scanf("%f", &p[i].cost);
    }

    
    display(p, n);

    
    free(p);

    return 0;
}