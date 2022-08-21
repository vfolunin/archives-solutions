class Solution {
public:
    int halveArray(vector<int> &a) {
        double totalSum = accumulate(a.begin(), a.end(), 0.0), curSum = totalSum;
        priority_queue<double> values(a.begin(), a.end());
        
        for (int i = 0; 1; i++) {
            if (curSum * 2 <= totalSum)
                return i;
            
            double value = values.top();
            values.pop();
            
            curSum -= value;
            value /= 2;
            curSum += value;
            
            values.push(value);
        }
    }
};