#include <bits/stdc++.h>
using namespace std;

// Check if string is palindrome considering only alphanumeric characters
bool isValidPalindrome(string s) {
    int left = 0, right = (int)s.length() - 1;

    while (left < right) {
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;

        if (tolower(s[left]) != tolower(s[right]))
            return false;

        left++;
        right--;
    }
    return true;
}

int main() {
    string s = "A man, a plan, a canal: Panama";

    if (isValidPalindrome(s))
        cout << "Valid Palindrome";
    else
        cout << "Not a Palindrome";

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
