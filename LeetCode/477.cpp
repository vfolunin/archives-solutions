class Solution {
public:
    int totalHammingDistance(vector<int> &a) {
        vector<int> ones(30);
        for (int value : a)
            for (int bit = 0; bit < ones.size(); bit++)
                if (value & (1 << bit))
                    ones[bit]++;
        
        int res = 0;
        for (int value : ones)
            res += value * (a.size() - value);
        return res;
    }
};