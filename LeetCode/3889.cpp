class Solution {
public:
    int mirrorFrequency(string &s) {
        unordered_map<char, int> count;
        for (char c : s)
            count[c]++;
        
        int res = 0;
        for (char l = 'a', r = 'z'; l < r; l++, r--)
            res += abs(count[l] - count[r]);
        for (char l = '0', r = '9'; l < r; l++, r--)
            res += abs(count[l] - count[r]);
        return res;
    }
};