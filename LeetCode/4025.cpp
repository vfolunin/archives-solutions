class Solution {
public:
    int minPenalty(int period, vector<int> &lights, vector<int> &arrivalTime) {
        int maxLight = *max_element(lights.begin(), lights.end());
        int res = 0;
        for (int time : arrivalTime)
            if (time % period >= maxLight)
                res = max(res, period - time % period);
        return res;
    }
};