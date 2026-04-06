#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;
};

bool compare(Item a, Item b) {
    return (double)a.value/a.weight > (double)b.value/b.weight;
}

double fractionalKnapsack(vector<Item>& items, int W) {

    sort(items.begin(), items.end(), compare);

    double total = 0;

    for(auto item : items) {

        if(W >= item.weight) {
            total += item.value;
            W -= item.weight;
        }
        else {
            total += item.value * ((double)W / item.weight);
            break;
        }
    }

    return total;
}

int main() {

    vector<Item> items = {{60,10},{100,20},{120,30}};
    int W = 50;

    cout << "Max value: " << fractionalKnapsack(items, W);

    return 0;
}
