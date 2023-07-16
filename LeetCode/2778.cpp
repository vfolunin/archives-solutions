class Solution {
public:
    int sumOfSquares(vector<int> &a) {
        int res = 0;
        for (int i = 0; i < a.size(); i++)
            if (a.size() % (i + 1) == 0)
                res += a[i] * a[i];
        return res;
    }
};