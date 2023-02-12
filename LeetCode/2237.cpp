class Solution {
public:
    int meetRequirement(int size, vector<vector<int>> &lights, vector<int> &need) {
        vector<int> delta(size + 1);
        for (vector<int> &light : lights) {
            delta[max(0, light[0] - light[1])]++;
            delta[min(size, light[0] + light[1] + 1)]--;
        }

        int sum = 0, res = 0;
        for (int i = 0; i < size; i++) {
            sum += delta[i];
            res += sum >= need[i];
        }
        return res;
    }
};