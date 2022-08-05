class Solution {
    int bfs(const unordered_set<string> &deadends, string &target) {
        unordered_map<string, int> dist;
        queue<string> q;
        
        if (deadends.count("0000"))
            return -1;
        dist["0000"] = 0;
        q.push("0000");
        
        while (!q.empty()) {
            string v = q.front();
            q.pop();
            
            if (v == target)
                return dist[v];
            
            for (int i = 0; i < 4; i++) {
                for (int delta : { 1, 9 }) {
                    string to = v;
                    to[i] = (v[i] - '0' + delta) % 10 + '0';
                    if (!deadends.count(to) && !dist.count(to)) {
                        dist[to] = dist[v] + 1;
                        q.push(to);
                    }
                }
            }
        }
        
        return -1;
    }
    
public:
    int openLock(vector<string> &deadends, string &target) {
        return bfs({ deadends.begin(), deadends.end() }, target);
    }
};