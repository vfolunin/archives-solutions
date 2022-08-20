class Solution {
public:
    int minRefuelStops(int target, int fuel, vector<vector<int>> &stations) {
        vector<long long> distance(stations.size() + 1);
        distance[0] = fuel;
        
        for (vector<int> &station : stations)
            for (int refills = stations.size() - 1; refills >= 0; refills--)
                if (station[0] <= distance[refills])
                    distance[refills + 1] = max(distance[refills + 1], distance[refills] + station[1]);
        
        for (int refills = 0; refills <= stations.size(); refills++)
            if (distance[refills] >= target)
                return refills;
        return -1;
    }
};