class Solution {
public:
    int countSubarrays(vector<int> &a) {
        int res = 0;
        for (int i = 0; i + 2 < a.size(); i++)
            res += (a[i] + a[i + 2]) * 2 == a[i + 1];
        return res;
    }
};