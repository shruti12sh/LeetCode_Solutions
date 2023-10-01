class Solution {
public:
   string reverseWords(string s) {
        int start = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (s[i] == ' ' || i == n - 1) {
                int end = (i == n - 1) ? i : i - 1;

                while (start < end) {
                    swap(s[start], s[end]);
                    start++;
                    end--;
                }

                start = i + 1;
            }
        }

        return s;
    }
};