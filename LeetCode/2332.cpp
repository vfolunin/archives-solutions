class Solution {
public:
    int latestTimeCatchTheBus(vector<int> &buses, vector<int> &passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        
        int res = 1;
        
        for (int bi = 0, pi = 0; bi < buses.size(); bi++) {
            int passengerCount = 0;
            while (pi < passengers.size() && passengers[pi] <= buses[bi] && passengerCount < capacity) {
                if (!pi || passengers[pi - 1] < passengers[pi] - 1)
                    res = passengers[pi] - 1;
                pi++;
                passengerCount++;
            }
            
            if (passengerCount < capacity && (!pi || passengers[pi - 1] != buses[bi]))
                res = buses[bi];
        }
        
        return res;
    }
};