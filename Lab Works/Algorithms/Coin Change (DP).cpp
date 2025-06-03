#include <iostream>
#include <vector>
#include <climits>  // For INT_MAX
using namespace std;

// Function to find the minimum number of coins needed
int coinChange(vector<int>& coins, int amount) {
    // Create a dp array to store the minimum number of coins for each amount up to 'amount'
    vector<int> dp(amount + 1, INT_MAX);  // Initialize all values with a large number (infinity)
    dp[0] = 0;  // Base case: 0 coins are needed to make the amount 0

    // Loop through all the amounts from 1 to the target amount
    for (int i = 1; i <= amount; i++) {
        // Try each coin denomination
        for (int coin : coins) {
            // If the coin can be used to make up the current amount
            if (i >= coin) {
                dp[i] = min(dp[i], dp[i - coin] + 1);  // Update dp[i] with the minimum coins required
            }
        }
    }

    // If dp[amount] is still INT_MAX, it means we cannot make the amount with the given coins
   if (dp[amount] == INT_MAX) {
    return -1;
} else {
    return dp[amount];
 }

}

int main() {
    vector<int> coins = {1, 2, 5};  // Coin denominations
    int amount = 11;  // Target amount to make

    int result = coinChange(coins, amount);  // Call the function

    if (result != -1) {
        cout << "Minimum number of coins required: " << result << endl;
    } else {
        cout << "It's not possible to make the amount with the given coins." << endl;
    }

    return 0;
}

