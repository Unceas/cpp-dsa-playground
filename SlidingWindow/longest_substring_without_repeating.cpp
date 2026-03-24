#include <bits/stdc++.h>
using namespace std;

// Longest Substring Without Repeating Characters
int longestSubstring(string s) {

    unordered_set<char> window;

    int left = 0;
    int maxLength = 0;

    for (int right = 0; right < s.length(); right++) {

        while (window.count(s[right])) {
            window.erase(s[left]);
            left++;
        }

        window.insert(s[right]);
        maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
}

int main() {

    string s = "abcabcbb";

    cout << "Longest substring length: "
         << longestSubstring(s);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
