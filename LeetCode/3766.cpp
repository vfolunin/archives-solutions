class Solution {
    bool isBinPalindrome(int n) {
        string s;
        for (; n; n /= 2)
            s += n % 2 + '0';
        return s == string(s.rbegin(), s.rend());
    }

    vector<int> getBinPalindromes() {
        vector<int> res;
        for (int i = 0; i < 6000; i++)
            if (isBinPalindrome(i))
                res.push_back(i);
        return res;
    }

public:
    vector<int> minOperations(vector<int> &a) {
        static vector<int> binPalindromes = getBinPalindromes();

        vector<int> res(a.size());
        for (int i = 0; i < a.size(); i++) {
            int r = lower_bound(binPalindromes.begin(), binPalindromes.end(), a[i]) - binPalindromes.begin();
            int l = r - 1;
            
            res[i] = min(a[i] - binPalindromes[l], binPalindromes[r] - a[i]);
        }
        return res;
    }
};