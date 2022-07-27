class Solution {
    int getSmallestCount(string &s) {
        vector<int> count(26);
        for (char c : s)
            count[c - 'a']++;
        
        int i = 0;
        while (!count[i])
            i++;
        return count[i];
    }
    
public:
    vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words) {
        vector<int> counts(words.size());
        for (int i = 0; i < words.size(); i++)
            counts[i] = getSmallestCount(words[i]);
        sort(counts.begin(), counts.end());
        
        vector<int> res(queries.size());
        for (int i = 0; i < queries.size(); i++)
            res[i] = counts.end() - upper_bound(counts.begin(), counts.end(), getSmallestCount(queries[i]));
        return res;
    }
};