class Solution {
    vector<pair<char, int>> getBlocks(string &s) {
        vector<pair<char, int>> blocks;
        for (char c : s) {
            if (blocks.empty() || blocks.back().first != c)
                blocks.push_back({ c, 1 });
            else
                blocks.back().second++;
        }
        return blocks;
    }
    
public:
    bool isLongPressedName(string a, string b) {
        vector<pair<char, int>> aBlocks = getBlocks(a);
        vector<pair<char, int>> bBlocks = getBlocks(b);
        
        if (aBlocks.size() != bBlocks.size())
            return 0;
        
        for (int i = 0; i < aBlocks.size(); i++)
            if (aBlocks[i].first != bBlocks[i].first || aBlocks[i].second > bBlocks[i].second)
                return 0;
        
        return 1;
    }
};