class Solution {
public:
    int minDeletions(string &s) {
        vector<int> counts(26);
        for (char c : s)
            counts[c - 'a']++;
        
        set<int> countSet;
        int res = 0;
        
        for (int count : counts) {            
            while (count && countSet.count(count)) {
                count--;
                res++;
            }
            
            if (count)
                countSet.insert(count);
        }
        
        return res;
    }
};