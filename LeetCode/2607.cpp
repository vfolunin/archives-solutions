class Solution {
public:
    long long makeSubKSumEqual(vector<int> &a, int width) {
        int groupCount = gcd(a.size(), width);
        vector<vector<int>> groups(groupCount);        
        for (int i = 0; i < a.size(); i++)
            groups[i % groupCount].push_back(a[i]);
        
        long long res = 0;
        for (auto &group : groups) {
            sort(group.begin(), group.end());
            int median = group[group.size() / 2];
            for (int value : group)
                res += abs(value - median);
        }
        return res;
    }
};