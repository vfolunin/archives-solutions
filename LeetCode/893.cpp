class Solution {
    string canonize(const string &s) {
        vector<string> parts(2);
        
        for (int i = 0; i < s.size(); i++)
            parts[i % 2] += s[i];
        
        for (string &part : parts)
            sort(part.begin(), part.end());
        
        return parts[0] + "#" + parts[1];
    }
    
public:
    int numSpecialEquivGroups(vector<string> &words) {
        unordered_set<string> canonized;
        
        for (string &word : words)
            canonized.insert(canonize(word));
        
        return canonized.size();
    }
};