class Solution {
public:
    int minimumDistance(vector<vector<int>> &points) {
        multiset<int> subs, sums;
        for (vector<int> &point : points) {
            subs.insert(point[0] - point[1]);
            sums.insert(point[0] + point[1]);
        }

        int res = 2e9;
        for (vector<int> &point : points) {
            subs.erase(subs.find(point[0] - point[1]));
            sums.erase(sums.find(point[0] + point[1]));

            res = min(res, max(*prev(subs.end()) - *subs.begin(), *prev(sums.end()) - *sums.begin()));

            subs.insert(point[0] - point[1]);
            sums.insert(point[0] + point[1]);
        }
        return res;
    }
};