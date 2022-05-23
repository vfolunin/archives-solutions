class Solution {
    vector<int> getCount(string &s) {
        vector<int> res(26);
        for (char c : s)
            res[c - 'a']++;
        return res;
    }
    
    bool canMake(const vector<int> &wordCount, vector<int> &letterCount) {
        for (int i = 0; i < wordCount.size(); i++)
            if (wordCount[i] > letterCount[i])
                return 0;
        return 1;
    }
    
public:
    int countCharacters(vector<string> &words, string letters) {
        vector<int> letterCount = getCount(letters);
        int res = 0;
        
        for (string &word : words)
            if (canMake(getCount(word), letterCount))
                res += word.size();
        
        return res;
    }
};