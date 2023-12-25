class Solution {
public:
    long long largestPerimeter(vector<int> &a) {
        sort(a.begin(), a.end());
        vector<long long> p(a.begin(), a.end());
        partial_sum(p.begin(), p.end(), p.begin());

        for (int i = a.size() - 1; i >= 2; i--)
            if (p[i - 1] > a[i])
                return p[i - 1] + a[i];
        return -1;
    }
};