class Solution {
public:
    int minOperations(vector<int> &a) {
        int xorSum = 0;
        unordered_set<int> values;
        for (int value : a) {
            xorSum ^= value;
            values.insert(value);
        }

        if (!xorSum)
            return 0;
        if (values.size() == 1)
            return -1;
        if (values.contains(xorSum))
            return 1;
        
        vector<int> dist(1 << 11, 1e9);
        queue<int> q;

        dist[0] = 0;
        q.push(0);

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int value : values) {
                int to = v ^ value;
                if (dist[to] > dist[v] + 1) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }

        return dist[xorSum] < a.size() ? dist[xorSum] : -1;
    }
};