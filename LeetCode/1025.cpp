class Solution {
public:
    bool divisorGame(int n) {
        static vector<int> memo(1001, -1);
        int &res = memo[n];
        if (res != -1)
            return res;
        
        for (int d = 1; d * 2 <= n; d++)
            if (n % d == 0 && !divisorGame(n - d))
                return res = 1;
        
        return res = 0;
    }
};