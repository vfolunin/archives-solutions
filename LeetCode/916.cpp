class Solution {
    vector<int> getCount(string &s) {
        vector<int> count(26);
        for (char c : s)
            count[c - 'a']++;
        return count;
    }
    
public:
    vector<string> wordSubsets(vector<string> &a, vector<string> &b) {
        vector<int> bCount(26);
        for (string &s : b) {
            vector<int> count = getCount(s);
            for (int i = 0; i < count.size(); i++)
                bCount[i] = max(bCount[i], count[i]);
        }
        
        vector<string> res;
        for (string &s : a) {
            vector<int> aCount = getCount(s);            
            bool ok = 1;
            for (int i = 0; ok && i < aCount.size(); i++)
                ok &= aCount[i] >= bCount[i];
            if (ok)
                res.push_back(s);
        }
        
        return res;
    }
};