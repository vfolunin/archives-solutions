class Solution {
public:
    vector<int> maximumBobPoints(int arrowCount, vector<int> &a) {
        int maxPoints = 0;
        vector<int> res;
        
        for (int mask = 0; mask < (1 << 12); mask++) {
            int curPoints = 0, curArrowCount = 0;
            vector<int> arrows(12);
            
            for (int bit = 0; bit < arrows.size(); bit++) {
                if (mask & (1 << bit)) {
                    curPoints += bit;
                    curArrowCount += a[bit] + 1;
                    arrows[bit] = a[bit] + 1;
                }
            }
            
            if (curArrowCount <= arrowCount && maxPoints < curPoints) {
                arrows[0] += arrowCount - curArrowCount;
                maxPoints = curPoints;
                res = arrows;                
            }
        }
        
        return res;
    }
};