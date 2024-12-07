class Solution {
public:
    int minOperations(vector<int> &a, int value) {
        set<int> values(a.begin(), a.end());
        return *values.begin() >= value ? values.size() - (*values.begin() == value) : -1;
    }
};