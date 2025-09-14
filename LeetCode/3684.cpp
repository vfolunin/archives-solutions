class Solution {
public:
    vector<int> maxKDistinct(vector<int> &a, int limit) {
        sort(a.rbegin(), a.rend());
        a.erase(unique(a.begin(), a.end()), a.end());
        if (limit < a.size())
            a.erase(a.begin() + limit, a.end());
        return a;
    }
};