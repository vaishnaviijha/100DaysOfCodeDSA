#include <stdio.h>

int main() {
    int n, i;
    scanf("%d", &n);

    int prices[n];

    for(i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }

    int min_price = prices[0];
    int max_profit = 0;

    for(i = 1; i < n; i++) {
        if(prices[i] < min_price) {
            min_price = prices[i];
        } else {
            int profit = prices[i] - min_price;
            if(profit > max_profit) {
                max_profit = profit;
            }
        }
    }

    printf("%d", max_profit);

    return 0;
}