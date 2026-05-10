class Solution {
public:
    vector<int> concatWithReverse(vector<int> &a) {
        a.insert(a.end(), a.rbegin(), a.rend());
        return a;
    }
};