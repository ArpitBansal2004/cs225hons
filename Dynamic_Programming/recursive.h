#include <vector>
#include <climits>

int coinChange(const std::vector<int>& coins, int amount, int n) {
    if (amount == 0) return 0;
    if (n == 0) return INT_MAX;

    if (coins[n - 1] > amount) {
        return coinChange(coins, amount, n - 1);
    } else {
        return std::min(coinChange(coins, amount, n - 1), 1 + coinChange(coins, amount - coins[n - 1], n));
    }
}