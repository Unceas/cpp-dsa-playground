#include <bits/stdc++.h>
using namespace std;

class DSU {

    vector<int> parent, rankv;

public:

    DSU(int n) {
        parent.resize(n);
        rankv.resize(n,0);

        for(int i=0;i<n;i++)
            parent[i]=i;
    }

    int find(int x){

        if(parent[x]!=x)
            parent[x]=find(parent[x]);

        return parent[x];
    }

    void unite(int a,int b){

        int rootA=find(a);
        int rootB=find(b);

        if(rootA==rootB) return;

        if(rankv[rootA]<rankv[rootB])
            parent[rootA]=rootB;

        else if(rankv[rootA]>rankv[rootB])
            parent[rootB]=rootA;

        else{
            parent[rootB]=rootA;
            rankv[rootA]++;
        }
    }
};

int main(){

    DSU dsu(6);

    dsu.unite(1,2);
    dsu.unite(2,3);
    dsu.unite(4,5);

    if(dsu.find(1)==dsu.find(3))
        cout<<"1 and 3 connected\n";

    if(dsu.find(1)!=dsu.find(5))
        cout<<"1 and 5 not connected\n";

    return 0;
}

// Time Complexity: ~O(alpha(n))
