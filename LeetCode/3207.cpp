class Solution {
public:
    long long maximumPoints(vector<int> &a, long long sum) {
        sort(a.begin(), a.end());
        
        if (sum >= a[0])
            for (int i = 1; i < a.size(); i++)
                sum += a[i];
        
        return sum / a[0];
    }
};