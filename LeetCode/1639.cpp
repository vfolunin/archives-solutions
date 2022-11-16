class Solution {
public:
    int numWays(vector<string> &words, string &s) {
        const long long MOD = 1e9 + 7;
        
        vector<vector<int>> count(words[0].size(), vector<int>(26));
        for (int i = 0; i < words[0].size(); i++)
            for (string &word : words)
                count[i][word[i] - 'a']++;

        vector<long long> ways(s.size() + 1);
        ways[0] = 1;
 
        for (int i = 0; i < words[0].size(); i++)
            for (int j = s.size(); j; j--)
                ways[j] = (ways[j] + ways[j - 1] * count[i][s[j - 1] - 'a']) % MOD;
        
        return ways[s.size()];
    }
};