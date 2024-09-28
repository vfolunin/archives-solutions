class Solution {
    int getLisSize(vector<int> &a) {
        vector<int> lisLast(a.size() + 1, 1e9);
        lisLast[0] = -1e9;
        
        for (int value : a)
            *lower_bound(lisLast.begin(), lisLast.end(), value) = value;

        int lisSize = a.size();
        while (lisLast[lisSize] == 1e9)
            lisSize--;
        return lisSize;
    }

public:
    int maxPathLength(vector<vector<int>> &points, int index) {
        vector<pair<int, int>> l, r;
        for (vector<int> &point : points) {
            if (point[0] < points[index][0] && point[1] < points[index][1])
                l.push_back({ point[0], point[1] });
            else if (point[0] > points[index][0] && point[1] > points[index][1])
                r.push_back({ point[0], point[1] });
        }

        sort(l.begin(), l.end(), [](auto &a, auto &b) {
            return a.first < b.first || a.first == b.first && a.second > b.second;
        });
        vector<int> ly;
        for (int i = 0; i < l.size(); i++)
            ly.push_back(l[i].second);

        sort(r.begin(), r.end(), [](auto &a, auto &b) {
            return a.first < b.first || a.first == b.first && a.second > b.second;
        });
        vector<int> ry;
        for (int i = 0; i < r.size(); i++)
            ry.push_back(r[i].second);
        
        return getLisSize(ly) + 1 + getLisSize(ry);
    }
};