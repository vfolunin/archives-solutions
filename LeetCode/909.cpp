class Solution {
    pair<int, int> getCoords(int size, int n) {
        n--;
        int y = size - 1 - n / size;
        int x = n % size;
        if ((size - 1 - y) % 2)
            x = size - 1 - x;
        return { y, x };
    }
    
    int bfs(vector<vector<int>> &a) {
        vector<int> dist(a.size() * a.size() + 1, 1e9);
        dist[1] = 0;
        
        queue<int> q;
        q.push(1);
        
        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int roll = 1; roll <= 6 && v + roll <= a.size() * a.size(); roll++) {
                int to = v + roll;
                auto [ty, tx] = getCoords(a.size(), to);

                if (a[ty][tx] != -1)
                    to = a[ty][tx];

                if (dist[to] == 1e9) {
                    dist[to] = dist[v] + 1;
                    q.push(to);
                }
            }
        }
        
        return dist.back();
    }
    
public:
    int snakesAndLadders(vector<vector<int>> &a) {
        int res = bfs(a);
        return res != 1e9 ? res : -1;
    }
};