class Solution {
public:
    int minimumCost(vector<int> &a) {
        sort(a.rbegin(), a.rend());
        int res = 0;
        for (int i = 0; i < a.size(); i++)
            if (i % 3 != 2)
                res += a[i];
        return res;
    }
};