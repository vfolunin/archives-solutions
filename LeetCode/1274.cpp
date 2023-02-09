class Solution {
public:
    int countShips(Sea &sea, const vector<int> &topRight, const vector<int> &bottomLeft) {
        int xl = bottomLeft[0], yl = bottomLeft[1];
        int xr = topRight[0], yr = topRight[1];

        if (xl > xr || yl > yr || !sea.hasShips(topRight, bottomLeft))
            return 0;

        if (xl == xr && yl == yr)
            return 1;
        
        int xm = xl + (xr - xl) / 2, ym = yl + (yr - yl) / 2;

        return (
            countShips(sea, { xm, ym }, { xl, yl }) +
            countShips(sea, { xr, ym }, { xm + 1, yl }) +
            countShips(sea, { xm, yr }, { xl, ym + 1 }) +
            countShips(sea, { xr, yr }, { xm + 1, ym + 1 })
        );
    }
};