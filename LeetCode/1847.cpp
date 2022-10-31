class Solution {
public:
    vector<int> closestRoom(vector<vector<int>> &rooms, vector<vector<int>> &queries) {        
        vector<int> order(queries.size());
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b) {
            return queries[a][1] > queries[b][1];
        });
        
        sort(rooms.begin(), rooms.end(), [](auto &a, auto &b) {
            return a[1] > b[1];
        });
        
        int ri = 0;
        set<int> roomIds;
        vector<int> res(queries.size(), -1);
        
        for (int qi : order) {
            while (ri < rooms.size() && rooms[ri][1] >= queries[qi][1]) {
                roomIds.insert(rooms[ri][0]);
                ri++;
            }
            
            if (roomIds.empty())
                continue;
            
            auto rIt = roomIds.lower_bound(queries[qi][0]);
            if (rIt == roomIds.begin()) {
                res[qi] = *rIt;
                continue;
            }
            
            auto lIt = prev(rIt);
            if (rIt == roomIds.end() || queries[qi][0] - *lIt <= *rIt - queries[qi][0])
                res[qi] = *lIt;
            else
                res[qi] = *rIt;
        }
        
        return res;
    }
};