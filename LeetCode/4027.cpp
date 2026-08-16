class Solution {
    long long rec(int mask, int lastRequestIndex, int start, vector<vector<int>> &requests, vector<vector<long long>> &memo) {
        long long &res = memo[mask][lastRequestIndex];
        if (res != -1)
            return res;
        
        long long lastTime = requests[lastRequestIndex][0];
        long long lastFloor = requests[lastRequestIndex][1];
        if (!(mask & (mask - 1)))
            return res = max(lastTime, abs(start - lastFloor));
        
        res = 1e18;
        for (int prevRequestIndex = 0; prevRequestIndex < requests.size(); prevRequestIndex++) {
            if (prevRequestIndex == lastRequestIndex || !(mask & (1 << prevRequestIndex)))
                continue;
                
            long long prevTime = rec(mask ^ (1 << lastRequestIndex), prevRequestIndex, start, requests, memo) ;
            long long prevFloor = requests[prevRequestIndex][1];
            res = min(res, max(lastTime, prevTime + abs(prevFloor - lastFloor)));
        }
        return res;
    }

public:
    long long elevatorRequests(int floorCount, int start, vector<vector<int>> &requests) {
        vector<vector<long long>> memo(1 << requests.size(), vector<long long>(requests.size(), -1));
        long long res = 1e18;
        for (int lastRequestIndex = 0; lastRequestIndex < requests.size(); lastRequestIndex++)
            res = min(res, rec((1 << requests.size()) - 1, lastRequestIndex, start, requests, memo));
        return res;
    }
};