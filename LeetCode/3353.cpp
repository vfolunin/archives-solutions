class Solution {
public:
    int minOperations(vector<int> &a) {
        int res = 0;
        for (int i = 0; i + 1 < a.size(); i++)
            res += a[i] != a[i + 1];
        return res;
    }
};