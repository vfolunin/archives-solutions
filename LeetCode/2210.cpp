class Solution {
public:
    int countHillValley(vector<int> &a) {
        a.erase(unique(a.begin(), a.end()), a.end());
        int res = 0;
        for (int i = 1; i + 1 < a.size(); i++)
            res += a[i - 1] < a[i] && a[i] > a[i + 1] ||
                   a[i - 1] > a[i] && a[i] < a[i + 1];
        return res;
    }
};