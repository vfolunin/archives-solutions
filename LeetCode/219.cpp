class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &a, int k) {
        unordered_map<int, int> seen;
        for (int i = 0; i < a.size(); i++) {
            if (seen.count(a[i]) && i - seen[a[i]] <= k)
                return 1;
            seen[a[i]] = i;
        }
        return 0;
    }
};