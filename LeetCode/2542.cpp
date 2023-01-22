class Solution {
public:
    long long maxScore(vector<int> &a, vector<int> &b, int size) {
        vector<int> order(a.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int lhs, int rhs) {
            return b[lhs] > b[rhs];
        });
        
        multiset<long long> values;
        long long sum = 0, res = 0;

        for (int i : order) {
            sum += a[i];
            values.insert(a[i]);            
            
            if (values.size() > size) {
                sum -= *values.begin();
                values.erase(values.begin());
            }
            
            if (values.size() == size)
                res = max(res, sum * b[i]);
        }

        return res;
    }
};