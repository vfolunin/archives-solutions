class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>> &towers, int radius) {
        double bestSignal = 0;
        int bestX = 0, bestY = 0;
        
        for (int x = 0; x <= 50; x++) {
            for (int y = 0; y <= 50; y++) {
                double signal = 0;
                
                for (vector<int> &tower : towers) {
                    double dist = hypot(x - tower[0], y - tower[1]);
                    if (dist > radius)
                        continue;
                    signal += floor(tower[2] / (1 + dist));
                }
                
                if (bestSignal < signal) {
                    bestSignal = signal;
                    bestX = x;
                    bestY = y;
                }
            }
        }
        
        return { bestX, bestY };
    }
};