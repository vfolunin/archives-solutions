class Solution {
public:
    string shiftingLetters(string &s, vector<int> &a) {
        long long sum = accumulate(a.begin(), a.end(), 0LL);
        
        for (int i = 0; i < s.size(); i++) {
            s[i] = (s[i] - 'a' + sum) % 26 + 'a';
            sum -= a[i];
        }
        
        return s;
    }
};