class Solution {
public:
    int brightestPosition(vector<vector<int>> &lights) {
        map<int, int> delta;
        for (vector<int> &light : lights) {
            delta[light[0] - light[1]]++;
            delta[light[0] + light[1] + 1]--;
        }

        int sum = 0, resSum = 0, res;
        for (auto &[x, delta] : delta) {
            sum += delta;
            if (resSum < sum) {
                resSum = sum;
                res = x;
            }
        }
        return res;
    }
};