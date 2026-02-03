#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int prices[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }

    int minPrice = prices[0];
    int maxProfit = 0;

    for(int i = 1; i < n; i++) {
        if(prices[i] < minPrice) {
            minPrice = prices[i];   // new minimum
        }

        int profit = prices[i] - minPrice;

        if(profit > maxProfit) {
            maxProfit = profit;     // update best profit
        }
    }

    printf("Maximum Profit = %d", maxProfit);

    return 0;
}
