class Solution {
public:
    double minAreaFreeRect(vector<vector<int>> &points) {
        int res = 1e9;
        
        for (int ai = 0; ai < points.size(); ai++) {
            int ax = points[ai][0], ay = points[ai][1];
            
            for (int bi = 0; bi < points.size(); bi++) {
                if (ai == bi)
                    continue;
                
                int bx = points[bi][0], by = points[bi][1];
                int abx = bx - ax, aby = by - ay;
                
                for (int ci = 0; ci < points.size(); ci++) {
                    if (ai == ci || bi == ci)
                        continue;

                    int cx = points[ci][0], cy = points[ci][1];
                    int acx = cx - ax, acy = cy - ay;
                    if (abx * acx + aby * acy)
                        continue;
                    
                    int dx = bx + acx, dy = by + acy;
                    
                    for (int di = 0; di < points.size(); di++) {
                        if (ai == di || bi == di || ci == di ||
                            points[di][0] != dx || points[di][1] != dy)
                            continue;
                        
                        res = min(res, abs(abx * acy - aby * acx));
                    }
                }
            }
        }
        
        return res != 1e9 ? res : 0;
    }
};