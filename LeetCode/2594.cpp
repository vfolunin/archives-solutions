class Solution {
    bool can(vector<int> &ranks, int cars, long long time) {
        long long repairedCars = 0;
        for (int rank : ranks)
            repairedCars += sqrt(time / rank);
        return repairedCars >= cars;
    }
    
public:
    long long repairCars(vector<int> &ranks, int cars) {
        long long l = 0, r = 1;
        while (!can(ranks, cars, r))
            r *= 2;

        while (l + 1 < r) {
            long long m = l + (r - l) / 2;
            if (can(ranks, cars, m))
                r = m;
            else
                l = m;
        }
        
        return r;
    }
};