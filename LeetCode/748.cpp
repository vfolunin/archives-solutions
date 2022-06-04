class Solution {
    vector<int> getCount(string &s) {
        vector<int> count(26);
        for (char c : s)
            if (isalpha(c))
                count[tolower(c) - 'a']++;
        return count;
    }
    
    bool contains(vector<int> &aCount, const vector<int> &bCount) {
        for (int i = 0; i < aCount.size(); i++)
            if (aCount[i] > bCount[i])
                return 0;
        return 1;
    }
    
public:
    string shortestCompletingWord(string licensePlate, vector<string> &words) {
        vector<int> letterCount = getCount(licensePlate);
        
        string res;
        for (string &word : words)
            if (contains(letterCount, getCount(word)) && (res.empty() || res.size() > word.size()))
                res = word;
        
        return res;
    }
};