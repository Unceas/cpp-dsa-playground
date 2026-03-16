#include <bits/stdc++.h>
using namespace std;

class SegmentTree {

    vector<int> tree;
    int n;

public:

    SegmentTree(vector<int>& arr){

        n = arr.size();
        tree.resize(4*n);

        build(arr,0,0,n-1);
    }

    void build(vector<int>& arr,int node,int start,int end){

        if(start==end){
            tree[node]=arr[start];
            return;
        }

        int mid=(start+end)/2;

        build(arr,2*node+1,start,mid);
        build(arr,2*node+2,mid+1,end);

        tree[node]=tree[2*node+1]+tree[2*node+2];
    }

    int query(int node,int start,int end,int l,int r){

        if(r<start || end<l)
            return 0;

        if(l<=start && end<=r)
            return tree[node];

        int mid=(start+end)/2;

        int left=query(2*node+1,start,mid,l,r);
        int right=query(2*node+2,mid+1,end,l,r);

        return left+right;
    }

    int rangeQuery(int l,int r){
        return query(0,0,n-1,l,r);
    }
};

int main(){

    vector<int> arr={1,3,5,7,9,11};

    SegmentTree st(arr);

    cout<<"Sum of range [1,4]: "
        <<st.rangeQuery(1,4);

    return 0;
}

// Time Complexity:
// Build -> O(n)
// Query -> O(log n)
