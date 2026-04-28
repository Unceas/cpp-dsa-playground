#include <bits/stdc++.h>
using namespace std;

// Minimum coins (Greedy for Indian denominations)
int minCoins(int amount) {

    vector<int> coins = {2000,500,200,100,50,20,10,5,2,1};

    int count = 0;

    for(int coin : coins) {
        if(amount >= coin) {
            count += amount / coin;
            amount %= coin;
        }
    }

    return count;
}

int main() {

    int amount = 2893;

    cout << "Minimum coins needed: " << minCoins(amount);

    return 0;
}
