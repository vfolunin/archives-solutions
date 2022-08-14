class Solution {
public:
    int minSideJumps(vector<int> &obstacles) {
        vector<vector<int>> jumps(obstacles.size(), vector<int>(3));
        jumps[0][0] = jumps[0][2] = 1;
        
        for (int i = 1; i < jumps.size(); i++) {
            for (int j = 0; j < 3; j++) {
                if (j == obstacles[i] - 1)
                    jumps[i][j] = 1e9;
                else
                    jumps[i][j] = jumps[i - 1][j];
            }
            
            for (int j = 0; j < 3; j++)
                if (j != obstacles[i] - 1)
                    for (int pj = 0; pj < 3; pj++)
                        if (pj != j)
                            jumps[i][j] = min(jumps[i][j], jumps[i][pj] + 1);
        }
        
        return *min_element(jumps.back().begin(), jumps.back().end());
    }
};