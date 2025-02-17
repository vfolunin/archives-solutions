class Solution {
public:
    int sumOfGoodNumbers(vector<int> &a, int d) {
        int res = 0;
        for (int i = 0; i < a.size(); i++)
            if ((i - d < 0 || a[i - d] < a[i]) && (i + d >= a.size() || a[i] > a[i + d]))
                res += a[i];
        return res;
    }
};