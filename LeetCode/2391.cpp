class Solution {
public:
    int garbageCollection(vector<string> &garbage, vector<int> &travel) {
        int res = 0;
        
        for (char c : { 'G', 'M', 'P' }) {
            int time = 0, travelTime = 0;
            
            for (int i = 0; i < garbage.size(); i++) {
                if (int collectTime = count(garbage[i].begin(), garbage[i].end(), c); collectTime) {
                    time += travelTime + collectTime;
                    travelTime = 0;
                }
                
                if (i < travel.size())
                    travelTime += travel[i];
            }
            
            res += time;
        }
        
        return res;
    }
};