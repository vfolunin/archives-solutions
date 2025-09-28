class Solution {
    int getOps(const string &a, const string &b) {
        vector<vector<int>> count(26, vector<int>(26));
        int ops = 0;

        for (int i = 0; i < a.size(); i++) {
            if (a[i] == b[i])
                continue;

            if (count[b[i] - 'a'][a[i] - 'a']) {
                count[b[i] - 'a'][a[i] - 'a']--;
            } else {
                count[a[i] - 'a'][b[i] - 'a']++;
                ops++;
            }
        }

        return ops;
    }

    int rec(string &a, string &b, int size, vector<int> &memo) {
        int &res = memo[size];
        if (res != 1e9)
            return res;
        
        if (!size)
            return res = 0;
        
        for (int prevSize = 0; prevSize < size; prevSize++) {
            string aPart = a.substr(prevSize, size - prevSize);
            string rPart = { aPart.rbegin(), aPart.rend() };
            string bPart = b.substr(prevSize, size - prevSize);

            res = min(res, rec(a, b, prevSize, memo) + min(getOps(aPart, bPart), 1 + getOps(rPart, bPart)));
        }
        return res;
    }

public:
    int minOperations(string &a, string &b) {
        vector<int> memo(a.size() + 1, 1e9);
        return rec(a, b, a.size(), memo);
    }
};