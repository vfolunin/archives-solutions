class Solution {
    int maxDigit(int n) {
        int res = 0;
        while (n) {
            res = max(res, n % 10);
            n /= 10;
        }
        return res;
    }
    
public:
    int maxSum(vector<int> &a) {
        int res = -1;
        for (int i = 0; i < a.size(); i++)
            for (int j = i + 1; j < a.size(); j++)
                if (maxDigit(a[i]) == maxDigit(a[j]))
                    res = max(res, a[i] + a[j]);
        return res;
    }
};