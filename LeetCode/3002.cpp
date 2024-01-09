class Solution {
public:
    int maximumSetSize(vector<int> &a, vector<int> &b) {
        unordered_set<int> aValues(a.begin(), a.end());
        unordered_set<int> bValues(b.begin(), b.end());

        unordered_set<int> aUnique, notUnique;
        for (int value : aValues) {
            if (!bValues.count(value))
                aUnique.insert(value);
            else
                notUnique.insert(value);
        }

        unordered_set<int> bUnique;
        for (int value : bValues) {
            if (!aValues.count(value))
                bUnique.insert(value);
            else
                notUnique.insert(value);
        }

        int res = 0;
        res += min(aUnique.size(), a.size() / 2);
        res += min(bUnique.size(), b.size() / 2);
        res += min(notUnique.size(), a.size() - res);
        return res;
    }
};