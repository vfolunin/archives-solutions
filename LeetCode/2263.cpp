class Solution {
    int cost(const vector<int> &a) {
        multiset<int> values = { a[0] };
        int res = 0;
        for (int i = 1; i < a.size(); i++) {
            if (*prev(values.end()) > a[i]) {
                res += *prev(values.end()) - a[i];
                values.erase(prev(values.end()));
                values.insert(a[i]);
            }
            values.insert(a[i]);
        }
        return res;
    }

public:
    int convertArray(vector<int> &a) {
        return min(cost(a), cost({ a.rbegin(), a.rend() }));
    }
};