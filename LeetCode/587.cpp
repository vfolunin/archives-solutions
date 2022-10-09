struct Point {
    int x, y;

    Point(int x, int y) : x(x), y(y) {}

    Point(const Point &a, const Point &b) : x(b.x - a.x), y(b.y - a.y) {}

    bool operator == (const Point &that) const {
        return y == that.y && x == that.x;
    }
    
    bool operator < (const Point &that) const {
        return y < that.y || y == that.y && x < that.x;
    }

    int length2() const {
        return x * x + y * y;
    }

    int dotProduct(const Point &that) const {
        return x * that.x + y * that.y;
    }

    int crossProduct(const Point &that) const {
        return x * that.y - y * that.x;
    }
};

class Solution {
    bool less(Point &o, Point &a, Point &b) {
        Point oa(o, a), ob(o, b);
        int cross = oa.crossProduct(ob), dot = oa.dotProduct(ob);
        return cross > 0 || cross == 0 && dot > 0 && oa.length2() < ob.length2();
    }
    
    vector<Point> convexHullJarvis(vector<Point> &points) {
        auto it = min_element(points.begin(), points.end());
        vector<Point> hull = { *it };
        points.erase(it);
        
        while (!points.empty()) {
            auto it = min_element(points.begin(), points.end(), [&](Point &a, Point &b) {
                return less(hull.back(), a, b);
            });
            
            if (less(hull.back(), hull[0], *it))
                break;
            
            hull.push_back(*it);
            points.erase(it);
        }
        
        return hull;
    }
    
public:
    vector<vector<int>> outerTrees(vector<vector<int>> &trees) {
        vector<Point> points;
        for (vector<int> &tree : trees)
            points.push_back(Point(tree[0], tree[1]));
        
        vector<vector<int>> res;
        for (auto &[x, y] : convexHullJarvis(points))
            res.push_back({ x, y });
        return res;
    }
};