class Solution {
public:
    int distributeCandies(vector<int> &a) {
        return min(a.size() / 2, unordered_set(a.begin(), a.end()).size());
    }
};