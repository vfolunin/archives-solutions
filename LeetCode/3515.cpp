struct SegmentTree {
    int size;
    vector<long long> t, tAdd;

    void build(int v, int vl, int vr, const vector<int> &a) {
        if (vl == vr) {
            t[v] = a[vl];
            return;
        }
        int vm = vl + (vr - vl) / 2;
        build(2 * v + 1, vl, vm, a);
        build(2 * v + 2, vm + 1, vr, a);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }

    void push(int v, int vl, int vr) {
        if (tAdd[v]) {
            t[v] += (vr - vl + 1) * tAdd[v];
            if (vl < vr) {
                tAdd[2 * v + 1] += tAdd[v];
                tAdd[2 * v + 2] += tAdd[v];
            }
            tAdd[v] = 0;
        }
    }

    long long query(int v, int vl, int vr, int l, int r) {
        push(v, vl, vr);
        if (vr < l || r < vl)
            return 0;
        if (l <= vl && vr <= r)
            return t[v];
        int vm = vl + (vr - vl) / 2;
        long long ql = query(2 * v + 1, vl, vm, l, r);
        long long qr = query(2 * v + 2, vm + 1, vr, l, r);
        return ql + qr;
    }

    void modify(int v, int vl, int vr, int l, int r, int value) {
        push(v, vl, vr);
        if (vr < l || r < vl)
            return;
        if (l <= vl && vr <= r) {
            tAdd[v] += value;
            push(v, vl, vr);
            return;
        }
        int vm = vl + (vr - vl) / 2;
        modify(2 * v + 1, vl, vm, l, r, value);
        modify(2 * v + 2, vm + 1, vr, l, r, value);
        t[v] = t[2 * v + 1] + t[2 * v + 2];
    }

    SegmentTree(vector<int> &a) : size(a.size()), t(4 * size), tAdd(4 * size) {
        build(0, 0, size - 1, a);
    }

    long long getSum(int l, int r) {
        return query(0, 0, size - 1, l, r);
    }

    void addValue(int l, int r, int value) {
        modify(0, 0, size - 1, l, r, value);
    }
};

class Solution {
    void dfs(vector<vector<pair<int, int>>> &graph, int v, int parent, int weight,
             vector<int> &dist, vector<int> &a, vector<int> &l, vector<int> &r, int &timer) {
        dist[v] = (parent == -1 ? 0 : dist[parent] + weight);

        a.push_back(dist[v]);
        l[v] = timer++;

        for (auto &[to, weight] : graph[v])
            if (to != parent)
                dfs(graph, to, v, weight, dist, a, l, r, timer);

        a.push_back(dist[v]);
        r[v] = timer++;
    }

public:
    vector<int> treeQueries(int vertexCount, vector<vector<int>> &edges, vector<vector<int>> &queries) {
        vector<vector<pair<int, int>>> graph(vertexCount);
        for (vector<int> &edge : edges) {
            edge[0]--;
            edge[1]--;
            graph[edge[0]].push_back({ edge[1], edge[2] });
            graph[edge[1]].push_back({ edge[0], edge[2] });
        }

        vector<int> dist(vertexCount), a, l(vertexCount), r(vertexCount);
        int timer = 0;
        dfs(graph, 0, -1, 0, dist, a, l, r, timer);

        SegmentTree segmentTree(a);
        vector<int> res;
        for (vector<int> &query : queries) {
            if (query[0] == 1) {
                int a = query[1] - 1;
                int b = query[2] - 1;
                if (dist[a] > dist[b])
                    swap(a, b);

                int distA = segmentTree.getSum(l[a], l[a]);
                int distB = segmentTree.getSum(l[b], l[b]);
                segmentTree.addValue(l[b], r[b], distA + query[3] - distB);
            } else {
                int v = query[1] - 1;
                res.push_back(segmentTree.getSum(l[v], l[v]));
            }
        }
        return res;
    }
};