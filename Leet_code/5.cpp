class Solution {
public:
    string longestPalindrome(string s) {
        string maxString = "";

        for (int i = 0; i < s.size(); i++) {
            int start = i;
            int end = i;

            while (start >= 0 && end < s.size() && s[start] == s[end]) {
                start--;
                end++;
            }

            start++;
            end--;

            if (end - start + 1 > maxString.size()) {
                maxString = s.substr(start, end - start + 1);
            }

            if (i < s.size() - 1 && s[i] == s[i + 1]) {
                int start = i;
                int end = i + 1;

                while (start >= 0 && end < s.size() && s[start] == s[end]) {
                    start--;
                    end++;
                }

                start++;
                end--;

                if (end - start + 1 > maxString.size()) {
                    maxString = s.substr(start, end - start + 1);
                }
            }
        }

        return maxString;
    }
};