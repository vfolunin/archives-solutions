class Solution {
public:
    int numOfSubarrays(vector<int> &a, int k, int threshold) {
        int sum = 0;
        for (int i = 0; i < k; i++)
            sum += a[i];
        
        int res = sum >= k * threshold;
        
        for (int i = k; i < a.size(); i++) {
            sum += a[i] - a[i - k];
            res += sum >= k * threshold;
        }
        
        return res;
    }
};