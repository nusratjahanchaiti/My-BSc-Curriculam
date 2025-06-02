#include <iostream>
#include <vector>
#include <algorithm>  // for sort
using namespace std;

int minCoins(vector<int>& coins, int target) {
    int coinCount = 0;

    // Sort the coins in descending order to process from largest to smallest
    sort(coins.rbegin(), coins.rend());

    for (int coin : coins) {
        // Take as many coins of the current denomination as possible
        if (coin <= target) {
            int coinUsed = target / coin;  // How many of this coin
            coinCount += coinUsed;         // Add to the coin count
            target -= coinUsed * coin;    // Reduce the target
        }
        if (target == 0) break;  // Stop if we have matched the target
    }

    return coinCount;
}

int main() {
    vector<int> coins = {1, 5, 10, 25};  // Coin denominations
    int target = 63;  // The target amount

    int result = minCoins(coins, target);  // Find the minimum number of coins

    cout << "Minimum coins needed: " << result << endl;

    return 0;
}
