class DetectSquares {
    map<pair<int, int>, int> points;
    
    int get(int x, int y) {
        pair<int, int> p = { x, y };
        return points.count(p) ? points[p] : 0;
    }
    
public:    
    void add(vector<int> point) {
        points[{ point[0], point[1] }]++;
    }
    
    int count(vector<int> point) {
        int ax = point[0], ay = point[1], res = 0;
        for (auto [p, count] : points) {
            auto [bx, by] = p;
            if (ax == bx && ay != by) {
                int size = abs(ay - by);
                res += count * get(ax - size, by) * get(bx - size, ay) +
                       count * get(ax + size, by) * get(bx + size, ay);
            } else if (ax != bx && ay == by) {
                int size = abs(ax - bx);
                res += count * get(bx, ay - size) * get(ax, by - size) +
                       count * get(bx, ay + size) * get(ax, by + size);
            }
        }
        return res / 2;
    }
};