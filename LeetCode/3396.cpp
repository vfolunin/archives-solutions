class Solution {
public:
    int minimumOperations(vector<int> &a) {
        unordered_set<int> seen;
        for (int i = a.size() - 1; i >= 0; i--) {
            if (seen.count(a[i]))
                return (i + 3) / 3;
            seen.insert(a[i]);
        }
        return 0;
    }
};