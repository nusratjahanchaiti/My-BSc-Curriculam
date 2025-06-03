#include <stdio.h>
#define CITIES 5
#define DAYS 7

int main() {
    int temperature[CITIES][DAYS] = {
        {30, 29, 31, 32, 29, 28, 33},
        {35, 30, 23, 27, 21, 30, 37},
        {28, 31, 25, 26, 24, 29, 32},
        {33, 27, 26, 28, 29, 24, 29},
        {26, 26, 28, 26, 20, 27, 31}
    };
    char city_names[CITIES][20] = {"Dhaka", "Khulna", "Chittagong", "Barisal", "Rajshahi"};
    int i, j, max_avg, min_avg, max_day, min_day, max_temp, min_temp;
    float city_avg, day_avg, total_avg = 0.0;

    printf("Average temperature of each city:\n");
    for (i = 0; i < CITIES; i++) {
        city_avg = 0.0;
        for (j = 0; j < DAYS; j++) {
            city_avg += temperature[i][j];
        }
        city_avg /= DAYS;
        printf("%s: %.2f\n", city_names[i], city_avg);
    }
    printf("\nAverage temperature of each day:\n");
    for (j = 0; j < DAYS; j++) {
        day_avg = 0.0;
        for (i = 0; i < CITIES; i++) {
            day_avg += temperature[i][j];
        }
        day_avg /= CITIES;
        printf("Day %d: %.2f\n", j+1, day_avg);
    }
    max_avg = -1000;
    min_avg = 1000;
    for (i = 0; i < CITIES; i++) {
        city_avg = 0.0;
        for (j = 0; j < DAYS; j++) {
            city_avg += temperature[i][j];
        }
        city_avg /= DAYS;
        total_avg += city_avg;
        if (city_avg > max_avg) {
            max_avg = city_avg;
            max_day = i + 1;
        }
        if (city_avg < min_avg) {
            min_avg = city_avg;
            min_day = i + 1;
        }
    }
    printf("\nMaximum average temperature among all cities: %.2f (%s)\n", max_avg, city_names[max_day-1]);
    printf("Minimum average temperature among all cities: %.2f (%s)\n", min_avg, city_names[min_day-1]);

    max_avg = -1000;
    min_avg = 1000;
    for (j = 0; j < DAYS; j++) {
        day_avg = 0.0;
        for (i = 0; i < CITIES; i++) {
            day_avg += temperature[i][j];
        }
    }
    printf("Maximum and Minimum average Temperatures among all days: %f\n",day_avg);
return 0;
}
