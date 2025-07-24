// Last updated: 7/24/2025, 11:28:34 AM
class Solution {
public:
    bool checkPalindrome(int s, int e, string &str) {
        // Move start forward if it's not alphanumeric
        while (s < e && !isalnum(str[s])) s++;
        // Move end backward if it's not alphanumeric
        while (s < e && !isalnum(str[e])) e--;

        // Base case
        if (s >= e) return true;

        // Compare lowercased characters
        if (tolower(str[s]) != tolower(str[e])) {
            return false;
        }

        // Recursive call
        return checkPalindrome(s + 1, e - 1, str);
    }

    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        return checkPalindrome(start, end, s);
    }
};
