class Solution {
public:
    vector<int> minSubsequence(vector<int> &a) {
        sort(a.rbegin(), a.rend());
        int sum = accumulate(a.begin(), a.end(), 0), partSum = 0;
        
        for (int i = 0; i < a.size(); i++) {
            partSum += a[i];
            if (partSum > sum - partSum)
                return { a.begin(), a.begin() + i + 1 };
        }
        
        return {};
    }
};