class Solution {
public:
    long long maxDifference(vector<int> &a) {
        vector<long long> res(a.size());

        res[a.size() - 1] = a[a.size() - 1];
        if (a.size() > 1)
            res[a.size() - 2] = a[a.size() - 2] + a[a.size() - 1];

        for (int i = (int)a.size() - 3; i >= 0; i--)
            res[i] = max(
                a[i] + (a[i] % 3 ? res[i + 1] : -res[i + 1]),
                a[i] + a[i + 1] + ((a[i] + a[i + 1]) % 3 ? res[i + 2] : -res[i + 2])
            );
        
        return res[0];
    }
};