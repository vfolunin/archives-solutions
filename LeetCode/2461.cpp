class Solution {
public:
    long long maximumSubarraySum(vector<int> &a, int windowWidth) {
        unordered_map<int, int> count;
        long long sum = 0;
        
        for (int i = 0; i < windowWidth; i++) {
            count[a[i]]++;
            sum += a[i];
        }
        
        long long res = 0;
        if (count.size() == windowWidth)
            res = max(res, sum);
        
        for (int i = windowWidth; i < a.size(); i++) {
            if (!--count[a[i - windowWidth]])
                count.erase(a[i - windowWidth]);
            sum -= a[i - windowWidth];
            
            count[a[i]]++;
            sum += a[i];
            
            if (count.size() == windowWidth)
                res = max(res, sum);
        }
        
        return res;
    }
};