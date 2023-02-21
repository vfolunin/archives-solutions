class Solution {
public:
    string minimizeError(vector<string> &prices, int target) {
        int sum = 0;
        vector<int> a;

        for (string &price : prices) {
            sum += stoi(price.substr(0, price.size() - 4));
            if (int frac = stoi(price.substr(price.size() - 3)); frac)
                a.push_back(frac);
        }

        int need = target - sum;
        if (need < 0 || need > a.size())
            return "-1";

        int res;
        if (!need) {
            res = accumulate(a.begin(), a.end(), 0);
        } else {
            vector<vector<int>> cost(a.size(), vector<int>(need + 1, 1e9));
            
            cost[0][0] = a[0];
            cost[0][1] = 1000 - a[0];

            for (int i = 1; i < a.size(); i++) {
                cost[i][0] = a[i] + cost[i - 1][0];
                for (int j = 1; j <= need; j++)
                    cost[i][j] = min(cost[i - 1][j] + a[i], cost[i - 1][j - 1] + 1000 - a[i]);
            }

            res = cost[a.size() - 1][need];
        }

        stringstream ss;
        ss << res / 1000 << "." << setw(3) << setfill('0') << res % 1000;
        return ss.str();
    }
};