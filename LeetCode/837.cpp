class Solution {    
public:
    double new21Game(int threshold, int stop, int limit) {
        vector<double> res(threshold + 1);
        fill(res.begin() + stop, res.end(), 1);
        
        double sum = min(threshold - stop + 1, limit);
        for (int l = stop - 1, r = l + limit; l >= 0; l--, r--) {
            res[l] = sum / limit;
            
            if (r < res.size())
                sum -= res[r];
            sum += res[l];
        }
        
        return res[0];
    }
};