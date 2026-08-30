class Solution {
public:
    int countSpecialIntegers(vector<int> &a) {
        unordered_map<int, int> l, r, count;
        for (int i = 0; i < a.size(); i++) {
            if (!l.count(a[i]))
                l[a[i]] = i;
            r[a[i]] = i;
            count[a[i]]++;
        }

        int res = 0;
        for (auto &[value, count] : count)
            res += r[value] - l[value] + 1 == count;
        return res;
    }
};