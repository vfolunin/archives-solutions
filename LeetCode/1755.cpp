class Solution {
    void rec(const vector<int> &a, int i, int sum, vector<int> &sums) {
        if (i == a.size()) {
            sums.push_back(sum);
            return;
        }
        rec(a, i + 1, sum, sums);
        rec(a, i + 1, sum + a[i], sums);
    }
    
    vector<int> getSums(const vector<int> &a) {
        vector<int> sums;
        rec(a, 0, 0, sums);
        sort(sums.begin(), sums.end());
        sums.erase(unique(sums.begin(), sums.end()), sums.end());
        return sums;
    }
    
public:
    int minAbsDifference(vector<int> &a, int target) {
        vector<int> al = getSums({ a.begin(), a.begin() + a.size() / 2 });
        vector<int> ar = getSums({ a.begin() + a.size() / 2, a.end() });
        int res = 2e9;
        
        for (int l = 0, r = ar.size() - 1; l < al.size(); l++) {
            while (r >= 0 && al[l] + ar[r] > target) {
                res = min(res, abs(al[l] + ar[r] - target));
                r--;
            }
            if (r >= 0)
                res = min(res, abs(al[l] + ar[r] - target));
        }
        
        return res;
    }
};