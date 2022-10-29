class Solution {
    vector<int> getDiff(string &s) {
        vector<int> diff(s.size() - 1);
        for (int i = 0; i < diff.size(); i++)
            diff[i] = s[i + 1] - s[i];
        return diff;
    }
    
public:
    string oddString(vector<string> &words) {
        map<vector<int>, vector<string>> groups;
        for (string &word : words)
            groups[getDiff(word)].push_back(word);
        
        if (groups.begin()->second.size() == 1)
            return groups.begin()->second[0];
        else
            return groups.rbegin()->second[0];
    }
};