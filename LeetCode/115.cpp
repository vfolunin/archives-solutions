class Solution {
public:
    int numDistinct(string &a, string &b) {
        unordered_map<char, vector<int>> pos(26);
        for (int i = 0; i < b.size(); i++)
            pos[b[i]].push_back(i);
        
        vector<unsigned long long> ways(b.size() + 1);
        ways[0] = 1;
        
        for (char c : a) {
            vector<unsigned long long> nextWays = ways;
            for (int p : pos[c])
                nextWays[p + 1] += (p ? ways[p] : 1);
            ways.swap(nextWays);
        }
        
        return ways.back();
    }
};