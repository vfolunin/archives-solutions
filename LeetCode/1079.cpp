class Solution {
    int factorial(int n) {
        static vector<int> memo(10);
        int &res = memo[n];
        if (res)
            return res;
        
        if (!n)
            return res = 1;
        
        return res = factorial(n - 1) * n;
    }
    
    int rec(vector<int> &count, int i, int size, int den) {
        if (i == count.size())
            return factorial(size) / den;
        
        int res = 0;
        for (int partSize = 0; partSize <= count[i]; partSize++)
            res += rec(count, i + 1, size + partSize, den * factorial(partSize));
        return res;
    }
    
public:
    int numTilePossibilities(string &s) {
        vector<int> count(26);
        for (char c : s)
            count[c - 'A']++;
        count.erase(remove(count.begin(), count.end(), 0), count.end());
        
        return rec(count, 0, 0, 1) - 1;
    }
};