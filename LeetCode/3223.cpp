class Solution {
public:
    int minimumLength(string &s) {
        vector<int> count(26);
        for (char c : s)
            count[c - 'a']++;
        
        int res = 0;
        for (int value : count)
            if (value)
                res += value % 2 ? 1 : 2;
        return res;
    }
};