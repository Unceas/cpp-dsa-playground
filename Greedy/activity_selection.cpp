#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start, end;
};

bool compare(Activity a, Activity b) {
    return a.end < b.end;
}

int maxActivities(vector<Activity>& arr) {

    sort(arr.begin(), arr.end(), compare);

    int count = 1;
    int lastEnd = arr[0].end;

    for(int i=1;i<arr.size();i++) {
        if(arr[i].start >= lastEnd) {
            count++;
            lastEnd = arr[i].end;
        }
    }

    return count;
}

int main() {

    vector<Activity> arr = {
        {1,3},{2,5},{4,7},{6,9}
    };

    cout << "Max activities: " << maxActivities(arr);

    return 0;
}
