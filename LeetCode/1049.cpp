class Solution {
public:
    int lastStoneWeightII(vector<int> &a) {
        int sum = 0;
        for (int value : a)
            sum += value;
        
        vector<int> can(sum / 2 + 1);
        can[0] = 1;
        
        for (int value : a)
            for (int i = sum / 2; i >= value; i--)
                can[i] |= can[i - value];
        
        int res = sum / 2;
        while (!can[res])
            res--;
        
        return sum - 2 * res;
    }
};