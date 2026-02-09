#include <bits/stdc++.h>
using namespace std;

// Find first non-repeating character in a string
char firstNonRepeating(string s) {
    unordered_map<char, int> freq;

    for (char c : s)
        freq[c]++;

    for (char c : s) {
        if (freq[c] == 1)
            return c;
    }
    return '_';
}

int main() {
    string s = "aabbccdeff";

    char result = firstNonRepeating(s);

    if (result != '_')
        cout << "First non-repeating character: " << result;
    else
        cout << "No unique character found";

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
