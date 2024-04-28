class Solution {
    bool check(vector<int> &a, int delta, unordered_map<int, int> &bCount) {
        unordered_map<int, int> aCount;
        for (int value : a)
            aCount[value + delta]++;
        
        unordered_set<int> values;
        for (auto &[value, count] : aCount)
            values.insert(value);
        for (auto &[value, count] : bCount)
            values.insert(value);
        
        int diff = 0;
        for (int value : values)
            diff += abs(aCount[value] - bCount[value]);
        return diff == 2;
    }

public:
    int minimumAddedInteger(vector<int> &a, vector<int> &b) {
        partial_sort(a.begin(), a.begin() + 3, a.end());
        partial_sort(b.begin(), b.begin() + 1, b.end());

        unordered_map<int, int> bCount;
        for (int value : b)
            bCount[value]++;
        
        int res = 1e9;
        for (int i = 0; i < 3; i++)
            if (check(a, b[0] - a[i], bCount))
                res = min(res, b[0] - a[i]);
        return res;
    }
};