class Solution {
public:
    int minOperationsMaxProfit(vector<int> &customers, int boardingCost, int runningCost) {
        int waiting = 0, curProfit = 0, maxProfit = 0, rotations = 0, res = -1;
        
        for (int i = 0; i < customers.size() || waiting; i++) {
            if (i < customers.size())
                waiting += customers[i];
            
            int delta = min(waiting, 4);
            waiting -= delta;
            curProfit += delta * boardingCost - runningCost;
            rotations++;

            if (maxProfit < curProfit) {
                maxProfit = curProfit;
                res = rotations;
            }
        }
        
        return res;
    }
};