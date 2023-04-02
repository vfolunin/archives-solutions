class Solution {
    vector<int> bfs(int size, int start, int width, const unordered_set<int> &bannedSet) {
        vector<int> dist(size, -1), next(size);
        iota(next.begin(), next.end(), 2);
        queue<int> q;

        dist[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            int l1 = max(0, v - width + 1), r1 = l1 + width - 1;
            int l2 = min(v, size - width), r2 = l2 + width - 1;
            int to1 = r1 - (v - l1), to2 = r2 - (v - l2);

            for (int to = to1; to <= to2; ) {
                int nextTo = next[to];
                if (dist[to] == -1 && !bannedSet.count(to)) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
                next[to] = to2 + 2;
                to = nextTo;
            }
        }

        return dist;
    }
    
public:
    vector<int> minReverseOperations(int size, int start, vector<int> &banned, int width) {
        return bfs(size, start, width, { banned.begin(), banned.end() });
    }
};