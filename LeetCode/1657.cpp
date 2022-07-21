class Solution {
    vector<int> getCount(string &s) {
        vector<int> count(26);
        for (char c : s)
            count[c - 'a']++;
        return count;
    }
    
public:
    bool closeStrings(string &a, string &b) {
        vector<int> aCount = getCount(a);
        vector<int> bCount = getCount(b);
        
        for (int i = 0; i < aCount.size(); i++)
            if (!aCount[i] && bCount[i] || aCount[i] && !bCount[i])
                return 0;
        
        sort(aCount.begin(), aCount.end());
        sort(bCount.begin(), bCount.end());
        return aCount == bCount;
    }
};