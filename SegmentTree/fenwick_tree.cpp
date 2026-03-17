#include <bits/stdc++.h>
using namespace std;

class Fenwick {

    vector<int> bit;
    int n;

public:

    Fenwick(int n){
        this->n = n;
        bit.resize(n+1,0);
    }

    void update(int index,int val){
        for(; index<=n; index += index & (-index))
            bit[index] += val;
    }

    int query(int index){
        int sum = 0;
        for(; index>0; index -= index & (-index))
            sum += bit[index];
        return sum;
    }

    int rangeQuery(int l,int r){
        return query(r) - query(l-1);
    }
};

int main(){

    vector<int> arr = {0,1,2,3,4,5}; // 1-based

    Fenwick ft(5);

    for(int i=1;i<=5;i++)
        ft.update(i,arr[i]);

    cout<<"Sum [2,4]: "<<ft.rangeQuery(2,4);

    return 0;
}

// Time Complexity: O(log n)
