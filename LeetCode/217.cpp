class Solution {
public:
    bool containsDuplicate(vector<int> &a) {
        unordered_set<int> seen;
        for (int value : a) {
            if (seen.count(value))
                return 1;
            seen.insert(value);
        }
        return 0;
    }
};