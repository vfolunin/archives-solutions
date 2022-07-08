class Solution {
    void rec(int x, int n, vector<int> &res) {
        if (x > n)
            return;
        res.push_back(x);
        for (int i = 0; i < 10; i++)
            rec(x * 10 + i, n, res);
    }
    
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int i = 1; i < 10; i++)
            rec(i, n, res);
        return res;
    }
};