class Solution {
    vector<vector<int>> getSums(const vector<int> &a) {
        vector<vector<int>> sums(a.size() + 1);
        
        for (int mask = 0; mask < (1 << a.size()); mask++) {
            int ones = 0, sum = 0;
            
            for (int bit = 0; bit < a.size(); bit++) {
                if (mask & (1 << bit)) {
                    ones++;
                    sum += a[bit];
                } else {
                    sum -= a[bit];
                }
            }
            
            sums[ones].push_back(sum);
        }
        
        for (vector<int> &s : sums)
            sort(s.begin(), s.end());
        return sums;
    }
    
public:
    int minimumDifference(vector<int> &a) {
        vector<vector<int>> leftSums = getSums({ a.begin(), a.begin() + a.size() / 2 });
        vector<vector<int>> rightSums = getSums({ a.begin() + a.size() / 2, a.end() });
        
        int res = 1e9;
        for (int leftOnes = 0, rightOnes = a.size() / 2; leftOnes <= a.size() / 2; leftOnes++, rightOnes--) {
            for (int l = 0, r = (int)rightSums[rightOnes].size() - 1; l < leftSums[leftOnes].size() && r >= 0; l++) {
                while (r >= 0 && leftSums[leftOnes][l] + rightSums[rightOnes][r] >= 0) {
                    res = min(res, leftSums[leftOnes][l] + rightSums[rightOnes][r]);
                    r--;
                }
            }
        }
        return res;
    }
};