class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>> &a) {
        map<int, vector<int>> defences;
        map<int, int> maxDefence;
        
        for (int i = 0; i < a.size(); i++) {
            defences[a[i][0]].push_back(a[i][1]);
            maxDefence[a[i][0]] = max(maxDefence[a[i][0]], a[i][1]);
        }
        
        int suffixMaxDefence = 0, res = 0;
        for (auto it = maxDefence.rbegin(); it != maxDefence.rend(); it++) {
            for (int defence : defences[it->first])
                res += defence < suffixMaxDefence;
            suffixMaxDefence = max(suffixMaxDefence, it->second);
        }
        
        return res;
    }
};