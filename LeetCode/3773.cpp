class Solution {
public:
    int maxSameLengthRuns(string &s) {
        unordered_map<int, int> count;
        int maxCount = 0;

        int row = 1;
        for (int i = 1; i < s.size(); i++) {
            if (s[i - 1] == s[i]) {
                row++;
            } else {
                maxCount = max(maxCount, ++count[row]);
                row = 1;
            }
        }
        maxCount = max(maxCount, ++count[row]);

        return maxCount;
    }
};