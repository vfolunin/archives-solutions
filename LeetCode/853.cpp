class Solution {
public:
    int carFleet(int maxCoord, vector<int> &coord, vector<int> &speed) {
        vector<int> index(coord.size());
        iota(index.begin(), index.end(), 0);
        sort(index.begin(), index.end(), [&](int a, int b) { return coord[a] > coord[b]; });
        
        int res = 0;
        double maxTime = -1;
        
        for (int i : index) {
            double time = (double)(maxCoord - coord[i]) / speed[i];
            if (maxTime < time) {
                maxTime = time;
                res++;
            }
        }

        return res;
    }
};