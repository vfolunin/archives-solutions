class Solution {
public:
    vector<int> busiestServers(int serverCount, vector<int> &from, vector<int> &width) {
        set<int> available;
        for (int i = 0; i < serverCount; i++)
            available.insert(i);
        
        set<pair<int, int>> busy;
        
        vector<int> requestCount(serverCount), res;
        int maxRequestCount = 0;
        
        for (int i = 0; i < from.size(); i++) {
            while (!busy.empty() && busy.begin()->first <= from[i]) {
                available.insert(busy.begin()->second);
                busy.erase(busy.begin());
            }
            
            auto it = available.lower_bound(i % serverCount);
            if (it == available.end()) {
                it = available.begin();
                if (it == available.end())
                    continue;
            }
            
            busy.insert({ from[i] + width[i], *it });
            
            requestCount[*it]++;
            if (maxRequestCount < requestCount[*it]) {
                maxRequestCount = requestCount[*it];
                res = { *it };
            } else if (maxRequestCount == requestCount[*it]) {
                res.push_back(*it);
            }
            
            available.erase(it);
        }
        
        return res;
    }
};