class Solution {
    pair<int, int> rec(int i, int fuel0, int fuel1, int time0, int time1,
                       vector<int> &demand, vector<int> &fuel, 
                       map<tuple<int, int, int, int, int>, pair<int, int>> &memo) {
        auto key = tie(i, fuel0, fuel1, time0, time1);
        if (auto it = memo.find(key); it != memo.end())
            return it->second;

        pair<int, int> &res = memo[key];
        res = { 0, 0 };
        if (i == demand.size())
            return res;
        
        if (fuel0 >= demand[i]) {
            auto [count, time] = rec(i + 1, fuel0 - demand[i], fuel1, demand[i], max(time1 - time0, 0), demand, fuel, memo);
            count++;
            time = max(time, time0);
            if (res.first < count || res.first == count && res.second > time)
                res = { count, time };
        }
        if (fuel1 >= demand[i]) {
            auto [count, time] = rec(i + 1, fuel0, fuel1 - demand[i], max(time0 - time1, 0), demand[i], demand, fuel, memo);
            count++;
            time = max(time, time1);
            if (res.first < count || res.first == count && res.second > time)
                res = { count, time };
        }
        return res;
    }

public:
    int minMaxWaitingTime(vector<int> &demand, vector<int> &fuel) {
        map<tuple<int, int, int, int, int>, pair<int, int>> memo;
        auto [count, time] = rec(0, fuel[0], fuel[1], 0, 0, demand, fuel, memo);
        return count ? time : -1;
    }
};