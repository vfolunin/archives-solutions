class Solution {
public:
    int countDigitOne(int n) {
        vector<long long> powerOfTen(10);
        powerOfTen[0] = 1;
        for (int i = 1; i < powerOfTen.size(); i++)
            powerOfTen[i] = powerOfTen[i - 1] * 10;
        
        vector<vector<long long>> oneCount(10, vector<long long>(2));
        oneCount[1][0] = oneCount[1][1] = 1;
        for (int len = 2; len < oneCount.size(); len++) {
            oneCount[len][0] = 10 * oneCount[len - 1][0] + powerOfTen[len - 1];
            oneCount[len][1] = 9 * oneCount[len - 1][0] + powerOfTen[len - 1];
        }
        
        string s = to_string(n);
        long long res = 0;
        
        for (int len = 1; len < s.size(); len++)
            res += oneCount[len][1];
        
        long long prefixOneCount = 0;
        for (int i = 0; i < s.size(); i++) {
            for (int digit = !i; digit < s[i] - '0'; digit++) {
                res += prefixOneCount * powerOfTen[s.size() - 1 - i];
                res += oneCount[s.size() - 1 - i][0];
                if (digit == 1)
                    res += powerOfTen[s.size() - 1 - i];
            }
            prefixOneCount += s[i] == '1';
        }
        res += prefixOneCount;
        
        return res;
    }
};