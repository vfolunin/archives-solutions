class Solution {
    vector<int> getCount(string &s) {
        vector<int> count(26);
        for (char c : s)
            count[c - 'a']++;
        return count;
    }
    
    void updateCount(vector<int> &countA, const vector<int> &countB) {
        for (int i = 0; i < countA.size(); i++)
            countA[i] = min(countA[i], countB[i]);
    }
    
public:
    vector<string> commonChars(vector<string> &words) {
        vector<int> count(26, 1e9);
        for (string &word : words)
            updateCount(count, getCount(word));
        
        vector<string> res;
        for (int i = 0; i < count.size(); i++)
            for (int j = 0; j < count[i]; j++)
                res.push_back(string(1, 'a' + i));
        return res;
    }
};