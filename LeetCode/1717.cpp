class Solution {
    int remove(string &s, const string &p) {
        int res = 0;
        string stack;
        
        for (char c : s) {
            stack.push_back(c);
            
            if (stack.size() >= p.size() && stack.substr(stack.size() - p.size()) == p) {
                res++;
                for (int i = 0; i < p.size(); i++)
                    stack.pop_back();
            }
        }
        
        s = stack;
        return res;
    }
    
public:
    int maximumGain(string &s, int ab, int ba) {
        vector<pair<string, int>> patterns = { { "ab", ab }, { "ba", ba } };
        if (patterns[0].second < patterns[1].second)
            swap(patterns[0], patterns[1]);
        
        int res = 0;
        for (auto &[pattern, cost] : patterns)
            res += remove(s, pattern) * cost;
        return res;
    }
};