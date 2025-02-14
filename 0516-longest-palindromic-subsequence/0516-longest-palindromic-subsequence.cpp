class Solution {
public:
    int longestPalindromeSubseq(string s) {
            string t = s;
            reverse(s.begin(), s.end());

            int n = t.size();
            int m = s.size();

            // Create two arrays to store the previous and current rows of DP values
            vector<int> prev(m + 1, 0), cur(m + 1, 0);

            // Base Case is covered as we have initialized the prev and cur to 0.

            for (int ind1 = 1; ind1 <= n; ind1++) {
                for (int ind2 = 1; ind2 <= m; ind2++) {
                    if (t[ind1 - 1] == s[ind2 - 1])
                        cur[ind2] = 1 + prev[ind2 - 1];
                    else
                        cur[ind2] = max(prev[ind2], cur[ind2 - 1]);
                }
                // Update the prev array with the current values
                prev = cur;
            }

            // The value at prev[m] contains the length of the LCS
            return prev[m];
    }
};