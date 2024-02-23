class Solution {
public:
    int countPrefixSuffixPairs(vector<string> &a) {
        int res = 0;
        for (int i = 0; i < a.size(); i++)
            for (int j = i + 1; j < a.size(); j++)
                res += a[i].size() <= a[j].size() &&
                       a[j].substr(0, a[i].size()) == a[i] &&
                       a[j].substr(a[j].size() - a[i].size()) == a[i];
        return res;
    }
};