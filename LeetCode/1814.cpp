class Solution {
    int rev(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        return stoi(s);
    }
    
public:
    int countNicePairs(vector<int> &a) {
        unordered_map<int, int> count;
        for (int value : a)
            count[value - rev(value)]++;
        
        long long res = 0;
        for (auto &[value, count] : count)
            res += count * (count - 1LL) / 2;
        
        const long long MOD = 1e9 + 7;
        return res % MOD;
    }
};