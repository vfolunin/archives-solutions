class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>> &orders) {
        vector<multiset<pair<int, int>>> backlogs(2);
        
        for (vector<int> &order : orders) {
            int price = order[0], amount = order[1], type = order[2];
            multiset<pair<int, int>> &backlog = backlogs[type ^ 1];

            while (!backlog.empty() && amount) {
                auto backlogIt = type ? prev(backlog.end()) : backlog.begin();
                auto [backlogPrice, backlogAmount] = *backlogIt;
                if (!type && backlogPrice > price || type && backlogPrice < price)
                    break;
                
                backlog.erase(backlogIt);
                int delta = min(amount, backlogAmount);
                amount -= delta;
                backlogAmount -= delta;
                
                if (backlogAmount)
                    backlog.insert({ backlogPrice, backlogAmount });
            }
            
            if (amount)
                backlogs[type].insert({ price, amount });
        }
        
        const long long MOD = 1e9 + 7;
        long long res = 0;
        
        for (multiset<pair<int, int>> &backlog : backlogs)
            for (auto &[price, amount] : backlog)
                res = (res + amount) % MOD;
        
        return res;
    }
};