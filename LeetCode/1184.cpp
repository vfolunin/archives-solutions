class Solution {
public:
    int distanceBetweenBusStops(vector<int> &p, int a, int b) {
        if (a == b)
            return 0;
        
        partial_sum(p.begin(), p.end(), p.begin());
        int total = p.back();
        
        if (a > b)
            swap(a, b);
        
        int res = p[b - 1] - (a ? p[a - 1] : 0);
        return min(res, total - res);
    }
};