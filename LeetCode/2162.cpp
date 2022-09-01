class Solution {
public:
    int minCostSetTime(int start, int moveCost, int pushCost, int targetSeconds) {
        int res = 1e9;
        
        for (int number = 0; number < 10000; number++) {
            vector<int> digits(4);
            for (int i = digits.size() - 1, n = number; i >= 0; i--, n /= 10)
                digits[i] = n % 10;
            
            int seconds = (digits[0] * 10 + digits[1]) * 60 + digits[2] * 10 + digits[3];
            if (seconds != targetSeconds)
                continue;
            
            int cost = 0, i = 0;
            while (i < 4 && !digits[i])
                i++;
            
            if (i < 4) {
                if (start != digits[i])
                    cost += moveCost;
                cost += pushCost;
                
                for (i++; i < 4; i++) {
                    if (digits[i - 1] != digits[i])
                        cost += moveCost;
                    cost += pushCost;
                }
            }
            
            res = min(res, cost);
        }
        
        return res;
    }
};