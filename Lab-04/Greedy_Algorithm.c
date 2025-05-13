#include <stdio.h>


void greedyCoinChange(int amount) {
    int coins[] = {25, 10, 5, 1};
    int n = sizeof(coins) / sizeof(coins[0]);
      int c=0;
    printf("Change for %d:\n", amount);

    for (int i = 0; i < n; i++) {
        if (amount >= coins[i]) {
            int count = amount / coins[i];

            amount -= count * coins[i];
            c+=count;
            printf("%d coin(s) of %d\n", count, coins[i]);
        }
        
    }
    printf(" Total Count of Coins = %d",c);
}


int main() {
    int amount;
    printf("Enter the amount: ");
    scanf("%d", &amount);

    greedyCoinChange(amount);

    return 0;
}
