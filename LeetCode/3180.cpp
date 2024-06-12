class Solution {
public:
    int maxTotalReward(vector<int> &a) {
        sort(a.begin(), a.end());

        vector<int> can(4001);
        can[0] = 1;

        for (int i = 0; i < a.size(); i++)
            for (int prevSum = a[i] - 1; prevSum >= 0; prevSum--)
                can[prevSum + a[i]] |= can[prevSum];
        
        return can.rend() - find(can.rbegin(), can.rend(), 1) - 1;
    }
};