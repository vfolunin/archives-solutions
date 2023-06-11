class Solution {
public:
    bool isFascinating(int n) {
        string s = to_string(n) + to_string(2 * n) + to_string(3 * n);

        vector<int> seen(10);
        for (char c : s) {
            if (c == '0' || seen[c - '0'])
                return 0;
            seen[c - '0'] = 1;
        }
        
        return 1;
    }
};