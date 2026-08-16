class Solution {
public:
    int nearestDrone(vector<vector<int>> &drones, vector<int> &target) {
        int resDist = 1e9, res = -1;
        for (int i = 0; i < drones.size(); i++) {
            int dist = abs(drones[i][0] - target[0]) + abs(drones[i][1] - target[1]);
            if (dist <= drones[i][2] && resDist > dist) {
                resDist = dist;
                res = i;
            }
        }
        return res;
    }
};