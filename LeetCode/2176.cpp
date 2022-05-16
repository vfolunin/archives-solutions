class Solution {
public:
    int countPairs(vector<int> &a, int k) {
        int res = 0;
        for (int i = 0; i < a.size(); i++)
            for (int j = i + 1; j < a.size(); j++)
                res += a[i] == a[j] && i * j % k == 0;
        return res;
    }
};