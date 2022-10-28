class Solution {
public:
    int cherryPickup(vector<vector<int>> &a) {
        int size = a.size();
        
        vector<vector<vector<int>>> cost(size, vector<vector<int>>(size, vector<int>(size, -1e9)));
        cost[0][0][0] = a[0][0];
        
        for (int ya = 0; ya < size; ya++) {
            for (int xa = 0; xa < size; xa++) {
                for (int xb = 0; xb < size && xb <= ya + xa; xb++) {
                    if (cost[ya][xa][xb] == -1e9)
                        continue;
                    
                    int yb = ya + xa - xb;
                    
                    static vector<int> dy = { 1, 0 };
                    static vector<int> dx = { 0, 1 };
                    
                    for (int da = 0; da < dy.size(); da++) {
                        int tya = ya + dy[da];
                        int txa = xa + dx[da];
                        
                        if (tya < 0 || tya >= size || txa < 0 || txa >= size || a[tya][txa] == -1)
                            continue;
                        
                        for (int db = 0; db < dy.size(); db++) {
                            int tyb = yb + dy[db];
                            int txb = xb + dx[db];

                            if (tyb < 0 || tyb >= size || txb < 0 || txb >= size || a[tyb][txb] == -1)
                                continue;
                            
                            cost[tya][txa][txb] = max(cost[tya][txa][txb],
                                                      cost[ya][xa][xb] + a[tya][txa] + a[tyb][txb] -
                                                      (a[tya][txa] && tya == tyb && txa == txb));
                        }
                    }
                }
            }
        }
        
        return max(cost[size - 1][size - 1][size - 1], 0);
    }
};