class Solution {
public:
    long long maxSum(vector<int> &a, int width, int limit) {
        long long res = -1e18;

        for (int l = 0, r = width - 1; r < a.size(); l++, r++) {
            multiset<int> in, out;
            for (int i = 0; i < a.size(); i++) {
                if (l <= i && i <= r)
                    in.insert(a[i]);
                else
                    out.insert(a[i]);
            }

            for (int i = 0; i < limit && !in.empty() && !out.empty() && *in.begin() < *prev(out.end()); i++) {
                in.insert(*prev(out.end()));
                in.erase(in.begin());
                out.erase(prev(out.end()));
            }

            res = max(res, accumulate(in.begin(), in.end(), 0LL));
        }

        return res;
    }
};