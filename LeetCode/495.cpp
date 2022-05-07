class Solution {
public:
    int findPoisonedDuration(vector<int> &times, int duration) {
        int prevTo = -1e9, res = 0;
        for (int from : times) {
            res += duration - max(prevTo - from, 0);
            prevTo = from + duration;
        }
        return res;
    }
};