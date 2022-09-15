class Solution {
public:
    bool xorGame(vector<int> &a) {
        int xorSum = 0;
        for (int value : a)
            xorSum ^= value;
        
        return !xorSum || a.size() % 2 == 0;
    }
};