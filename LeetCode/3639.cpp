class Solution {
public:
    int minTime(string &s, vector<int> &order, int threshold) {
        set<int> pos = { -1, (int)s.size() };
        long long count = 0;

        for (int i = 0; i < order.size(); i++) {
            auto it = pos.upper_bound(order[i]);
            long long l = *prev(it), r = *it;

            count += (order[i] - l) * (r - order[i]);
            if (count >= threshold)
                return i;
            
            pos.insert(order[i]);
        }

        return -1;
    }
};