class Solution {
public:
    int minIncrements(int size, vector<int> &a) {
        vector<int> sum(size);
        for (int i = 0; i < size; i++)
            sum[i] = a[i] + (i ? sum[(i - 1) / 2] : 0);        
        int maxSum = *max_element(sum.begin(), sum.end());
        
        vector<int> delta(size);
        for (int i = size - 1; i >= size / 2; i--)
            delta[i] = maxSum - sum[i];
        
        for (int i = size / 2 - 1; i >= 0; i--) {
            delta[i] = min(delta[i * 2 + 1], delta[i * 2 + 2]);
            delta[i * 2 + 1] -= delta[i];
            delta[i * 2 + 2] -= delta[i];
        }
        
        return accumulate(delta.begin(), delta.end(), 0);
    }
};