class Solution {
public:
    int maximumLength(vector<int> &a, int limit) {
        vector<vector<int>> maxLen(a.size(), vector<int>(limit + 1));
        for (int i = 0; i < a.size(); i++) {
            maxLen[i][0] = 1;
            for (int prevI = 0; prevI < i; prevI++) {
                for (int prevErrors = 0; prevErrors <= limit; prevErrors++) {
                    int errors = prevErrors + (a[prevI] != a[i]);
                    if (errors <= limit)
                        maxLen[i][errors] = max(maxLen[i][errors], maxLen[prevI][prevErrors] + 1);
                }
            }
        }

        int res = 0;
        for (int i = 0; i < a.size(); i++)
            for (int errors = 0; errors <= limit; errors++)
                res = max(res, maxLen[i][errors]);
        return res;
    }
};