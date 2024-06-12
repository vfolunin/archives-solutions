class Solution {
public:
    int maximumLength(vector<int> &a, int limit) {
        vector<vector<int>> maxLen(a.size(), vector<int>(limit + 1));
        vector<int> resLen(limit + 1);
        unordered_map<int, int> lastIndex;

        for (int i = 0; i < a.size(); i++) {
            for (int errors = limit; errors >= 0; errors--) {
                maxLen[i][errors] = max(maxLen[i][errors], 1);

                if (lastIndex.count(a[i]))
                    maxLen[i][errors] = max(maxLen[i][errors], maxLen[lastIndex[a[i]]][errors] + 1);
                if (errors)
                    maxLen[i][errors] = max(maxLen[i][errors], resLen[errors - 1] + 1);

                resLen[errors] = max(resLen[errors], maxLen[i][errors]);
            }
            
            lastIndex[a[i]] = i;
        }

        return resLen.back();
    }
};