#include <stdio.h>

int main() {
    int numProducts;
    float totalAmount = 0.0;

    printf("Enter the number of products sold: ");
    scanf("%d", &numProducts);

    float price[numProducts], quantity[numProducts], totalPrice[numProducts];

    for (int i = 0; i < numProducts; i++) {
        printf("Enter the unit price for product %d: ", i+1);
        scanf("%f", &price[i]);

        printf("Enter the quantity sold for product %d: ", i+1);
        scanf("%f", &quantity[i]);

        totalPrice[i] = price[i] * quantity[i];
        totalAmount += totalPrice[i];
    }

    printf("\n\nMoney Receipt:\n\n");
    printf("Product No.\t\t\tTotal Price\n");

    for (int i = 0; i < numProducts; i++) {
        printf("%d\t\t\t\t%.2f\n", i+1, totalPrice[i]);
    }

    printf("\nTotal amount: %.2f\n", totalAmount);

    return 0;
}




