class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> factorial(10);
        factorial[0] = 1;
        for (int i = 1; i < factorial.size(); i++)
            factorial[i] = factorial[i - 1] * i;
        
        int res = 1;
        for (int i = 1; i <= n; i++)
            res += 9 * factorial[9] / factorial[10 - i];
        return res;
    }
};