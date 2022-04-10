class Solution {
public:
    void rotate(vector<int> &a, int k) {
        k %= a.size();
        reverse(a.begin(), a.end() - k);
        reverse(a.end() - k, a.end());
        reverse(a.begin(), a.end());
    }
};