class Solution {
public:
    long long getSum(vector<long long> &p, int l, int r) {
        return p[r] - (l ? p[l - 1] : 0);
    }

    vector<int> countTasks(vector<int> &a, vector<int> &queries) {
        vector<long long> p(a.begin(), a.end());
        partial_sum(p.begin(), p.end(), p.begin());
        
        vector<int> res(queries.size());
        int index = 0, leftTime = a[0];
        for (int i = 0; i < queries.size(); i++) {
            if (queries[i] < leftTime) {
                res[i] = a.size() - index;
                leftTime -= queries[i];
                continue;
            }
        
            int l = index, r = a.size();
            while (l + 1 < r) {
                int m = l + (r - l) / 2;
                if (leftTime + getSum(p, index + 1, m) <= queries[i])
                    l = m;
                else
                    r = m;
            }
                
            if (r == a.size()) {
                leftTime = a[0];
                index = 0;
            } else {
                leftTime = leftTime + getSum(p, index + 1, r) - queries[i];
                index = r;
                res[i] = a.size() - index;
            }
        }
        return res;
    }
};