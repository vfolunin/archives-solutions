class Solution {
    bool isPalindromic(int value) {
        string s = to_string(value);
        for (int l = 0, r = s.size() - 1; l < r; l++, r--)
            if (s[l] != s[r])
                return 0;
        return 1;
    }

    long long getCost(vector<int> &a, int targetValue) {
        long long res = 0;
        for (int value : a)
            res += abs(value - targetValue);
        return res;
    }

public:
    long long minimumCost(vector<int> &a) {
        nth_element(a.begin(), a.begin() + a.size() / 2, a.end());
        
        int l = a[a.size() / 2];
        while (!isPalindromic(l))
            l--;
        
        int r = a[a.size() / 2];
        while (!isPalindromic(r))
            r++;
        
        return min(getCost(a, l), getCost(a, r));
    }
};