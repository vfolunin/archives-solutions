class Solution {
public:
    vector<int> cheapestJump(vector<int> &a, int maxJump) {
        if (a.back() == -1)
            return {};

        vector<int> cost(a.size(), 1e9), next(a.size(), -1);
        cost.back() = a.back();

        for (int i = (int)a.size() - 2; i >= 0; i--) {
            if (a[i] == -1)
                continue;

            for (int jump = 1; jump <= maxJump && i + jump < a.size(); jump++) {
                if (cost[i] > a[i] + cost[i + jump]) {
                    cost[i] = a[i] + cost[i + jump];
                    next[i] = i + jump;
                }
            }
        }

        if (cost[0] == 1e9)
            return {};
        
        vector<int> path;
        for (int i = 0; i != -1; i = next[i])
            path.push_back(i + 1);
        return path;
    }
};