class Solution {
public:
    string bestHand(vector<int> &ranks, vector<char> &suits) {
        if (set<char>(suits.begin(), suits.end()).size() == 1)
            return "Flush";
        
        sort(ranks.begin(), ranks.end());
        
        for (int i = 0; i + 2 < ranks.size(); i++)
            if (ranks[i] == ranks[i + 2])
                return "Three of a Kind";
        
        for (int i = 0; i + 1 < ranks.size(); i++)
            if (ranks[i] == ranks[i + 1])
                return "Pair";
        
        return "High Card";
    }
};