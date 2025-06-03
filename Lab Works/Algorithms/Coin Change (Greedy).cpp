#include <iostream>
#include <vector>

using namespace std;

int minCoinsCalculation(const vector<int>& coins, int target) {
int count = 0;
for (int i = 0; i < coins.size(); i++) {
    if (target == 0) {
        break;
}
count += target / coins[i];
target %= coins[i];
 }
return count;
}

int main() {
vector<int> coins = {25, 10, 5, 2};
int target = 63;
int result = minCoinsCalculation(coins, target);
cout << "Minimum number of coins needed to target: " << result << endl;

return 0;
}
