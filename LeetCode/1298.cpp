class Solution {
public:
    int maxCandies(vector<int> &isOpen, vector<int> &bonus, vector<vector<int>> &keys,
                   vector<vector<int>> &inner, vector<int> &start) {
        vector<int> haveBox(1001);
        vector<int> visited(1001);
        queue<int> q;
        
        for (int v : start) {
            haveBox[v] = 1;
            if (isOpen[v]) {
                visited[v] = 1;
                q.push(v);
            }
        }
        
        int res = 0;
        
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            
            res += bonus[v];
            
            for (int to : keys[v]) {
                isOpen[to] = 1;
                if (haveBox[to] && !visited[to]) {
                    visited[to] = 1;
                    q.push(to);
                }
            }
            
            for (int to : inner[v]) {
                haveBox[to] = 1;
                if (isOpen[to] && !visited[to]) {
                    visited[to] = 1;
                    q.push(to);
                }
            }
        }
        
        return res;
    }
};