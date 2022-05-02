class Solution {
public:
    vector<int> countPoints(vector<vector<int>> &points, vector<vector<int>> &queries) {
        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            int &cx = queries[i][0], &cy = queries[i][1], &r = queries[i][2];
            for (vector<int> &point : points) {
                int &x = point[0], &y = point[1];
                res[i] += (x - cx) * (x - cx) + (y - cy) * (y - cy) <= r * r;
            }
        }
        return res;
    }
};