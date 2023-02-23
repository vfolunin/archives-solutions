class Solution {
    int rec(int size) {
        static vector<int> memo(61, -1);
        int &res = memo[size];
        if (res != -1)
            return res;
        
        if (size < 2)
            return res = 0;
        
        unordered_set<int> childRes;
        for (int l = 0, r = size - 2; l <= r; l++, r--)
            childRes.insert(rec(l) ^ rec(r));
        
        res = 0;
        while (childRes.count(res))
            res++;
        return res;
    }

public:
    bool canWin(string &s) {
        int res = 0, row = 0;

        for (char c : s) {
            if (c == '+') {
                row++;
            } else if (row) {
                res ^= rec(row);
                row = 0;
            }
        }
        if (row)
            res ^= rec(row);
            
        return res;
    }
};