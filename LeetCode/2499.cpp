class Solution {
public:
    long long minimumTotalCost(vector<int> &a, vector<int> &b) {
        unordered_map<int, int> eqCount;
        long long res = 0;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] == b[i]) {
                eqCount[a[i]]++;
                res += i;
            }
        }

        if (eqCount.empty())
            return 0;

        vector<pair<int, int>> eqCounts = { eqCount.begin(), eqCount.end() };
        sort(eqCounts.begin(), eqCounts.end(), [](auto &a, auto &b) {
            return a.second < b.second;
        });

        int smallerSum = 0;
        for (int i = 0; i + 1 < eqCounts.size(); i++)
            smallerSum += eqCounts[i].second;

        if (smallerSum >= eqCounts.back().second)
            return res;

        auto [value, need] = eqCounts.back();
        need -= smallerSum;

        for (int i = 0; i < a.size() && need; i++) {
            if (a[i] != b[i] && a[i] != value && b[i] != value) {
                res += i;
                need--;
            }
        }

        return need ? -1 : res;
    }
};