class Solution {
public:
    vector<int> countRectangles(vector<vector<int>> &rectangles, vector<vector<int>> &points) {
        vector<vector<int>> widths(101);
        for (vector<int> &rectangle : rectangles)
            widths[rectangle[1]].push_back(rectangle[0]);
        
        for (vector<int> &row : widths)
            sort(row.begin(), row.end());
        
        vector<int> res(points.size());
        
        for (int i = 0; i < res.size(); i++)
            for (int y = points[i][1]; y <= 100; y++)
                res[i] += widths[y].end() - lower_bound(widths[y].begin(), widths[y].end(), points[i][0]);
        
        return res;
    }
};