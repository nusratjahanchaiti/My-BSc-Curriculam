#include <stdio.h>

float kmToMiles(float km);
float milesToKm(float miles);

int main() {
    float distance, convertedDistance;
    int choice;

    printf("Enter distance and choice : ");
    scanf("%f %d", &distance, &choice);

    if (choice == 1) {
        convertedDistance = kmToMiles(distance);
        printf("Converted distance in miles: %.2f\n", convertedDistance);
    } else if (choice == 2) {
        convertedDistance = milesToKm(distance);
        printf("Converted distance in kilometers: %.2f\n", convertedDistance);
    } else {
        printf("Invalid choice! Please enter 1 or 2.\n");
    }

    return 0;
}

float kmToMiles(float km) {
    return km * 0.6213;
}

float milesToKm(float miles) {
    return miles / 0.6213;
}
