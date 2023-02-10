class Solution {
public:
    bool nimGame(vector<int> &a) {
        int res = 0;
        for (int value : a)
            res ^= value;
        return res;    
    }
};