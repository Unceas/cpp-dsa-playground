#include <bits/stdc++.h>
using namespace std;

// Task Scheduler
int leastInterval(vector<char>& tasks, int n) {

    vector<int> freq(26, 0);

    for(char t : tasks)
        freq[t - 'A']++;

    sort(freq.begin(), freq.end());

    int maxFreq = freq[25] - 1;
    int idle = maxFreq * n;

    for(int i = 24; i >= 0; i--) {
        idle -= min(freq[i], maxFreq);
    }

    idle = max(0, idle);

    return tasks.size() + idle;
}

int main() {

    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;

    cout << leastInterval(tasks, n);

    return 0;
}
