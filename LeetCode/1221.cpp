class Solution {
public:
    int balancedStringSplit(string s) {
        int balance = 0, res = 0;
        for (char c : s) {
            if (c == 'L')
                balance++;
            else
                balance--;
            res += !balance;
        }
        return res;
    }
};