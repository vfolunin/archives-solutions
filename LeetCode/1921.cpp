class Solution {
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed) {
        vector<double> time(dist.size());
        for (int i = 0; i < time.size(); i++)
            time[i] = 1.0 * dist[i] / speed[i];
        sort(time.begin(), time.end());
        
        for (int i = 0; i < time.size(); i++)
            if (time[i] <= i)
                return i;
        
        return time.size();
    }
};