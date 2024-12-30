class Solution {
public:
    int maxDistinctElements(vector<int> &a, int limit) {
        sort(a.begin(), a.end());
        a[0] -= limit;
        for (int i = 1; i < a.size(); i++)
            a[i] = min(max(a[i - 1] + 1, a[i] - limit), a[i] + limit);
        a.erase(unique(a.begin(), a.end()), a.end());
        return a.size();
    }
};