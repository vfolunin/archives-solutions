class Solution {
public:
    vector<int> findCoins(vector<int> &ways) {
        ways.insert(ways.begin(), 1);
        vector<int> res;

        for (int i = 1; i < ways.size(); i++) {
            if (!ways[i])
                continue;

            if (ways[i] != 1)
                return {};
            
            res.push_back(i);

            for (int j = ways.size() - 1; j >= i; j--)
                ways[j] -= ways[j - i];
        }

        return res;
    }
};