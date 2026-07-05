class Solution {
public:
    bool isMiddleElementUnique(vector<int> &a) {
        return count(a.begin(), a.end(), a[a.size() / 2]) == 1;
    }
};