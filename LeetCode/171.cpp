class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long res = 0;
        for (char c : columnTitle)
            res = res * 26 + c - 'A' + 1;
        return res;
    }
};