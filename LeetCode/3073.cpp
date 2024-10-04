class Solution {
public:
    int maximumTripletValue(vector<int> &a) {
        multiset<int> l, r(a.begin(), a.end());
        int res = -1e9;

        for (int value : a) {
            r.erase(r.find(value));

            auto it = l.lower_bound(value);
            if (it != l.begin() && !r.empty() && value < *prev(r.end()))
                res = max(res, *prev(it) - value + *prev(r.end()));

            l.insert(value);
        }

        return res;
    }
};