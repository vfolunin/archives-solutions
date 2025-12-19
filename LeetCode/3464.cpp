class Solution {
    bool can(long long side, vector<long long> &a, long long dist, int count) {
        for (int first = 0; first < a.size(); first++) {
            long long last = first;
            for (int i = 1; i < count && last < a.size(); i++)
                last = lower_bound(a.begin(), a.end(), a[last] + dist) - a.begin();

            if (last < a.size() && a[first] + 4 * side - a[last] >= dist)
                return 1;
        }

        return 0;
    }

public:
    int maxDistance(long long side, vector<vector<int>> &points, int count) {
        vector<long long> a;
        
        for (vector<int> &point : points) {
            int x = point[0], y = point[1];
            if (y == side)
                a.push_back(x);
            else if (x == side)
                a.push_back(side + side - y);
            else if (y == 0)
                a.push_back(side * 2 + side - x);
            else
                a.push_back(side * 3 + y);
        }

        for (int i = 0; i < points.size(); i++)
            a.push_back(side * 4 + a[i]);

        sort(a.begin(), a.end());

        long long l = 0, r = 1;
        while (can(side, a, r, count))
            r *= 2;
        
        while (l + 1 < r) {
            int m = l + (r - l) / 2;
            if (can(side, a, m, count))
                l = m;
            else
                r = m;
        }
        return l;
    }
};