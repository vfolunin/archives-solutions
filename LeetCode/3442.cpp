class Solution {
public:
    int maxDifference(string &s) {
        vector<int> count(26);
        for (char c : s)
            count[c - 'a']++;
        
        int res = -1e9;
        for (int a : count)
            if (a % 2)
                for (int b : count)
                    if (b && b % 2 == 0)
                        res = max(res, a - b);
        return res;
    }
};