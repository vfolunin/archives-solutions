class Solution {
public:
    int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue) {
        int index = 0;
        if (ruleKey == "color")
            index = 1;
        if (ruleKey == "name")
            index = 2;
        
        int matchCount = 0;
        for (vector<string> &item : items)
            matchCount += item[index] == ruleValue;
        return matchCount;
    }    
};