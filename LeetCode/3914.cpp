class Solution {
public:
    long long minOperations(vector<int> &a) {
        long long res = 0;
        for (int i = 1; i < a.size(); i++)
            if (a[i - 1] > a[i])
                res += a[i - 1] - a[i];
        return res;
    }
};