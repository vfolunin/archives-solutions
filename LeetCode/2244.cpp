class Solution {
    int rec(int n) {
        static vector<int> memo(1e5 + 1);
        int &res = memo[n];
        if (res)
            return res;
        
        if (n <= 3)
            return res = 1;
        return res = 1 + min(rec(n - 2), rec(n - 3));
    }
    
public:
    int minimumRounds(vector<int> &a) {
        unordered_map<int, int> count;
        for (int value : a)
            count[value]++;
        
        int res = 0;
        for (auto &[_, count] : count) {
            if (count == 1)
                return -1;
            res += rec(count);
        }
        return res;
    }
};