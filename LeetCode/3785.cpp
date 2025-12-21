class Solution {
public:
    int minSwaps(vector<int> &a, vector<int> &bad) {
        unordered_map<int, int> count, badCount;
        int totalBadCount = 0, maxBadCount = 0;

        for (int i = 0; i < a.size(); i++) {
            count[a[i]]++;
            count[bad[i]]++;

            if (a[i] == bad[i]) {
                badCount[a[i]]++;
                totalBadCount++;
                maxBadCount = max(maxBadCount, badCount[a[i]]);
            }
        }

        for (auto &[value, count] : count)
            if (count > a.size())
                return -1;
        
        return max((totalBadCount + 1) / 2, maxBadCount);
    }
};