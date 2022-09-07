class Solution {
public:
    int minNumberOperations(vector<int> &a) {
        int res = a[0];
        for (int i = 1; i < a.size(); i++)
            if (a[i - 1] < a[i])
                res += a[i] - a[i - 1];
        return res;
    }
};