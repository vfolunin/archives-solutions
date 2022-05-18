class Solution {
    bool checkPart(string &s, int from, int len, int l, int r) {
        int value = stoi(s.substr(from, len));
        return l <= value && value <= r;
    }
    
public:
    int numDecodings(string s) {
        vector<int> ways(s.size() + 1);
        ways[0] = 1;
        
        for (int i = 1; i <= s.size(); i++) {
            if (checkPart(s, i - 1, 1, 1, 9))
                ways[i] += ways[i - 1];
            if (i >= 2 && checkPart(s, i - 2, 2, 10, 26))
                ways[i] += ways[i - 2];
        }
        
        return ways.back();
    }
};