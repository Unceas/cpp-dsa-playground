#include <bits/stdc++.h>
using namespace std;

struct Job {
    int id, deadline, profit;
};

bool cmp(Job a, Job b) {
    return a.profit > b.profit;
}

int maxProfit(vector<Job>& jobs) {

    sort(jobs.begin(), jobs.end(), cmp);

    int maxDeadline = 0;
    for(auto j : jobs)
        maxDeadline = max(maxDeadline, j.deadline);

    vector<int> slot(maxDeadline + 1, -1);

    int profit = 0;

    for(auto job : jobs) {
        for(int j = job.deadline; j > 0; j--) {
            if(slot[j] == -1) {
                slot[j] = job.id;
                profit += job.profit;
                break;
            }
        }
    }

    return profit;
}

int main() {

    vector<Job> jobs = {
        {1,2,100},
        {2,1,19},
        {3,2,27},
        {4,1,25},
        {5,3,15}
    };

    cout << "Max Profit: " << maxProfit(jobs);

    return 0;
}
