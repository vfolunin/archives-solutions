class Solution {
    bool canWin(string &s, string &hand) {
        vector<int> count(128);
        for (char c : s)
            count[c]++;
        
        for (char c : hand)
            if (count[c])
                count[c]++;
        
        for (char c : s)
            if (count[c] < 3)
                return 0;
        
        return 1;
    }
    
    string process(const string &s) {
        vector<pair<char, int>> stack;
        for (char c : s) {
            if (!stack.empty() && stack.back().first == c) {
                stack.back().second++;
            } else if (!stack.empty() && stack.back().second >= 3) {
                stack.pop_back();
                if (!stack.empty() && stack.back().first == c)
                    stack.back().second++;
                else
                    stack.push_back({ c, 1 });
            } else {
                stack.push_back({ c, 1 });
            }
        }
        if (!stack.empty() && stack.back().second >= 3)
            stack.pop_back();
        
        string res;
        for (auto [c, count] : stack)
            res += string(count, c);
        return res;            
    }
    
    vector<int> getPlaces(string &s, char c, bool last) {
        vector<int> places;        
        if (last) {
            for (int i = 0; i + 1 < s.size(); i++)
                if (c == s[i] && c == s[i + 1])
                    places.push_back(i);
        } else {
            for (int i = 0; i < s.size(); i++)
                if (c == s[i] || i + 1 < s.size() && s[i] == s[i + 1])
                    places.push_back(i);
        }        
        return places;
    }
    
    int rec(string &s, string &hand, map<pair<string, string>, int> &memo) {        
        if (memo.count({ s, hand }))
            return memo[{ s, hand }];
        int &res = memo[{ s, hand }];
        
        if (s.empty())
            return res = 0;
        if (hand.empty() || !canWin(s, hand))
            return res = 1e9;
        
        res = 1e9;
        
        for (int hi = 0; hi < hand.size(); hi++) {
            if (hi && hand[hi - 1] == hand[hi])
                continue;            
            string nextHand = hand.substr(0, hi) + hand.substr(hi + 1);
            
            for (int si : getPlaces(s, hand[hi], nextHand.empty())) {
                string nextS = process(s.substr(0, si + 1) + hand[hi] + s.substr(si + 1));                
                res = min(res, 1 + rec(nextS, nextHand, memo));
            }
        }
        
        return res;
    }
    
public:
    int findMinStep(string &s, string &hand) {
        sort(hand.begin(), hand.end());
        map<pair<string, string>, int> memo;
        int res = rec(s, hand, memo);
        return res < 1e9 ? res : -1;
    }
};