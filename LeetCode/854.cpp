class Solution {
    int bfs(string &start, string &finish) {
        unordered_map<string, int> dist;
        queue<string> q;
        
        dist[start] = 0;
        q.push(start);
        
        while (!q.empty()) {
            string s = q.front();
            q.pop();
            
            if (s == finish)
                return dist[s];
            int d = dist[s];
            
            int i = 0;
            while (s[i] == finish[i])
                i++;
            
            for (int j = i + 1; j < s.size(); j++) {
                if (finish[i] == s[j]) {
                    swap(s[i], s[j]);
                    if (!dist.count(s)) {
                        dist[s] = d + 1;
                        q.push(s);
                    }
                    swap(s[i], s[j]);
                }
            }
        }
        
        return -1;
    }
    
public:
    int kSimilarity(string &a, string &b) {
        return bfs(a, b);
    }
};