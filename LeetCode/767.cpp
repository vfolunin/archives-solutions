class Solution {
public:
    string reorganizeString(string &s) {
        unordered_map<char, int> count;
        for (char c : s)
            count[c]++;
        
        vector<pair<char, int>> pairs = { count.begin(), count.end() };
        sort(pairs.begin(), pairs.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });
        
        if (pairs[0].second > (s.size() + 1) / 2)
            return "";
        
        string res(s.size(), ' ');
        
        int pi = 0;
        for (int i = 0; i < s.size(); i += 2) {
            while (!pairs[pi].second)
                pi++;
            res[i] = pairs[pi].first;
            pairs[pi].second--;
        }
        for (int i = 1; i < s.size(); i += 2) {
            while (!pairs[pi].second)
                pi++;
            res[i] = pairs[pi].first;
            pairs[pi].second--;
        }
        
        return res;
    }
};