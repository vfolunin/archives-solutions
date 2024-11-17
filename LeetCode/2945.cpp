class Solution {
public:
    int findMaximumLength(vector<int> &a) {
        vector<long long> p(a.begin(), a.end());
        for (int i = 1; i < p.size(); i++)
            p[i] += p[i - 1];

        vector<int> maxPartCount(a.size()), prevPartEnd(a.size() + 1, -1);
        for (int l = -1, r = 0; r < a.size(); r++, l = max(l, prevPartEnd[r])) {
            maxPartCount[r] = (l != -1 ? maxPartCount[l] : 0) + 1;
            int index = lower_bound(p.begin(), p.end(), 2 * p[r] - (l != -1 ? p[l] : 0)) - p.begin();
            prevPartEnd[index] = r;
        }
        return maxPartCount.back();
    }
};