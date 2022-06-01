class Solution {
public:
    int divisorSubstrings(int n, int k) {
        string s = to_string(n);
        
        int res = 0;
        for (int i = 0; i + k <= s.size(); i++) {
            int d = stoi(s.substr(i, k));
            res += d && n % d == 0;
        }
        
        return res;
    }
};