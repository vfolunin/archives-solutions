class Solution {
public:
    int finalElement(vector<int> &a) {
        return max(a.front(), a.back());
    }
};