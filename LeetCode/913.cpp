class Solution {
    int rec(vector<vector<int>> &graph, int mousePos, int catPos, int time, vector<vector<vector<int>>> &memo) {
        int &res = memo[mousePos][catPos][time];
        if (res != -1)
            return res;
        
        if (mousePos == 0)
            return res = 1;
        if (mousePos == catPos)
            return res = 2;
        if (time == graph.size() * 5)
            return res = 0;
        
        if (time % 2 == 0) {
            bool canMakeDraw = 0;
            for (int nextMousePos : graph[mousePos]) {
                int nextRes = rec(graph, nextMousePos, catPos, time + 1, memo);
                if (nextRes == 1)
                    return res = 1;
                else if (nextRes == 0)
                    canMakeDraw = 1;
            }
            return res = (canMakeDraw ? 0 : 2);
        } else {
            bool canMakeDraw = 0;
            for (int nextCatPos : graph[catPos]) {
                if (nextCatPos == 0)
                    continue;
                int nextRes = rec(graph, mousePos, nextCatPos, time + 1, memo);
                if (nextRes == 2)
                    return res = 2;
                else if (nextRes == 0)
                    canMakeDraw = 1;
            }
            return res = (canMakeDraw ? 0 : 1);
        }
    }
    
public:
    int catMouseGame(vector<vector<int>> &graph) {
        vector<vector<vector<int>>> memo(graph.size(), vector<vector<int>>(graph.size(), vector<int>(graph.size() * 5 + 1, -1)));
        return rec(graph, 1, 2, 0, memo);
    }
};