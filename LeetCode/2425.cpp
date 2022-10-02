class Solution {
public:
    int xorAllNums(vector<int> &a, vector<int> &b) {
        int res = 0;
        
        if (b.size() % 2)
            for (int value : a)
                res ^= value;
        
        if (a.size() % 2)
            for (int value : b)
                res ^= value;
        
        return res;
    }
};