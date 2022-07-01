class Solution {
public:
    bool canPartition(vector<int> &a) {
        int sum = 0;
        for (int value : a)
            sum += value;
        
        if (sum % 2)
            return 0;
        
        vector<int> can(sum / 2 + 1);
        can[0] = 1;
        
        for (int value : a)
            for (int sum = can.size() - 1; sum >= value; sum--)
                can[sum] |= can[sum - value];
        
        return can.back();
    }
};