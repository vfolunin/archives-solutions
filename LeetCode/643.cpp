class Solution {
public:
    double findMaxAverage(vector<int> &a, int k) {
        double sum = 0;
        for (int i = 0; i < k; i++)
            sum += a[i];
        
        double maxSum = sum;
        for (int i = k; i < a.size(); i++) {
            sum += a[i] - a[i - k];
            maxSum = max(maxSum, sum);
        }
        
        return maxSum / k;
    }
};