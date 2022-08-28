class Solution {
    void makeTos(string &s, int i, unordered_map<string, string> &transitions, string &to, vector<string> &tos) {
        if (i + 1 == s.size()) {
            tos.push_back(to);
            return;
        }
        
        to.push_back(' ');
        for (char c : transitions[s.substr(i, 2)]) {
            to.back() = c;
            makeTos(s, i + 1, transitions, to, tos);
        }
        to.pop_back();
    }
    
    bool rec(string &s, unordered_map<string, string> &transitions, unordered_map<string, bool> &memo) {
        if (memo.count(s))
            return memo[s];
        bool &res = memo[s];
        
        if (s.size() == 1)
            return res = 1;
        
        string to;
        vector<string> tos;
        makeTos(s, 0, transitions, to, tos);
        
        for (string &to : tos)
            if (rec(to, transitions, memo))
                return res = 1;
        
        return res = 0;
    }
    
public:
    bool pyramidTransition(string &s, vector<string> &allowed) {
        unordered_map<string, string> transitions;
        for (string &triplet : allowed)
            transitions[triplet.substr(0, 2)] += triplet[2];
        
        unordered_map<string, bool> memo;
        
        return rec(s, transitions, memo);
    }
};