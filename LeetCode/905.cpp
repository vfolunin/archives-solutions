class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &a) {
        sort(a.begin(), a.end(), [](int a, int b) { return a % 2 < b % 2; });
        return a;
    }
};