class Solution {
public:
    int findKOr(vector<int> &a, int k) {
        vector<int> count(31);
        for (int value : a)
            for (int bit = 0; bit < count.size(); bit++)
                count[bit] += (value & (1 << bit)) != 0;
        
        int res = 0;
        for (int bit = 0; bit < count.size(); bit++)
            res |= (count[bit] >= k) << bit;
        return res;
    }
};