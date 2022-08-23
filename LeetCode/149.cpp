class Solution {
public:
    int maxPoints(vector<vector<int>> &points) {
        int res = 1;
        
        for (int ai = 0; ai < points.size(); ai++) {
            for (int bi = ai + 1; bi < points.size(); bi++) {
                int abx = points[bi][0] - points[ai][0];
                int aby = points[bi][1] - points[ai][1];
                int cur = 0;
                
                for (int i = 0; i < points.size(); i++) {
                    int apx = points[i][0] - points[ai][0];
                    int apy = points[i][1] - points[ai][1];
                    cur += apx * aby == apy * abx;
                }
                
                res = max(res, cur);
            }
        }
        
        return res;
    }
};