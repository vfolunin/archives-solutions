class Solution {
public:
    int minimumSum(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        
        int res = 1e9;
        do {
            res = min(res, stoi(s.substr(0, 1)) + stoi(s.substr(1)));
            res = min(res, stoi(s.substr(0, 2)) + stoi(s.substr(2)));
            res = min(res, stoi(s.substr(0, 3)) + stoi(s.substr(3)));
        } while (next_permutation(s.begin(), s.end()));
        return res;
    }
};