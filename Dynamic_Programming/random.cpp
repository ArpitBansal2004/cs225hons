#include <iostream>
#include <vector>
#include <climits>

//#include "recursive.h"
#include "dynamic.h"

int main(int argc, char **argv) {
    if(argc != 2) {
        std::cout << "Usage: " << argv[0] << " <amount>" << std::endl;
        return 1;
    }
    int amount = std::atoi(argv[1]);

    
    std::vector<int> coins = {1, 2, 5};

    
    int result = coinChange(coins, amount, coins.size());
    if (result == -1 || result == INT_MAX) 
        std::cout << "Not possible to make change" << std::endl;
    else 
        std::cout << "Minimum coins required: " << result << std::endl;

    return 0;
}
