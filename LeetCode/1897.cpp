class Solution {
public:
    bool makeEqual(vector<string> &words) {
        vector<int> count(26);
        for (string &word : words)
            for (char c : word)
                count[c - 'a']++;
        
        for (int count : count)
            if (count % words.size())
                return 0;
        
        return 1;
    }
};