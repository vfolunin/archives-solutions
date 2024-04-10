class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int> &a, int target) {
        sort(a.begin(), a.end());

        long long res = 0;
        for (int i = 0; i <= a.size() / 2; i++)
            res += max(a[i] - target, 0);
        for (int i = a.size() / 2; i < a.size(); i++)
            res += max(target - a[i], 0);
        
        return res;
    }
};