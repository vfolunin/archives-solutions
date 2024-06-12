class Solution {
public:
    int maxTotalReward(vector<int> &a) {
        sort(a.begin(), a.end());

        bitset<100001> mask, can;
        int maskValue = 0;
        can[0] = 1;

        for (int value : a) {
            for ( ; maskValue < value; maskValue++)
                mask[maskValue] = 1;
                
            can |= (can & mask) << value;
        }
        
        int res = can.size() - 1;
        while (!can[res])
            res--;
        return res;
    }
};