class Solution {
    int decode(vector<int> &mapping, int x) {
        int res = 0, powerOfTen = 1;
        for ( ; x > 9; x /= 10, powerOfTen *= 10) 
            res += mapping[x % 10] * powerOfTen;
        res += mapping[x % 10] * powerOfTen;
        return res;
    }
    
public:
    vector<int> sortJumbled(vector<int> &mapping, vector<int> &a) {
        sort(a.begin(), a.end(), [&](int a, int b) {
            return decode(mapping, a) < decode(mapping, b);
        });
        return a;
    }
};