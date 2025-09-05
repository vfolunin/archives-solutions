class Solution {
public:
    vector<int> sortByAbsoluteValue(vector<int> &a) {
        sort(a.begin(), a.end(), [](int lhs, int rhs) {
            return abs(lhs) < abs(rhs);
        });
        return a;
    }
};