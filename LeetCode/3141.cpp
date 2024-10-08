class Solution {
    vector<int> bfs(vector<int> &starts, int bitCount) {
        vector<int> dist(1 << bitCount, 1e9);
        queue<int> q;

        for (int start : starts) {
            start = (1 << bitCount) - 1 - start;
            dist[start] = 0;
            q.push(start);
        }

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int bit = 0; bit < bitCount; bit++) {
                int to = v ^ (1 << bit);
                if (dist[to] > dist[v] + 1) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }

        return dist;
    }

public:
    vector<int> maxHammingDistances(vector<int> &a, int bitCount) {
        vector<int> dist = bfs(a, bitCount);

        vector<int> res(a.size());
        for (int i = 0; i < res.size(); i++)
            res[i] = bitCount - dist[a[i]];
        return res;
    }
};