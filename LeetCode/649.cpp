class Solution {
public:
    string predictPartyVictory(string &s) {
        vector<deque<int>> pos(2);
        for (int i = 0; i < s.size(); i++)
            pos[s[i] == 'D'].push_back(i);
        
        while (!pos[0].empty() && !pos[1].empty()) {
            if (pos[0][0] < pos[1][0])
                pos[0].push_back(pos[0][0] + pos[0].size() + pos[1].size());
            else
                pos[1].push_back(pos[1][0] + pos[0].size() + pos[1].size());
            
            pos[0].pop_front();
            pos[1].pop_front();
        }
        
        return pos[1].empty() ? "Radiant" : "Dire";
    }
};