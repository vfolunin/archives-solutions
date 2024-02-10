class Solution {
public:
    int numberOfPairs(vector<vector<int>> &points) {
        map<int, set<int>> pointMap;
        for (vector<int> &point : points)
            pointMap[point[1]].insert(point[0]);
        
        int res = 0;
        for (auto &[by, bxs] : pointMap) {
            for (int bx : bxs) {
                int axFrom = -2e9;
                if (auto it = bxs.find(bx); it != bxs.begin()) {
                    res++;
                    axFrom = *prev(it);
                }

                for (auto ayIt = pointMap.upper_bound(by); ayIt != pointMap.end(); ayIt++) {
                    auto &[ay, axs] = *ayIt;

                    auto axIt = axs.upper_bound(bx);
                    if (axIt == axs.begin())
                        continue;
                    axIt--;

                    if (axFrom < *axIt) {
                        res++;
                        axFrom = *axIt;
                    }
                }
            }
        }
        return res;
    }
};