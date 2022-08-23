class Solution {
public:
    int addRungs(vector<int> &a, int dist) {
        int height = 0, res = 0;
        for (int value : a) {
            res += (value - height - 1) / dist;
            height = value;
        }
        return res;
    }
};