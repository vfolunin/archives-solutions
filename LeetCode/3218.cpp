class Solution {
public:
    int minimumCost(int h, int w, vector<int> &yPrice, vector<int> &xPrice) {
        int yPriceSum = accumulate(yPrice.begin(), yPrice.end(), 0);
        int xPriceSum = accumulate(xPrice.begin(), xPrice.end(), 0);

        sort(yPrice.rbegin(), yPrice.rend());
        sort(xPrice.rbegin(), xPrice.rend());

        int res = 0;
        for (int yi = 0, xi = 0; yi < yPrice.size() || xi < xPrice.size(); ) {
            if (xi == xPrice.size() || yi < yPrice.size() && yPrice[yi] > xPrice[xi]) {
                res += yPrice[yi] + xPriceSum;
                yPriceSum -= yPrice[yi];
                yi++;
            } else {
                res += xPrice[xi] + yPriceSum;
                xPriceSum -= xPrice[xi];
                xi++;
            }
        }
        return res;
    }
};