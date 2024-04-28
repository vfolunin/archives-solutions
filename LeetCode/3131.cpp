class Solution {
public:
    int addedInteger(vector<int> &a, vector<int> &b) {
        return *min_element(b.begin(), b.end()) - *min_element(a.begin(), a.end());
    }
};