class Solution {
public:
    int alternateDigitSum(int n) {
        string s = to_string(n);
        int sum = 0;

        for (int i = 0; i < s.size(); i++)
            sum += (s[i] - '0') * (i % 2 ? -1 : 1);
            
        return sum;
    }
};