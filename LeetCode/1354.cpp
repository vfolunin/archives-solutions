class Solution {
public:
    bool isPossible(vector<int> &a) {
        priority_queue<int> values;
        long long sum = 0;
        
        for (int value : a) {
            values.push(value);
            sum += value;
        }
        
        while (1) {
            int maxValue = values.top();
            values.pop();
            sum -= maxValue;
            
            if (maxValue == 1 || sum == 1)
                return 1;
            
            if (!sum || maxValue < sum || maxValue % sum == 0)
                return 0;
            
            int prevValue = maxValue % sum;            
            values.push(prevValue);
            sum += prevValue;
        }
        
        return 1;
    }
};