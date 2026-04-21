#include <bits/stdc++.h>
using namespace std;

bool canEat(vector<int>& piles, int h, int speed) {
    long long hours = 0;

    for(int p : piles) {
        hours += (p + speed - 1) / speed;
    }

    return hours <= h;
}

int minEatingSpeed(vector<int>& piles, int h) {

    int left = 1, right = *max_element(piles.begin(), piles.end());

    while(left < right) {
        int mid = left + (right - left) / 2;

        if(canEat(piles, h, mid))
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}

int main() {

    vector<int> piles = {3,6,7,11};
    int h = 8;

    cout << "Minimum Speed: " << minEatingSpeed(piles, h);

    return 0;
}
