class Solution {
public:
    int longestSubsequence(vector<int> &a) {
        vector<vector<int>> size(301, vector<int>(301, -1));

        for (int value : a) {
            size[value][300] = max(size[value][300], 1);

            for (int prevValue = 1; prevValue <= 300; prevValue++) {
                int diff = abs(value - prevValue);
                if (size[prevValue][diff] != -1)
                    size[value][diff] = max(size[value][diff], size[prevValue][diff] + 1);
            }

            for (int diff = 299; diff >= 0; diff--)
                size[value][diff] = max(size[value][diff], size[value][diff + 1]);
        }

        int res = 0;
        for (int value = 1; value <= 300; value++)
            res = max(res, size[value][0]);
        return res;
    }
};