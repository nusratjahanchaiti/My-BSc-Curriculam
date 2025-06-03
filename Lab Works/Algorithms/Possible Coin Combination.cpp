#include <iostream>
#include <vector>
using namespace std;

void findCombinations(int amount, const vector<int>& coins, int start, vector<int>& current, vector<vector<int>>& result) {
if (amount == 0) {
    result.push_back(current);
    return;
}

for (int i = start; i < coins.size(); i++) {
    if (amount >= coins[i]) {
        current.push_back(coins[i]);
        findCombinations(amount - coins[i], coins, i, current, result);
        current.pop_back();
        }
    }
}

void coinChangeCombinations(const vector<int>& coins, int amount) {
    vector<vector<int>> result;
    vector<int> current;

    findCombinations(amount, coins, 0, current, result);

if (result.empty()) {
        cout << "No combinations possible for the given amount." << endl;
    } else {
        cout << "Possible combinations of coins to make " << amount << " are:" << endl;
        for (auto& comb : result) {
            for (int coin : comb) {
                cout << coin << " ";
    }
        cout << endl;
  }
 }
}

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 5;
    coinChangeCombinations(coins, amount);

    return 0;
}
