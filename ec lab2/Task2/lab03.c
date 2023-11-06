#include <stdio.h>
#include <stdlib.h>

// Function to calculate six-month moving average
void calculateMovingAverage(float sales[], float movingAverage[]) {
    for(int i=0; i<7; i++) {
        float sum = 0.0;
        for(int j=i; j<i+6; j++) {
            sum += sales[j];
        }
        movingAverage[i] = sum / 6;
    }
}

// Function to sort sales data in descending order
void sortSalesData(float sales[], int months[], int n) {
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(sales[i] < sales[j]) {
                float temp = sales[i];
                sales[i] = sales[j];
                sales[j] = temp;

                int tempMonth = months[i];
                months[i] = months[j];
                months[j] = tempMonth;
            }
        }
    }
}

// Function to return the month name
char* getMonthName(int month) {
    char* names[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    return names[month-1];
}

int main() {
    float sales[12] = {23458.01, 40112.00, 56011.85, 37820.88, 37904.67, 60200.22, 72400.31, 56210.89, 67230.84, 68233.12, 80950.34, 95225.22};
    float sortedSales[12];
    for (int i = 0; i < 12; i++) {
        sortedSales[i] = sales[i];
    }
    float movingAverage[7];
    int months[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    float minSales = sales[0], maxSales = sales[0], sumSales = 0.0;
    int minMonth = 1, maxMonth = 1;
    for(int i=0; i<12; i++) {
        if(sales[i] < minSales) {
            minSales = sales[i];
            minMonth = i+1;
        }
        if(sales[i] > maxSales) {
            maxSales = sales[i];
            maxMonth = i+1;
        }
        sumSales += sales[i];
    }
    float averageSales = sumSales / 12;

    calculateMovingAverage(sales, movingAverage);
    sortSalesData(sortedSales, months, 12);

    printf("Monthly sales report for 2022:\n");
    printf("Month Sales\n");
    for(int i=0; i<12; i++) {
        printf("%s $%.2f\n", getMonthName(i+1), sales[i]);
    }
    printf("Sales summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", minSales, getMonthName(minMonth));
    printf("Maximum sales: $%.2f (%s)\n", maxSales, getMonthName(maxMonth));
    printf("Average sales: $%.2f\n", averageSales);

    printf("Six-Month Moving Average Report:\n");
    for(int i=0; i<7; i++) {
        printf("%s - %s: $%.2f\n", getMonthName(i+1), getMonthName(i+6), movingAverage[i]);
    }

    printf("Sales Report (Highest to Lowest):\n");
    printf("Month Sales\n");
    for(int i=0; i<12; i++) {
        printf("%s: $%.2f\n", getMonthName(months[i]), sortedSales[i]);
    }

    return 0;
}
