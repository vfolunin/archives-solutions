class Solution {
public:
    long long putMarbles(vector<int> &a, int k) {
        if (a.size() == 1)
            return 0;
        
        vector<long long> diffs;
        for (int i = 0; i + 1 < a.size(); i++)
            diffs.push_back(a[i] + a[i + 1]);
        
        sort(diffs.begin(), diffs.end());
        long long minScore = accumulate(diffs.begin(), diffs.begin() + k - 1, 0LL);
        long long maxScore = accumulate(diffs.rbegin(), diffs.rbegin() + k - 1, 0LL);
        return maxScore - minScore;
    }
};