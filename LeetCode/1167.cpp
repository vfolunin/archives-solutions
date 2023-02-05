class Solution {
public:
    int connectSticks(vector<int> &a) {
        multiset<int> values(a.begin(), a.end());
        int res = 0;

        while (values.size() > 1) {
            int x = *values.begin();
            values.erase(values.begin());
            int y = *values.begin();
            values.erase(values.begin());
            res += x + y;
            values.insert(x + y);
        }

        return res;
    }
};