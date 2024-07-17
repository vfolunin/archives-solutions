class Solution {
public:
    long long minimumCost(int h, int w, vector<int> &yPrice, vector<int> &xPrice) {
        long long yPriceSum = accumulate(yPrice.begin(), yPrice.end(), 0LL);
        long long xPriceSum = accumulate(xPrice.begin(), xPrice.end(), 0LL);

        sort(yPrice.rbegin(), yPrice.rend());
        sort(xPrice.rbegin(), xPrice.rend());

        long long res = 0;
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