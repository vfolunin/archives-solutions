class Solution {
    bool isSelfDividing(int n) {
        for (int d = n; d; d /= 10)
            if (d % 10 == 0 || n % (d % 10))
                return 0;
        return 1;
    }
    
public:
    vector<int> selfDividingNumbers(int l, int r) {
        vector<int> res;
        for (int i = l; i <= r; i++)
            if (isSelfDividing(i))
                res.push_back(i);
        return res;
    }
};