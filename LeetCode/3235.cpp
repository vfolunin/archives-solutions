struct Point {
    long long x, y;
    
    long long dist2To(const Point &that) const {
        long long dx = x - that.x;
        long long dy = y - that.y;
        return dx * dx + dy * dy;
    }
};

struct Segment {
    Point a, b;
    
    long long dist2To(const Point &that) const {
        if (a.x == b.x && that.y < a.y || a.y == b.y && that.x < a.x)
            return a.dist2To(that);
        if (a.x == b.x && that.y > b.y || a.y == b.y && that.x > b.x)
            return b.dist2To(that);
        long long dist = a.x == b.x ? a.x - that.x : a.y - that.y;
        return dist * dist;
    }
};

struct Circle {
    Point o;
    long long radius;

    Circle(vector<int> &args) : o(args[0], args[1]), radius(args[2]) {}

    bool intersectsWith(const Circle &that, int w, int h) const {
        long long dist = radius + that.radius;
        if (o.dist2To(that.o) > dist * dist)
            return 0;

        double midX = o.x + (double)(that.o.x - o.x) * radius / dist;
        double midY = o.y + (double)(that.o.y - o.y) * radius / dist;
        return 0 < midX && midX < w && 0 < midY && midY < h;
    }

    bool intersectsWith(const Segment &that) const {
        return that.dist2To(o) <= radius * radius;
    }
};

struct DSU {
    vector<int> id;

    DSU(int n) {
        for (int v = 0; v < n; v++)
            id.push_back(v);
    }

    int find(int i) {
        return id[i] == i ? i : id[i] = find(id[i]);
    }

    bool connected(int i, int j) {
        return find(i) == find(j);
    }

    void merge(int i, int j) {
        int ri = find(i), rj = find(j);
        if (ri == rj)
            return;
        if (rand() % 2)
            id[ri] = rj;
        else
            id[rj] = ri;
    }
};

class Solution {
public:
    bool canReachCorner(int w, int h, vector<vector<int>> &circleArgs) {
        vector<Circle> circles = { circleArgs.begin(), circleArgs.end() };
        const Segment UP = { { 0, h }, { w, h } };
        const Segment RIGHT = { { w, 0 }, { w, h } };
        const Segment DOWN = { { 0, 0 }, { w, 0 } };
        const Segment LEFT = { { 0, 0 }, { 0, h } };

        const int UP_V = circles.size();
        const int RIGHT_V = circles.size() + 1;
        const int DOWN_V = circles.size() + 2;
        const int LEFT_V = circles.size() + 3;

        DSU dsu(circles.size() + 4);
        
        for (int v = 0; v < circles.size(); v++) {
            for (int to = 0; to < circles.size(); to++) 
                if (circles[v].intersectsWith(circles[to], w, h))
                    dsu.merge(v, to);

            if (circles[v].intersectsWith(UP))
                dsu.merge(v, UP_V);
            if (circles[v].intersectsWith(RIGHT))
                dsu.merge(v, RIGHT_V);
            if (circles[v].intersectsWith(DOWN))
                dsu.merge(v, DOWN_V);
            if (circles[v].intersectsWith(LEFT))
                dsu.merge(v, LEFT_V);
        }

        return !dsu.connected(UP_V, RIGHT_V) &&
               !dsu.connected(UP_V, DOWN_V) &&
               !dsu.connected(RIGHT_V, LEFT_V) &&
               !dsu.connected(DOWN_V, LEFT_V);
    }
};