class Solution {
    bool isSymmetric(int n) {
        string s = to_string(n);

        if (s.size() % 2)
            return 0;

        int balance = 0;
        for (int i = 0; i < s.size(); i++)
            balance += i < s.size() / 2 ? s[i] : -s[i];
        return !balance;
    }

public:
    int countSymmetricIntegers(int l, int r) {
        int res = 0;
        for (int i = l; i <= r; i++)
            res += isSymmetric(i);
        return res;
    }
};